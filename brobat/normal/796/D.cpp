#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 300100
#define MOD 1000000007
 
int n, k, d, t1, t2;
vector<int> adj[MAXN];
map<pair<int, int>, int> ind;
int police[MAXN];
map<int, bool> ans;
int dist[MAXN];
 
void bfs() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    forn(i, 0, n) {
        if(police[i]) {
            dist[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
            else if(dist[next] >= dist[curr]) {
                ans[ind[{curr, next}]] = true;
            }
        }
    }
}
 
void solve() {
    cin >> n >> k >> d;
    forn(i, 0, k) {
        cin >> t1;
        t1--;
        police[t1] = true;
    }
    forn(i, 0, n-1) {
        cin >> t1 >> t2;
        t1--; t2--;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
        ind[{t1, t2}] = i + 1;
        ind[{t2, t1}] = i + 1;
    }
    bfs();
    int s = 0;
    for(auto i : ans) s++;
    cout << s << endl;
    for(auto i : ans) cout << i.first << " ";
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