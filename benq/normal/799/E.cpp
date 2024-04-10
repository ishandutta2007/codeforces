#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200001;


int n,m,k,like[MX],c[MX];
vi al[4], revM;
vl cum[4];
map<int,int> M;
ll ans = INF;

pl operator+(pl a, pl b) {
    return {a.f+b.f,a.s+b.s};
}

pl operator-(pl a, pl b) {
    return {a.f-b.f,a.s-b.s};
}

struct Dat {
    typedef pl T;
    T bit[MX];
    
    Dat() { F0R(i,MX) bit[i] = {0,0}; }
    
    void upd(int k, T val) { // add val to index k
        for( ;k < MX; k += (k&-k)) bit[k] = bit[k]+val;
    }
    
    int sz = 0;
    int size() { return sz; }
    ll get(ll x) { 
        if (sz == 0) return 0;
        int cur = 0; 
        pl ans = {0,0};
        F0Rd(i,18) {
            int ne = cur^(1<<i);
            if (ne < MX && ans.s+bit[ne].s < x) {
                cur = ne;
                ans = ans+bit[ne];
            }
        }
        if (ans.f+(x-ans.s)*revM[cur+1] < 0) exit(4);
        if (cur+1 >= sz(revM)) exit(9);
        return ans.f+(x-ans.s)*revM[cur+1];
    }
    
    void ins(int x) {
        sz ++;
        upd(M[x],{x,1});
    }
};

Dat dat;

void red(vi& x, int y) {
    while (sz(x) > y) {
        dat.ins(x.back());
        x.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin >> n >> m >> k;
    F0R(i,n) {
        // c[i] = 1000000000;
        cin >> c[i];
        M[c[i]] = 0;
    }
    revM.pb(0);
    for (auto& z: M) {
        z.s = sz(revM);
        revM.pb(z.f);
    }
    int a; cin >> a;
    F0R(i,a) {
        int x; cin >> x;
        like[x-1] ^= 1;
    }
    int b; cin >> b;
    F0R(i,b) {
        int x; cin >> x;
        like[x-1] ^= 2;
    }
    // F0R(i,n) like[i] = 3;
    F0R(i,n) {
        al[like[i]].pb(c[i]);
        // cout << like[i] << "\n";
    }
    F0R(i,4) sort(all(al[i]));
    FOR(k,1,4) {
        cum[k].resize(sz(al[k])+1); 
        F0R(i,sz(cum[k])-1) {
            cum[k][i+1] = cum[k][i]+al[k][i];
            if (cum[k][i+1] < 0) exit(5);
        }
    }
    for (auto a: al[0]) dat.ins(a);
    F0Rd(i,n+1) {
        red(al[1],i);
        red(al[2],i);
        if (i < sz(cum[1]) && i < sz(cum[2]) 
           && max(k-i,0) < sz(cum[3]) && m-i-i-max(k-i,0) <= dat.size() && m-i-i-max(k-i,0) >= 0) {
               ans = min(ans,cum[1][i]+cum[2][i]+cum[3][max(k-i,0)]+dat.get(m-i-i-max(k-i,0)));
               if (ans < 0) {
                   cout << "HI " << cum[1][i] << " " << cum[2][i] << " " << cum[3][k-i] << " " << dat.get(m-k-i) << "\n";
               }
            }
    }
    FOR(i,k+1,n+1) {
        if (i < sz(cum[3]) && m-i <= dat.size() && m-i >= 0) {
            ans = min(ans,cum[3][i]+dat.get(m-i));
            if (ans < 0) {
                cout << "HI " << cum[3][i] << " " << dat.get(m-i);
                exit(0);
            }
        }
    }
    if (ans == INF) cout << -1;
    else cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)