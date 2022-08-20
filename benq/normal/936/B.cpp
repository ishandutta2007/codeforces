
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
const int MX = 100001;

int n,m,s,sh[2][MX];
pi pre[2][MX]; // shortest distance
vi adj[MX];

void testwin() {
    FOR(i,1,n+1) if (sz(adj[i]) == 0 && sh[1][i] != MOD) {
        cout << "Win\n";
        vi res;
        pi cur = {1,i};
        while (cur != mp(0,s)) {
            res.pb(cur.s);
            cur = pre[cur.f][cur.s];
        }
        res.pb(s);
        reverse(all(res));
        for (int i: res) cout << i << " ";
        exit(0);
    }
}

bool visit[MX], insta[MX];

void dfs(int cur) {
    if (visit[cur]) return;
    
    visit[cur] = insta[cur] = 1;
    for (int i: adj[cur]) {
        if (insta[i]) {
            cout << "Draw";
            exit(0);
        }
        dfs(i);
    }
    
    insta[cur] = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(i,1,n+1) {
        sh[0][i] = sh[1][i] = MOD;
        int c; cin >> c;
        F0R(j,c) {
            int x; cin >> x;
            adj[i].pb(x);
        }
    }
    cin >> s;
    sh[0][s] = 0;
    queue<pi> q; q.push({0,s});
    while (sz(q)) {
        auto a = q.front(); q.pop();
        for (int b: adj[a.s]) if (sh[a.f^1][b] == MOD) {
            sh[a.f^1][b] = sh[a.f][a.s]+1;
            pre[a.f^1][b] = a;
            q.push({a.f^1,b});
        }
    }
    testwin();
    dfs(s);
    cout << "Lose";
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)