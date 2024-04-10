#include <bits/stdc++.h>

using namespace std;

class F
{
  struct E
  {
    int from;
    int to;
    int capacity;
  };

public:
  vector<E> edges;
  vector<vector<int>> g;
  vector<int> level, ptr;
  int n;
  int want;

  F(int nn, int wantt) : n(nn), want(wantt), g(nn + 1), level(nn + 1), ptr(nn + 1)
  {

  }

  int dfs(int a, int cur)
  {
    if (a == n || cur == 0)
    {
      return cur;
    }
    while (ptr[a] < (int) g[a].size())
    {
      int i = g[a][ptr[a]++];
      if (edges[i].capacity && level[edges[i].to] == 1 + level[a])
      {
        int sol = dfs(edges[i].to, min(edges[i].capacity, cur));
        if (sol)
        {
          edges[i].capacity -= sol;
          edges[i ^ 1].capacity += sol;
          return sol;
        }
      }
    }
    return 0;
  }

  ~F()
  {
    int sol = 0;
    while (1)
    {
      for (int i = 1; i <= n; i++)
      {
        level[i] = -1;
        ptr[i] = 0;
      }
      level[1] = 0;
      queue<int> q;
      q.push(1);
      while (!q.empty())
      {
        int a = q.front();
        q.pop();

       // cout << "vertex = " << a << "\n";
        for (auto &i : g[a])
        {
          if (edges[i].capacity && level[edges[i].to] == -1)
          {
            level[edges[i].to] = 1 + level[a];
            q.push(edges[i].to);
          }
        }
      }
      if (level[n] == -1)
      {
        break;
      }

      while (1)
      {
        int flow = dfs(1, (int) 1e9);
        if (!flow)
        {
          break;
        }
        sol += flow;
      }
    }
    if (sol != want)
    {
      cout << "un";
    }
    cout << "fair\n";
  }

  void operator += (vector<int> data)
  {
    assert((int) data.size() == 3);
    int from = data[0];
    int to = data[1];
    assert(1 <= from && from <= n);
    assert(1 <= to && to <= n);

    int capacity = data[2];

    g[from].push_back((int) edges.size());
    g[to].push_back((int) edges.size() + 1);


    edges.push_back({from, to, capacity});
    edges.push_back({to, from, 0});
  }

};

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int n, b, q;
  cin >> n >> b >> q;
  vector<pair<int, int>> restr;
  restr.push_back({0, 0});
  restr.push_back({b, n});
  while (q--)
  {
    int pref, cnt;
    cin >> pref >> cnt;
    restr.push_back({pref, cnt});
  }
  sort(restr.begin(), restr.end());
  vector<vector<int>> v;
  for (int i = 0; i < (int) restr.size() - 1; i++)
  {
    int l = restr[i].first + 1, r = restr[i + 1].first, need = restr[i + 1].second - restr[i].second;
    if (need < 0)
    {
      cout << "unfair\n";
      exit(0);
    }
    if (l > r)
    {
      continue;
    }
    vector<int> am(5, 0);
    for (int i = l; i <= r; i++)
    {
      am[i % 5]++;
    }
    am.push_back(need);
    v.push_back(am);
  }
  F flow(1 + 5 + (int) v.size() + 1, n);
  for (int i = 1; i <= 5; i++)
  {
    flow += (vector<int> {1, 1 + i, n / 5});
  }

  for (int i = 1; i <= (int) v.size(); i++)
  {
    flow += (vector<int> {1 + 5 + i, 1 + 5 + (int) v.size() + 1, v[i - 1].back()});
    for (int j = 0; j < 5; j++)
    {
      flow += (vector<int> {1 + 1 + j, 1 + 5 + i, v[i - 1][j]});
    }
  }



  return 0;
}