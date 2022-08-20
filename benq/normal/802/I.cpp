#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
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
const int MX = 100001;

struct suffix_array {
    int N;
    vector<vi> P;
    vector<array<int,3>> L;
    vi idx;
    string str;
    
    void bucket_sort(vector<array<int,3>>& v, int ind) {
        int mn = MOD, mx = -MOD;
        for (auto a: v) mn = min(mn,a[ind]), mx = max(mx,a[ind]);
        vi tmp(mx-mn+1), st(mx-mn+1);
        F0R(i,sz(v)) tmp[L[i][ind]-mn] ++;
        FOR(i,1,mx-mn+1) st[i] = st[i-1]+tmp[i-1];
        
        vector<array<int,3>> V(sz(v));
        F0R(i,sz(v)) V[st[v[i][ind]-mn]++] = v[i];
        v = V;
    }
    
    suffix_array(string _str) {
        str = _str; N = sz(str);
        P.pb(vi(N)); L.resize(N);
        F0R(i,N) P[0][i] = str[i];
        
        for (int stp = 1, cnt = 1; cnt < N; stp ++, cnt *= 2) {
            P.pb(vi(N));
            F0R(i,N) L[i] = {P[stp-1][i],i+cnt < N ? P[stp-1][i+cnt] : -1,i};
            bucket_sort(L,1); bucket_sort(L,0);
            F0R(i,N) {
                if (i && mp(L[i][0],L[i][1]) == mp(L[i-1][0],L[i-1][1])) P[stp][L[i][2]] = P[stp][L[i-1][2]];
                else P[stp][L[i][2]] = i;
            }
        }
        
        idx.resize(N);
        F0R(i,sz(P.back())) idx[P.back()[i]] = i;
    }
    
    int lcp(int x, int y) {
        int res = 0;
        if (x == y) return N-x;
        for (int k = sz(P) - 1; k >= 0 && x < N && y < N; k--) {
            if (P[k][x] == P[k][y]) {
                x += 1 << k;
                y += 1 << k;
                res += 1 << k;
            }
        }
        return res;
    }
};

int N;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    F0R(i,N) {
        string t; cin >> t;
        suffix_array S(t);
        //for (int i: S.idx) cout << i << " ";
        //cout << "\n";
        ll ans = sz(t); ans = ans*(ans+1)/2;
        ll csum = 0;
        vpi cur;
        FOR(i,1,sz(S.idx)) {
            int len = S.lcp(S.idx[i], S.idx[i-1]), num = 1;
            while (sz(cur) && cur.back().f >= len) {
                csum -= (ll)cur.back().f*cur.back().s;
                num += cur.back().s;
                cur.pop_back();
            }
            cur.pb({len,num});  csum += (ll)len*num;
            ans += 2*csum;
        }
        cout << ans << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/