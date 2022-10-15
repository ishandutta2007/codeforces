#include <bits/stdc++.h>



using namespace std;

bool home = 1;

typedef long long ll;
const int M = 5;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

const int N = 500 + 7;
int n, m;
int a[N][N];
int initcop[N][N];
int pi[N];
int pj[N];
int sol[N];
int cur[N];
vector<vector<int>> happen;
int kit[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      int digit = s[j - 1] - 'a';
      a[j][i] = digit;
    }
  }
  swap(n, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      initcop[i][j] = a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    pi[i] = -1;
  }
  for (int j = 1; j <= m; j++) {
    pj[j] = -1;
  }

  while (1) {
    int r = -1, c = -1;
    for (int i = 1; i <= n; i++) {
      if (pi[i] == -1) {
        for (int j = 1; j <= m; j++) {
          if (pj[j] == -1 && a[i][j] > 0) {
            r = i;
            c = j;
          }
        }
      }
    }
    if (r == -1 && c == -1) {
      break;
    }
    pi[r] = c;
    pj[c] = r;
    int value = dv(1, a[r][c]);
    for (int j = 1; j <= m; j++) {
      a[r][j] = mul(a[r][j], value);
    }
    happen.push_back({ r, value });
    assert(a[r][c] == 1);
    for (int row = 1; row <= n; row++) {
      if (row != r && a[row][c] > 0) {
        int value = dv(a[row][c], a[r][c]);
        for (int j = 1; j <= m; j++) {
          addup(a[row][j], -mul(a[r][j], value));
        }
        happen.push_back({ row, r, value });

        assert(a[row][c] == 0);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      kit[i][j] = a[i][j];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    assert((int)s.size() == n);
    for (int i = 1; i <= n; i++) {
      int digit = s[i - 1] - 'a';
      for (int j = 1; j <= m; j++) {
        a[i][j] = initcop[i][j];
      }
      a[i][m + 1] = digit;
      cur[i] = digit;
    }
    for (auto& x : happen) {
      if ((int)x.size() == 2) {
        mulup(cur[x[0]], x[1]);
      }
      else {
        addup(cur[x[0]], -mul(cur[x[1]], x[2]));
      }
    }
    for (int i = 1; i <= n; i++) {
      a[i][m + 1] = cur[i];
      for (int j = 1; j <= m; j++) {
        a[i][j] = kit[i][j];
      }
    }
    /// write here
    for (int i = 1; i <= n; i++) {
      if (pi[i] != -1) {
        sol[pi[i]] = a[i][m + 1];
      }
    }
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      cnt += (pj[j] == -1);
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      int s = 0;
      for (int j = 1; j <= m; j++) {
        addup(s, mul(sol[j], a[i][j]));
      }
      ok &= (s == a[i][m + 1]);
    }
    if (ok) {
      int sol = 1;
      for (int j = 1; j <= cnt; j++) {
        sol = sol * 5LL % ((int)1e9 + 7);
      }
      cout << sol << "\n";
    }
    else {
      cout << "0\n";
    }
  }
}