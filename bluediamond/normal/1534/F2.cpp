#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    assert((int)s.size() == m);
    for (int j = 0; j < m; j++) {
      char ch = s[j];
      assert(ch == '.' || ch == '#');
      if (ch == '#') {
        a[i][j] = 1;
      }
    }
  }
  vector<int> needcol(m);
  for (int j = 0; j < m; j++) {
    cin >> needcol[j];
  }

  vector<vector<int>> id(n, vector<int>(m, 0));
  int y = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        id[i][j] = ++y;
      }
    }
  }

  vector<int> whatcol(y + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (id[i][j]) {
        whatcol[id[i][j]] = j;
      }
    }
  }

  vector<vector<int>> g(y + 1), ig(y + 1);

  function<void(int, int)>addedge = [&](int a, int b) {
    assert(1 <= a && a <= y);
    assert(1 <= b && b <= y);
    g[a].push_back(b);
    ig[b].push_back(a);
  };

  for (int j = 0; j < m; j++) {
    int last = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (id[i][j]) {
        if (last != -1) {
          addedge(id[i][j], id[last][j]);
        }
        last = i;

        if (i - 1 >= 0 && id[i - 1][j]) {
          addedge(id[i][j], id[i - 1][j]);
        }
      }
    }
    for (auto& j2 : { j - 1,j + 1 }) {
      if (0 <= j2 && j2 < m) {
        int last = -1;
        for (int i = n - 1; i >= 0; i--) {
          if (id[i][j2]) {
            last = i;
          }
          if (id[i][j]) {
            if (last != -1) {
              addedge(id[i][j], id[last][j2]);
            }
          }
        }
      }
    }
  }

  vector<bool> vis(y + 1, 0);
  vector<int> ord;

  function<void(int)>dfs = [&](int a) {
    assert(1 <= a && a <= y);
    vis[a] = 1;
    for (auto& b : g[a]) {
      if (vis[b] == 0) {
        dfs(b);
      }
    }
    ord.push_back(a);
  };
  for (int i = 1; i <= y; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  reverse(ord.begin(), ord.end());

  vector<int> col(y + 1, 0);

  function<void(int, int)>coldfs = [&](int a, int curcol) {
    assert(1 <= a && a <= y);
    col[a] = curcol;
    for (auto& b : ig[a]) {
      if (col[b] == 0) {
        coldfs(b, curcol);
      }
    }
  };

  int curcol = 0;
  for (auto& a : ord) {
    if (col[a] == 0) {
      curcol++;
      coldfs(a, curcol);
    }
  }

  vector<bool> is(curcol + 1, 0);


  for (int a = 1; a <= y; a++) {
    for (auto& b : g[a]) {
      if (col[a] != col[b]) {
        is[col[b]] = 1;
      }
    }
  }


  const int INF = (int)1e9 + 7;

  vector<int> mncol(curcol + 1, +INF), mxcol(curcol + 1, -INF);


  for (int a = 1; a <= y; a++) {
    if (is[col[a]] == 0) {
      mncol[col[a]] = min(mncol[col[a]], whatcol[a]);
      mxcol[col[a]] = max(mxcol[col[a]], whatcol[a]);
    }
  }

  for (auto& a : ord) {
    for (auto& b : g[a]) {
      if (col[a] != col[b]) {
        mncol[col[b]] = min(mncol[col[b]], mncol[col[a]]);
        mxcol[col[b]] = max(mxcol[col[b]], mxcol[col[a]]);
      }
    }
  }

  for (int i = 1; i <= curcol; i++) {
    assert(0 <= mncol[i] && mncol[i] <= mxcol[i] && mxcol[i] < m);
  }

  vector<pair<int, int>>segs;

  for (int j = 0; j < m; j++) {
    int val = needcol[j];
    if (val == 0) {
      continue;
    }
    int seen = 0;
    int pzi = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (id[i][j]) {
        seen++;
        if (seen == val) {
          pzi = i;
          break;
        }
      }
    }
    assert(pzi != -1);
    {
      int i = pzi;
      int a = id[i][j];
      segs.push_back({ mncol[col[a]],mxcol[col[a]] });
    }
  }

  sort(segs.begin(), segs.end(), [&](pair<int, int>a, pair<int, int>b) {
    return a.second < b.second; });

  int bigr = -1, sol = 0;
  for (auto& it : segs) {
    int l = it.first, r = it.second;
    if (bigr < l) {
      sol++;
      bigr = r;
    }
  }
  cout << sol << "\n";
}