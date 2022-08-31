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

int n,m;
pi cur[50][50];
vector<array<int,4>> tri;

void prin() {
    F0R(i,n) {
        F0R(j,n) {
            if (cur[i][j].f != -1) cout << 'x';
            else cout << '.';
        }
        cout << "\n";
    }
}

void move(pi a, pi b) {
    assert(cur[a.f][a.s].f != -1);
    assert(cur[b.f][b.s].f == -1);
    assert(abs(a.f-b.f)+abs(a.s-b.s) == 1);
    swap(cur[a.f][a.s],cur[b.f][b.s]);
    tri.pb({a.f,a.s,b.f,b.s});
}

int getVal(pi x) {
    if (x.f != 0) return n*x.f+x.s; 
    return n-1-x.s;
}

void putOnRow() {
    int tmp = 0;
    F0R(j,n) if (cur[0][j].f != -1) {
        pi pos = {0,j};
        while (pos.s && cur[0][pos.s-1].f == -1) {
            move(pos,{pos.f,pos.s-1});
            pos.s --;
        }
        tmp ++;
    }
    FOR(i,1,n) F0Rd(j,n) if (cur[i][j].f != -1) {
        // cout << i << " " << j << "\n";
        pi pos = {i,j};
        while (pos.s < tmp) {
            move(pos,{pos.f,pos.s+1});
            pos.s ++;
        }
        while (pos.f > 0) {
            move(pos,{pos.f-1,pos.s});
            pos.f --;
        }
        while (pos.s > tmp) {
            move(pos,{pos.f,pos.s-1});
            pos.s --;
        }
        tmp ++;
    }
}

void swa(int x) {
    move({0,x},{1,x});
    move({0,x+1},{0,x});
    move({1,x},{1,x+1});
    move({1,x+1},{0,x+1});
}

void bubbleSort() {
    F0R(i,m) F0R(j,m-1) if (getVal(cur[0][j]) < getVal(cur[0][j+1])) swa(j);
}

void finish() {
    F0R(i,m) if (cur[0][i].f != 0) {
        pi st = {0,i}, en = cur[0][i];
        while (st.s > en.s) {
            move(st,{st.f,st.s-1});
            st = {st.f,st.s-1};
        }
        while (st.f < en.f) {
            move(st,{st.f+1,st.s});
            st = {st.f+1,st.s};
        }
        while (st.s < en.s) {
            move(st,{st.f,st.s+1});
            st = {st.f,st.s+1};
        }
    }
    F0R(j,n) if (cur[0][j].f != -1) {
        pi pos = {0,j};
        while (pos.s && cur[0][pos.s-1].f == -1) {
            move(pos,{pos.f,pos.s-1});
            pos.s --;
        }
    }
    F0Rd(j,n) if (cur[0][j].f != -1) {
        pi st = {0,j}, en = cur[0][j];
        while (st.s < en.s) {
            move(st,{st.f,st.s+1});
            st = {st.f,st.s+1};
        }
    }
}

vector<array<int,4>> solve(vpi x, vpi y) {
    tri.clear();
    F0R(i,n) F0R(j,n) cur[i][j] = {-1,-1};
    F0R(i,m) cur[x[i].f][x[i].s] = y[i];
    putOnRow();
    bubbleSort();
    finish();
    F0R(i,n) F0R(j,n) if (cur[i][j].f != -1) assert(cur[i][j] == mp(i,j));
    return tri;
}

vpi x,y;

void prin(vector<array<int,4>> b, int x, int y) {
    cout << sz(b) << "\n";
    for (auto& a: b) {
        if (x == 0) a[0] ++, a[2] ++;
        else a[0] = n-a[0], a[2] = n-a[2];
        
        if (y == 0) a[1] ++, a[3] ++;
        else a[1] = n-a[1], a[3] = n-a[3];
        cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    x.resize(m), y.resize(m);
    if (n == 1) {
        cout << 0;
        exit(0);
    }
    
    F0R(i,m) {
        cin >> x[i].f >> x[i].s;
        x[i].f --, x[i].s --;
    }
    F0R(i,m) {
        cin >> y[i].f >> y[i].s;
        y[i].f --, y[i].s --;
    }
    
    auto a = solve(x,y);
    F0R(i,m) x[i].f = n-1-x[i].f, y[i].f = n-1-y[i].f;
    auto b = solve(x,y);
    F0R(i,m) x[i].s = n-1-x[i].s, y[i].s = n-1-y[i].s;
    auto c = solve(x,y);
    F0R(i,m) x[i].f = n-1-x[i].f, y[i].f = n-1-y[i].f;
    auto d = solve(x,y);
    int mn = min(min(sz(a),sz(b)),min(sz(c),sz(d)));
    if (sz(a) == mn) prin(a,0,0);
    else if (sz(b) == mn) prin(b,1,0);
    else if (sz(c) == mn) prin(c,1,1);
    else if (sz(d) == mn) prin(d,0,1);
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/