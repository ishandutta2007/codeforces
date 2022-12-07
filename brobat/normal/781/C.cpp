#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n, m, k, t1, t2, sz;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> v;
map<int, vector<int>> mp;

void dfs(int node) {
    visited[node] = true;
    v.push_back(node);
    for(auto next: adj[node]) {
        if(!visited[next]) {
            dfs(next);
            v.push_back(node);
        }
    }
}

void func(int x, int y) {
    // x = total values left to print
    // y = total lines left to print
    // sz = the upper bound of values that can be printed in one line
    if(x==0 || y==0) return;
    int upper = ceil(x/float(y));
    int lower = floor(x/float(y));
    cout << lower << " ";
    forn(i, 0, lower) cout << v[2*n-x-1+i] << " ";
    cout << endl;
    func(x-lower, y-1);
}

void solve() {
    cin >> n >> m >> k;
    forn(i, 0, m) {
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    dfs(1);
    sz = ceil(2*n/floor(k));
    vector<int> temp;
    func(2*n-1, k);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}