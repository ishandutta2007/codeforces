#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

#define vector deque

int n;
vector <int> adj[MAXN];
vector <int> c;

void dfs(int node, int prev, int x) {
    c[node] = x;
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs(next, node, !x);
    }
}

vector <int> find(int a) {
    vector <int> ans;
    vector <int> b;
    while(a) {
        b.push_back(a % 2);
        a /= 2;
    }
    forn(i, 0, b.size()) {
        if(b[i] == 1) {
            forn(j, 1<<i, 1<<(i + 1)) ans.push_back(j);
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    c.resize(n + 1, 0);
    forn(i, 1, n + 1) adj[i].clear();
    forn(i, 0, n - 1) {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    dfs(1, 1, 1);
    {
        int cnt = accumulate(c.begin(), c.end(), 0ll);
        if(cnt * 2 > n) {
            forn(i, 1, n + 1) {
                c[i] = !c[i];
            }
        }
    }
    int cnt = accumulate(c.begin(), c.end(), 0ll);
    vector <int> f = find(cnt);
    vector <int> g;
    {
        map<int, bool> done;
        for(auto i : f) done[i] = true;
        forn(i, 1, n + 1) if(!done[i]) g.push_back(i);
    }
    forn(i, 1, n + 1) {
        if(c[i] == 1) {
            cout << f[0] << " ";
            f.pop_front();
        }
        else {
            cout << g[0] << " ";
            g.pop_front();
        }
    }
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}