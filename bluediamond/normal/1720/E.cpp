#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500 + 7;
const int INF = (int) 1e9 + 7;
int n, k, a[N][N], dp[N][N], y, gd[N][N];
int mn_row[N * N], mn_col[N * N];
int mx_row[N * N], mx_col[N * N];
set<int> s;

void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  ///freopen ("___input___.txt", "r", stdin);


  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      s.insert(a[i][j]);
    }
  }
  {
    /// normalize
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        mp[a[i][j]] = 0;
      }
    }
    {
      y = 0;
      for (auto &it : mp) {
        it.second = ++y;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = mp[a[i][j]];
      }
    }
  }
  ///print();
  for (int i = 1; i <= y; i++) {
    mn_col[i] = mn_row[i] = +INF;
    mx_col[i] = mx_col[i] = -INF;
  }
  int current_distinct = (int) s.size();

  if (current_distinct <= k) {
    cout << k - current_distinct << "\n";
    exit(0);
  }
  assert(current_distinct > k);

  int need_to_lose = current_distinct - k + 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      mn_row[a[i][j]] = min(mn_row[a[i][j]], i);
      mn_col[a[i][j]] = min(mn_col[a[i][j]], j);

      mx_row[a[i][j]] = max(mx_row[a[i][j]], i);
      mx_col[a[i][j]] = max(mx_col[a[i][j]], j);
    }
  }

  for (int l = 1; l <= n; l++) {
    int dim = n - l + 1;

    for (int r = 1; r <= dim; r++) {
      for (int c = 1; c <= dim; c++) {
        gd[r][c] = 0;
      }
    }
    for (int i = 1; i <= y; i++) {
      int dr_r = min(dim, mn_row[i]);
      int st_r = max(1, mx_row[i] - l + 1);

      int dr_c = min(dim, mn_col[i]);
      int st_c = max(1, mx_col[i] - l + 1);

      if (st_r <= dr_r && st_c <= dr_c) {
        gd[st_r][st_c]++;
        gd[dr_r + 1][st_c]--;
        gd[st_r][dr_c + 1]--;
        gd[dr_r + 1][dr_c + 1]++;
      }
    }
    for (int r = 1; r <= dim; r++) {
      for (int c = 1; c <= dim; c++) {
        gd[r][c] += gd[r - 1][c];
      }
    }
    for (int r = 1; r <= dim; r++) {
      for (int c = 1; c <= dim; c++) {
        gd[r][c] += gd[r][c - 1];
      }
    }
    for (int r = 1; r <= dim; r++) {
      for (int c = 1; c <= dim; c++) {
        if (gd[r][c] == need_to_lose || gd[r][c] == need_to_lose - 1) {
          cout << "1\n";
          exit(0);
        }
      }
    }
  }
  cout << "2\n";

  exit(0);

  for (int i = 1; i <= y; i++) {
    cout << i << " : " << mn_row[i] << "..." << mx_row[i] << " and " << mn_col[i] << "..." << mx_col[i] << "\n";
  }

  return 0;
}
/**
pt v avem :

mn1[v], mx1[v] si mn2[v], mx2[v]

(x1, x2) -> (x1 + l, x2 + l)

avem x1 <= mn1[v] <= mx1[v] <= x1 + l
avem x2 <= mn2[v] <= mx2[v] <= x2 + l


mx1[v] - l <= x1 <= mn1[v]
mx2[v] - l <= x2 <= mn2[v]

**/