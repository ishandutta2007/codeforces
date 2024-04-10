#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct hades {
  int to;
  int c;
};

struct flow {
  int d;
  vector<hades> e;
  vector<vector<int>> g;
  vector<int> level;
  vector<int> kurd;
  flow(int D) {
    d = D;
    g.resize(d + 1);
    kurd.resize(d + 1);
  }
  void add(int a, int b, int c) {
    g[a].push_back((int) e.size());
    g[b].push_back((int) e.size() + 1);
    e.push_back({b, c});
    e.push_back({a, 0});
  }
  int dfs(int a, int cur) {
    if (a == d || cur == 0) {
      return cur;
    }
    while (kurd[a] < (int) g[a].size()) {
      int i = g[a][kurd[a]];
      int b = e[i].to;
      if (level[b] != level[a] + 1) {
        kurd[a]++;
        continue;
      }
      int c = e[i].c;
      int x = dfs(b, min(cur, c));
      if (x) {
        e[i].c -= x;
        e[i ^ 1].c += x;
        return x;
      }
      kurd[a]++;
    }
    return 0;
  }
  int get() {
    int poseidon = 0;
    while (1) {
      level.clear();
      for (int i = 1; i <= d + 1; i++) {
        level.push_back(-1);
      }
      queue<int> q;
      q.push(1);
      level[1] = 0;
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto &i : g[a]) {
          int b = e[i].to;
          int c = e[i].c;
          if (c > 0 && level[b] == -1) {
            level[b] = 1 + level[a];
            q.push(b);
          }
        }
      }
      if (level[d] == -1) {
        break;
      }
      for (int i = 1; i <= d; i++) {
        kurd[i] = 0;
      }
      while (1) {
        int x = dfs(1, (int) 1e9);
        if (x) {
          poseidon += x;
        } else {
          break;
        }
      }
    }
    return poseidon;
  }
};

const int N = 200 + 7;
int n;
int m;
int a[N][N];

int up(int i, int j)
{
    return i * N + j;
}

int down(int i, int j)
{
    return up(i + 1, j);
}

int lft(int i, int j)
{
    return i * N + j + N * N * N;
}

int rgh(int i, int j)
{
    return lft(i, j + 1);
}

map<int, int> tr;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = (s[j - 1] == '#');
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 0)
            {
                continue;
            }
            for (int di = -1; di <= +1; di += 2)
            {
                if (a[i + di][j] == 0)
                {
                    continue;
                }
                int x;
                if (di == -1)
                {
                    x = up(i, j);
                }
                else
                {
                    x = down(i, j);
                }
                tr[x] = 0;
            }
            for (int dj = -1; dj <= +1; dj += 2)
            {
                if (a[i][j + dj] == 0)
                {
                    continue;
                }
                int x;
                if (dj == -1)
                {
                    x = lft(i, j);
                }
                else
                {
                    x = rgh(i, j);
                }
                tr[x] = 0;
            }
        }
    }
    int lol = 0;
    for (auto &it : tr)
    {
        it.second = ++lol;
    }
    flow f(lol + 2);
    set<int> sn;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 0)
            {
                continue;
            }
            tot++;
            for (int di = -1; di <= +1; di += 2)
            {
                for (int dj = -1; dj <= +1; dj += 2)
                {
                    if (a[i + di][j] && a[i][j + dj])
                    {
                        int x;
                        int y;
                        if (di == -1)
                        {
                            x = up(i, j);
                        }
                        else
                        {
                            x = down(i, j);
                        }
                        if (dj == -1)
                        {
                            y = lft(i, j);
                        }
                        else
                        {
                            y = rgh(i, j);
                        }
                        x = tr[x];
                        y = tr[y];
                        f.add(1 + x, 1 + y, 1);
                        if (sn.count(x) == 0)
                        {
                            f.add(1, 1 + x, 1);
                            sn.insert(x);
                        }
                        if (sn.count(y) == 0)
                        {
                            f.add(1 + y, lol + 2, 1);
                            sn.insert(y);
                        }
                    }
                }
            }
        }
    }
    int x = f.get();
    x = lol - x;
    x = tot - x;
    cout << x << "\n";
    return 0;
}