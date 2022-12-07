//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100100

int n;
vector <int> adj[MAXN];
int dist[MAXN]; // distance from ROOT by BFS
double multi[MAXN]; // multiplier (1/multi)
int sze[MAXN]; // sze of it's adj vector.

void bfs(int start) {
    queue <int> q;
    dist[start] = 0;
    multi[start] = 1/double(sze[start]);
    q.push(start);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int e : adj[v]) {
            if(dist[e] == -1) {
                dist[e] = dist[v] + 1;
                multi[e] = multi[v] * 1/double(max(1,sze[e]-1));
                q.push(e);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, n) {
        sze[i] = 0;
        dist[i] = -1;
        multi[i] = 1;
    }
    int t1, t2;
    forn(i, n-1) {
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
        sze[t1] += 1;
        sze[t2] += 1;
    }
    bfs(0);
    double ans = 0;
    // forn(i, n) cout << dist[i] << " " << multi[i] << endl;
    for(int i=1; i<n; i++) {
        if(sze[i]==1) {
            ans += double(dist[i])*double(multi[i]);
        }
    }
    cout << ans;
    return 0;
}