#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 1000005;

int n,m1,m2,t;
map<int,int> m;
pi besProg[MX][2];
int cum[2][MX];
vi trans;
vpi v, shots;

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m1 >> m2 >> t;
    F0R(i,m1) {
        int x; cin >> x;
        m[x] ++;
    }
    F0R(i,m2) {
        int x; cin >> x;
        m[x] += 2;
    }
    m[0] = m[n+1] = 0;
    for (auto a: m) v.pb(a);
    F0R(i,sz(v)) {
        if (i != 0) cum[0][i] = cum[0][i-1], cum[1][i] = cum[1][i-1];
        if (v[i].s&1) cum[0][i] ++;
        if (v[i].s&2) cum[1][i] ++;
    }
}

pi get(int i, int j, int af) {
    int lo = i, hi = sz(v)-1;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (cum[j][mid]-cum[j][i] <= af) lo = mid;
        else hi = mid-1;
    }
    return {lo,cum[j][lo]-cum[j][i]};
}

bool trShoot(int i, int j, pi x) {
    pi z = get(x.f,j,x.s/t);
    pi ret = {z.f,x.s-t*z.s};
    
    ret.s = min(ret.s,t);
    if (ret.f >= i+1 && ret >= besProg[i+1][j]) besProg[i+1][j] = max(besProg[i+1][j],ret);
    ret.s = min(ret.s+1,t);
    return ret == besProg[i+1][j];
}

bool tryContinue(int i, int j) {
    if (besProg[i][j].f == -MOD) return 0;
    pi x = besProg[i][j];
    x.s += v[i+1].f-v[i].f-1;
    return trShoot(i,j,x);
}

bool trySwitch(int i, int j) {
    if (besProg[i][j].f == -MOD) return 0;
    pi x = {i,besProg[i][j].s};
    if (cum[j][besProg[i][j].f]-cum[j][i] != 0) x.s = t;
    
    if (v[i].s&(1<<(j^1))) {
        if (v[i+1].f != v[i].f+1) {
            x.s = min(t,x.s+1);
            x.s += v[i+1].f-v[i].f-2;
            return trShoot(i,j^1,x);
        }
        return 0;
    } else {
        x.s += v[i+1].f-v[i].f-1;
        return trShoot(i,j^1,x);
    }
}

bool process(int x, int y, int swi) {
    if (swi) return trySwitch(x-1,y^1);
    return tryContinue(x-1,y);
}

vi change;

void backtrack(int x, int y) {
    // cout << "AAAAA " << x << " " << y << " " << besProg[x][y].f << "\n";
    // cout << "ZZ " << process(x,y,0) << " " << tryContinue(x-1,1) << " " << process(x,y,1) << "\n";
    // cout << "AH " << besProg[2][1].f << " " << besProg[2][1].s << " " << besProg[3][1].f << " " << besProg[3][1].s << "\n";
    if (x == 0) {
        if (y == 1) change.pb(x);
        return;
    }
    if (process(x,y,0)) backtrack(x-1,y);
    else if (process(x,y,1)) {
        change.pb(x-1);
        backtrack(x-1,y^1);
    }
}

array<int,3> upd(int lst, array<int,3> cur, int i) {
    int z = get(lst,cur[1],0).f;
    while (z < i) {
        pi tmp = get(z,cur[1],1);
        z = tmp.f;
        cur[0] += t-cur[2];
        // cout << "AH " << cur[0] << " " << z << "\n";
        shots.pb({cur[0],cur[1]+1});
        cur[2] = 0;
    }
    cur[2] = min(t,cur[2]+v[i].f-cur[0]);
    cur[0] = v[i].f;
    return cur;
}

void gen() {
    reverse(all(change));
    change.pb(sz(v)-1);
    array<int,3> cur = {0,0,0};
    
    int lst = 0;
    for (int i: change) {
        cur = upd(lst,cur,i);
        
        if (i != sz(v)-1) {
            // cout << "HI " << i << "\n";
            if (v[i].s&(1<<(cur[1]^1))) {
                trans.pb(v[i].f+1);
                cur[0] ++;
                cur[2] = min(cur[2]+1,t);
            } else {
                trans.pb(v[i].f);
            }
            
            cur[1] ^= 1;
            lst = i;
        }
    }
}

void finish() {
    // reverse(all(trans)),reverse(all(shots));
    cout << sz(trans) << "\n";
    for (int i: trans) cout << i << " ";
    cout << "\n";
    cout << sz(shots) << "\n";
    for (auto a: shots) cout << a.f << " " << a.s << "\n";
}

int main() {
    init();
    F0R(j,2) besProg[0][j] = {0,-1};
    
    F0R(i,sz(v)) {
        F0R(j,2) besProg[i+1][j] = {-MOD,-MOD};
        F0R(j,2) if (besProg[i][j].f != -MOD) {
            besProg[i][j].s = min(t,besProg[i][j].s+1);
            if (i != sz(v)-1) {
                tryContinue(i,j);
                trySwitch(i,j);
            }
            // if (tryContinue(i,j)) cout << "ZZ " << i << " " << j << " " << tryContinue(i,j) << " " << besProg[i+1][j].f << " " << besProg[i+1][j].s << "\n";
            // if (trySwitch(i,j)) cout << "ZZ " << i << " " << j << " " << trySwitch(i,j) << "\n";
        }
    }
    
    /*F0R(i,sz(v)) {
        cout << i << " " << besProg[i][0].f << " " << besProg[i][1].f << "\n";
    }*/
    
    if (besProg[sz(v)-1][0].f != -MOD) {
        cout << "Yes\n";
        backtrack(sz(v)-1,0);
    } else if (besProg[sz(v)-1][1].f != -MOD) {
        cout << "Yes\n";
        backtrack(sz(v)-1,1);
    } else {
        cout << "No";
        return 0;
    }
    gen();
    finish();
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)