#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = 200100;
const int INF = 0x3f3f3f3f;
int d1[N], dn[N];

vector<int> adj[N];
vector<int> spec;

void bfs(int start, int dist[N]) {
    queue<int> q;
    for (int i=0; i<N; ++i) {
        dist[i] = INF;
    }
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& v : adj[u]) {
            if (dist[v] > dist[u]+1) {
                q.push(v);
                dist[v] = dist[u]+1;
            }
        }
    }
}

int n, m, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=k; ++i) {
        int a;
        cin >> a;
        spec.push_back(a);
    }
    for (int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        //cerr << " :: " << u << " " << v << endl;
    }
    bfs(1, d1);
    bfs(n, dn);

    int L = d1[n];
    assert(dn[1] == d1[n]);
    assert(L < N);

    set<pii> dns;
    for (auto& u : spec) {
        dns.insert(pii(dn[u], u));
    }

    int ans = 0;

    set<pii> frees;

    for (auto& u : spec) {
        dns.erase(pii(dn[u], u));

        auto it = dns.lower_bound(pii(L-d1[u]+1, -1));
        //cerr << " :: " << 
        if (it != dns.begin()) {
            --it;
            int amt = min(d1[u]+it->first+1, L);
            ans = max(ans, amt);
            //cerr << "ANS " << ans << " FOR " << u << ":: " << it->first << "," << it->second << endl;
        } else {
            frees.insert(pii(dn[u], u));
        }

        dns.insert(pii(dn[u], u));
    }

    for (auto& u : spec) {
        bool wasin = 0;
        if (frees.count(pii(dn[u], u))) {
            frees.erase(pii(dn[u], u));
            wasin = 1;
        }

        auto it = frees.begin();
        if (it != frees.end()) {
            int amt = min(d1[u]+it->first+1, L);
            ans = max(ans, amt);
        }

        if (wasin) {
            frees.insert(pii(dn[u], u));
        }
    }

    assert(ans);
    cout << ans << "\n";
    return 0;
}