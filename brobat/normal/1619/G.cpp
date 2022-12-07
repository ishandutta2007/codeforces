#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, k;
int t1, t2, t3;
map<int, vector<int>> x, y;
map<pair<int, int>, vector<pair<int, int>>> adj;
vector<vector<int>> mine;
map<pair<int, int>, int> tme;
map<pair<int, int>, bool> visited;
vector <int> ans;

int dfs(pair <int, int> node) {
    visited[node] = true;
    int ans = tme[node];
    for(auto next : adj[node]) {
        if(!visited[next]) {
            ans = min(ans, dfs(next));
        }
    }
    return ans;
}

bool check(int x) {
    // Can all mines be exploded in x seconds?
    int cnt = -1;
    for(auto i : ans) if(i > x) cnt++;
    if(cnt > x) return false;
    return true;
}

int binary_search(int left, int right) {
    int ans = -1;
    if(check(left)) return 0;
    while(left <= right) {
        int mid = (left + right)/2;
        if(!check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans + 1;
}

void solve() {
    cin >> n >> k;
    x.clear(); y.clear(); adj.clear();  tme.clear(); mine.clear();
    visited.clear(); ans.clear();
    forn(i, 0, n) {
        cin >> t1 >> t2 >> t3;
        x[t1].push_back(t2);
        y[t2].push_back(t1);
        mine.push_back({t1, t2, t3});
        tme[{t1, t2}] = t3;
    }
    for(auto i : x) sort(x[i.first].begin(), x[i.first].end());
    for(auto i : y) sort(y[i.first].begin(), y[i.first].end());
    for(auto i : mine) {
        // i[0], i[1].
        int left = upper_bound(x[i[0]].begin(), x[i[0]].end(), i[1]) - x[i[0]].begin();
        
        if(left < x[i[0]].size() && x[i[0]][left] - i[1] <= k) {
            adj[{i[0], i[1]}].push_back({i[0], x[i[0]][left]});
            adj[{i[0], x[i[0]][left]}].push_back({i[0], i[1]});
        }
        
        int down = upper_bound(y[i[1]].begin(), y[i[1]].end(), i[0]) - y[i[1]].begin();
        // if(i[0] == 0 && i[1] == -1) cout << down << endl;
        if(down < y[i[1]].size() && y[i[1]][down] - i[0] <= k) {
            adj[{i[0], i[1]}].push_back({y[i[1]][down], i[1]});
            adj[{y[i[1]][down], i[1]}].push_back({i[0], i[1]});
        }
    }
    // for(auto i : adj) {
    //     cout << i.first.first << "," << i.first.second << ":";
    //     for(auto j : i.second) cout << "[" << j.first << "," << j.second << "] ";
    //     cout << endl;
    // }
    for(auto i : mine) {
        if(visited[{i[0], i[1]}]) continue;
        ans.push_back(dfs({i[0], i[1]}));
    }
    sort(ans.begin(), ans.end());
    // for(auto i : ans) cout << i << " "; cout << endl;
    // Now, binary search on the minimum time?
    cout << binary_search(0, MAXN) << endl;
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