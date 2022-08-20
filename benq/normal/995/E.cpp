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

const ll INF = 1e18;
const int MX = 100001;

int u,v,MOD;
unordered_map<int,int> x[2];
queue<pi> q;

ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }

int sub(int x, int y) {
    return (x-y+MOD)%MOD;
}

int ad(int x, int y) {
    return (x+y)%MOD;
}

void cons(int z, int dis, int ind) {
    if (dis > 50) return;
    if (x[ind].count(z)) return;
    x[ind][z] = dis;
    q.push({dis,z});
}

void search(int ori, int ind) {
    while (sz(q)) q.pop();
    q.push({0,ori}); x[ind][ori] = 0;
    F0R(i,1<<19) {
        if (!sz(q)) break;
        pi t = q.front(); q.pop();
        cons(inv(sub(t.s,1)),t.f+2,ind);
        cons(inv(ad(t.s,1)),t.f+2,ind);
    }
    
    /*for (auto a: x[ind]) cout << a.f << " " << a.s << "\n";
    cout << "----\n";*/
}

vi get(int en, int u, int ind) {
    vi v;
    while (en != u) {
        v.pb(3);
        if (x[ind].count(sub(inv(en),1)) && x[ind][sub(inv(en),1)] < x[ind][en]) {
            en = sub(inv(en),1);
            v.pb(1);
        } else {
            // assert(x[ind].count(ad(in)));
            en = ad(inv(en),1);
            v.pb(2);
        }
    }
    reverse(all(v));
    return v;
}

void finish() {
    vi A, B;
    for (auto a: x[0]) A.pb(a.f);
    for (auto a: x[1]) B.pb(a.f);
    sort(all(A)); sort(all(B));
    int ind = 0;
    for (int i: A) {
        while (ind < sz(B) && i-B[ind] > 100) ind ++;
        if (ind < sz(B) && abs(i-B[ind]) <= 100) {
            //cout << i << " " << B[ind] << "\n";
            //exit(0);
            vi x = get(i,u,0);
            int t = u;
            //cout << sz(x) << "\n";
            for (int i: x) {
                //cout << i << " ";
                if (i == 1) t = ad(t,1);
                else if (i == 2) t = sub(t,1);
                else t = inv(t);
            }
            if (i < B[ind]) {
                F0R(z,B[ind]-i) x.pb(1);
            } else {
                F0R(z,i-B[ind]) x.pb(2);
            }
            // cout << "\n" << i << " " << u << " " << t << "\n";
            vi y = get(B[ind],v,1);
            for (int& z: y) if (z <= 2) z = 3-z;
            reverse(all(y));
            x.insert(x.end(),all(y));

            t = u;
            cout << sz(x) << "\n";
            for (int i: x) {
                cout << i << " ";
                if (i == 1) t = ad(t,1);
                else if (i == 2) t = sub(t,1);
                else t = inv(t);
            }
            // cout << "\n" << i << " " << v << " " << t << "\n";
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //u = 25, v = 315109;
    //MOD = 1000000009;

    cin >> u >> v >> MOD;
    search(u,0);
    search(v,1);
    finish();
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS