#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n;
vector <string> v;
vector <int> adj[26];
int needed[26], done[26], dist[26];
vector <int> ans;
bool pos;

pair<char, char> compare(string &a, string &b) {
    forn(i, 0, min(a.length(), b.length())) {
        if(a[i]!=b[i]) return {a[i], b[i]};
    }
    if(a.length() > b.length()) pos = false;
    return {a[0], b[0]};
}

void bfs() {
    memset(dist, -1, sizeof(dist));
    queue <int> q;
    forn(i, 0, 26) {
        if(needed[i]==0) {
            q.push(i);
            dist[i] = 0;
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto next : adj[curr]) {
            done[next]++;
            if(done[next]==needed[next]) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    cin >> n;
    pos = true;
    forn(i, 0, 26) {
        needed[i] = 0;
        done[i] = 0;
    }
    v.resize(n);
    forn(i, 0, n) cin >> v[i];
    forn(i, 0, n - 1) {
        auto x = compare(v[i], v[i + 1]);
        if(x.first==x.second) continue;
        // cout << x.first << " " << x.second << endl;
        adj[x.first - 'a'].push_back(x.second - 'a');
        needed[x.second - 'a']++;
    }
    bfs();
    forn(i, 0, 26) if(dist[i]==-1) pos = false;
    if(pos) for(auto i : ans) cout << (char)('a' + i);
    else cout << "Impossible";
    
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}