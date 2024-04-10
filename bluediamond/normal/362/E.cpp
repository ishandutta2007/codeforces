#include <bits/stdc++.h>

using namespace std;

struct E {
  int to;
  int cap;
  int cost;
};

const int N = 50 + 7;
const int INF = (int) 2e9;
int dist[N];
int par[N];
int n;
int k;
int s;
int d;
vector<E> e;
vector<int> g[N];


void add(int x, int y, int c, int z) {
  g[x].push_back((int) e.size());
  g[y].push_back((int) e.size() + 1);
  e.push_back({y, c, z});
  e.push_back({x, 0, -z});
}


struct T {
  int x;
  int val;
};

bool operator < (T a, T b) {
  return a.val > b.val;
}

pair<int, int> get() {
  /// cost <= k
  int sol = 0;
  int cost = 0;
  while (1) {
    for (int i = 1; i <= n; i++) {
      dist[i] = INF;
      par[i] = -1;
    }
    priority_queue<T> q;
    q.push({s, 0});
    dist[s] = 0;
    while (!q.empty()) {
      T k = q.top();
      q.pop();
      int x = k.x;
      if (k.val != dist[x]) {
        continue;
      }
      for (auto &i : g[x]) {
        if (e[i].cap > 0) {
          int y = e[i].to;
          int dnew = dist[x] + e[i].cost;
          if (dnew < dist[y]) {
            dist[y] = dnew;
            par[y] = i;
            q.push({y, dist[y]});
          }
        }
      }
    }
    if (par[d] == -1) {
      break;
    }
    vector<int> ids;
    int node = d;
    while (node != s) {
      ids.push_back(par[node]);
      node = e[par[node] ^ 1].to;
    }
    int vmin = INF, sum = 0;
    for (auto &i : ids) {
      vmin = min(vmin, e[i].cap);
      sum += e[i].cost;
    }
    if (sum) {
      vmin = min(vmin, (k - cost) / sum);
      if (vmin == 0) {
        break;
      }
    }
    sol += vmin;
    cost += sum * vmin;
    for (auto &i : ids) {
      e[i].cap -= vmin;
      e[i ^ 1].cap += vmin;
    }
  }
  return make_pair(sol, cost);
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n>>k;
        s=1;
        d=n;
        for (int i=1;i<=n;i++)
        {
                for (int j=1;j<=n;j++)
                {
                        int c;
                        cin>>c;
                        if (c)
                        {
                                add(i,j,c,0);
                                add(i,j,INF,1);
                        }
                }
        }
        pair<int,int> x=get();
        cout<<x.first<<"\n";
}