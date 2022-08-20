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

int n,k,g[4][50];
vpi al, belong;
vector<array<int,3>> mov;

void tri(int x) {
    if (g[al[x].f][al[x].s] > 0 && g[al[x].f][al[x].s] == g[belong[x].f][belong[x].s]) {
        mov.pb({g[al[x].f][al[x].s],belong[x].f+1,belong[x].s+1});
        k --;
        g[al[x].f][al[x].s] = 0;
    }
}

void move(int emp) {
    int EMP = (emp+sz(al)-1)%sz(al);
    if (g[al[EMP].f][al[EMP].s]) {
        mov.pb({g[al[EMP].f][al[EMP].s],al[emp].f+1, al[emp].s+1});
        swap(g[al[EMP].f][al[EMP].s],g[al[emp].f][al[emp].s]);
        tri(emp);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    F0R(i,4) F0R(j,n) cin >> g[i][j];
    F0R(i,n) {
        al.pb({1,i});
        belong.pb({0,i});
    }
    F0Rd(i,n) {
        al.pb({2,i});
        belong.pb({3,i});
    }
    F0R(i,sz(al)) tri(i);
    int emp = -1;
    F0R(i,sz(al)) if (g[al[i].f][al[i].s] == 0) emp = i;
    if (emp == -1) {
        cout << -1;
        exit(0);
    }
    while (k) {
        move(emp);
        emp = (emp+sz(al)-1)%sz(al);
    }
    cout << sz(mov) << "\n";
    for (auto a: mov) cout << a[0] << " " << a[1] << " " << a[2] << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS