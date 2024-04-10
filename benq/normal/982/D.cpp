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
const int MX = 100001;

int n;
pi ans = {-MOD,-MOD};
map<int,int> oc;
set<pi> cur;
vpi v;

void ad(int a, int b) {
    oc[a] += b;
    if (oc[a] == 0) oc.erase(a);
}

void del(int x) {
    auto it = *prev(cur.ub({x,MOD}));
    ad(it.s-it.f,-1);
    cur.erase(it);
    if (it.f < x) {
        cur.insert({it.f,x-1});
        ad(x-1-it.f,1);
    }
    if (x < it.s) {
        cur.insert({x+1,it.s});
        ad(it.s-x-1,1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cur.insert({0,n-1});
    oc[n-1] ++;
    F0R(i,n) {
        int x; cin >> x;
        v.pb({x,i});
    }
    
    sort(all(v));
    ans = {1,-(v[n-1].f+1)};
    for (int i = n-1; i >= 0; ) {
        int I = i;
        while (i >= 0 && v[i].f == v[I].f) del(v[i--].s);
        //for (auto z: oc) cout << z.f << " " << z.s << "\n";
        //cout << "\n";
        if (i >= 0 && sz(oc) == 1) ans = max(ans,{oc.begin()->s,-(v[i].f+1)});
    }
    
    cout << -ans.s;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)