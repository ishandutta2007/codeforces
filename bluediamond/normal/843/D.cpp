#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
  int from;
  int to;
  ll cost;
};


const int N = (int) 1e5 + 7;
const ll INF = (ll) 1e15;
int n, m, q;
vector<edge> edges;
vector<int> g[N];
ll best[N], sol[N];

void dijNormal() {
  priority_queue<pair<ll, int>> pq;
  for (int i = 2; i <= n; i++) best[i] = INF;
  pq.push({-best[1], 1});
  while (!pq.empty()) {
    int a = pq.top().second;
    ll val = -pq.top().first;
    pq.pop();
    if (val != best[a]) continue;
    for (auto &i : g[a]) {
      int b = edges[i].to;
      ll upd = val + edges[i].cost;
      if (upd < best[b]) {
        best[b] = upd;
        pq.push({-best[b], b});
      }
    }
  }
}

vector<int> qq[N * 10];

void elapse(int mxdist) {
  for (int i = 2; i <= n; i++) best[i] = INF;

  qq[0].push_back(1);

  for (int x = 0; x <= mxdist; x++) {
    for (int itr = 0; itr < (int) qq[x].size(); itr++) {
      int a = qq[x][itr];
      for (auto &i : g[a]) {
        int b = edges[i].to;
        ll upd = best[a] + edges[i].cost;
      //  cout << i << " uh " << edges[i].cost << " " << upd << "\n";
        if (upd < best[b]) {
          best[b] = upd;
          if (upd <= mxdist) {

            if (upd >= N * 10 || upd < 0) {
              cout << "what?\n";
              cout << upd << "\n";
              cout << best[a] << " and " << edges[i].cost << "\n";
              exit(0);
            }
            qq[upd].push_back(b);
          }
        }
      }
    }
    qq[x].clear();
  }
  for (auto &it : edges) {
    it.cost = best[it.from] + it.cost - best[it.to];
    assert(it.cost >= 0);
  }
  for (int i = 1; i <= n; i++) {
    sol[i] += best[i];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n >> m >> q;
  edges.resize(m);
  int __ = 0;
  for (auto &it : edges) {
    cin >> it.from >> it.to >> it.cost;
    g[it.from].push_back(__++);
  }


  dijNormal();

  for (auto &it : edges) {
    it.cost = best[it.from] + it.cost - best[it.to];
    assert(it.cost >= 0);
  }
  for (int i = 1; i <= n; i++) {
    sol[i] += best[i];
  }

  int mxdist = 0;

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int vertex;
      cin >> vertex;
      if (mxdist) {
        elapse(mxdist);
        mxdist = 0;
      }
      if (sol[vertex] >= INF) {
        cout << "-1\n";
      } else {
        cout << sol[vertex] << "\n";
      }
    } else {
      int cnt;
      cin >> cnt;
      mxdist += cnt;
      for (int i = 1; i <= cnt; i++) {
        int e;
        cin >> e;
        edges[e - 1].cost++;
      }
    }
  }

  return 0;
}