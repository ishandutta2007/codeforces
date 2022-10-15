#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 50 + 7;
int n, m, y, v[N][N];
string s[N];

void put(int mat[N][N]) {
  y = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i + 1 <= n && s[i][j] == 'U' && s[i + 1][j] == 'D') {
        y++;
        mat[i][j] = mat[i + 1][j] = y;
      }
      if (j + 1 <= m && s[i][j] == 'L' && s[i][j + 1] == 'R') {
        y++;
        mat[i][j] = mat[i][j + 1] = y;
      }
    }
  }
}

void print(int mat[N][N]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
}

vector<pair<int, int>> kek;

void op(int r, int c) {
  kek.push_back({r, c});
  assert(1 <= r && r + 1 <= n);
  assert(1 <= c && c + 1 <= m);
  if (v[r][c] == v[r][c + 1]) {
    assert(v[r + 1][c] == v[r + 1][c + 1]);
    int x = v[r][c], y = v[r + 1][c];
    v[r][c] = v[r + 1][c] = x;
    v[r][c + 1] = v[r + 1][c + 1] = y;
  } else {
    assert(v[r][c] == v[r + 1][c]);
    assert(v[r][c + 1] == v[r + 1][c + 1]);
    int x = v[r][c], y = v[r][c + 1];
    v[r][c] = v[r][c + 1] = x;
    v[r + 1][c] = v[r + 1][c + 1] = y;
  }
}

void lol(int r, int c);
void rofl(int r, int c);

void lol(int r, int c) {
  if (v[r][c] == v[r][c + 1]) return;
  assert(v[r][c] == v[r + 1][c]);
  if (v[r][c + 1] == v[r + 1][c + 1]) {
    op(r, c);
    return;
  }
  rofl(r, c + 1);
  assert(v[r][c + 1] == v[r + 1][c + 1]);
  op(r, c);
}

void rofl(int r, int c) {
  if (v[r][c] == v[r + 1][c]) return;
  assert(v[r][c] == v[r][c + 1]);
  if (v[r + 1][c] == v[r + 1][c + 1]) {
    op(r, c);
    return;
  }
  lol(r + 1, c);
  assert(v[r + 1][c] == v[r + 1][c + 1]);
  op(r, c);
}

vector<pair<int, int>> to_state(int mat[N][N]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      v[i][j] = mat[i][j];
    }
  }
  kek.clear();
  bool swp = 0;
  if (m % 2 == 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        v[j][i] = mat[i][j];
      }
    }
    swp = 1;
    swap(n, m);
   /** for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << v[i][j] << " ";
      }
    }
    cout << "\n";**/
  }
  assert(m % 2 == 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j += 2) {
      lol(i, j);
    }
  }
  if (swp) {
    //cout << "sz = " << (int) kek.size() << "\n";
    swap(n, m);
    for (auto &it : kek) {
      swap(it.first, it.second);
    }
  }
  //exit(0);
  return kek;
}


int a[N][N], b[N][N];

signed realMain() {
  cin >> n >> m;
  for (int it = 1; it <= 2; it++) {
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      s[i] = "#" + s[i];
    }
    if (it == 1) {
      put(a);
    } else {
      put(b);
    }
  }
  if (home) {
    print(a);
    cout << "\n#######\n";
    print(b);
    cout << "done\n";
  }
  auto pre = to_state(a);
  auto suf = to_state(b);
  reverse(suf.begin(), suf.end());
  vector<pair<int, int>> ret;
  for (auto &it : pre) ret.push_back(it);
  for (auto &it : suf) ret.push_back(it);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      v[i][j] = a[i][j];
    }
  }
  cout << (int) ret.size() << "\n";
  for (auto &it : ret) {
    cout << it.first << " " << it.second << "\n";
    op(it.first, it.second);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i + 1 <= n && v[i][j] == v[i + 1][j]) assert(b[i][j] == b[i + 1][j]);
      if (j + 1 <= m && v[i][j] == v[i][j + 1]) assert(b[i][j] == b[i][j + 1]);
    }
  }
  return 0;
}