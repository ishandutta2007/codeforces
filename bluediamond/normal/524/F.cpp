#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e6 + 7;
string s;
int n, f[N], c[N], ord[N];

struct T {
  int i;
  int c1;
  int c2;
};

vector<T> so(vector<T> v) {
  int n = (int) v.size();
  for (int i = 0; i <= n; i++) {
    f[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    f[v[i].c2]++;
  }
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
  }
  vector<T> v2(n);
  for (int i = n - 1; i >= 0; i--) {
    v2[--f[v[i].c2]] = v[i];
  }
  for (int i = 0; i <= n; i++) {
    f[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    f[v2[i].c1]++;
  }
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    v[--f[v2[i].c1]] = v2[i];
  }
  return v;
}

bool operator < (T a, T b) {
  if (a.c1 != b.c1) {
    return a.c1 < b.c1;
  } else {
    return a.c2 < b.c2;
  }
}

int baltotal, a[N], sum[N], pre[N], suf[N];
/// prefer '(' si dupa ')'

signed realMain() {
  cin >> s;
  n = (int) s.size();
  int raz = -1;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '(') baltotal++; else baltotal--;
    a[i] = (s[i - 1] == '(') ? +1 : -1;
    sum[i] = sum[i - 1] + a[i];
  }
  pre[1] = sum[1];
  for (int i = 2; i <= n; i++) {
    pre[i] = min(pre[i - 1], sum[i]);
  }
  suf[n] = sum[n];
  for (int i = n - 1; i >= 1; i--) {
    suf[i] = min(suf[i + 1], sum[i]);
  }
  for (int i = 0; i < n; i++) {
    c[i] = s[i];
    f[c[i]]++;
  }
  for (int i = 1; i < N; i++) {
    f[i] += f[i - 1];
  }
  for (int i = 0; i < n; i++) {
    ord[--f[c[i]]] = i;
  }
  map<int, int> trn;
  for (int i = 0; i < n; i++) {
    trn[c[i]] = 0;
  }
  int curtrn = 0;
  for (auto &it : trn) {
    it.second = curtrn++;
  }
  for (int i = 0; i < n; i++) {
    c[i] = trn[c[i]];
  }
  for (int len = 1; len <= n; len *= 2) {
    vector<T> v;
    for (int i = 0; i < n; i++) {
      v.push_back({i, c[i], c[(i + len) % n]});
    }
    v = so(v);
    for (int i = 0; i < n; i++) {
      ord[i] = v[i].i;
    }
    c[v[0].i] = 0;
    for (int i = 1; i < n; i++) {
      c[v[i].i] = c[v[i - 1].i] + (v[i - 1] < v[i]);
    }
  }
  for (int j = 0; j < n; j++) {
    bool ok = 1;
    int cur = max(0, -baltotal), init = cur;
    if (j + 1 <= n && cur + suf[j + 1] - sum[j] < 0) {
      ok = 0;
    }
    cur = init + sum[n] - sum[j];
    if (j && cur + pre[j] < 0) {
      ok = 0;
    }
    if (!ok) {
      continue;
    }
    if (raz == -1 || c[j] < c[raz]) {
      raz = j;
    }
  }
  while (baltotal < 0) {
    cout << "(";
    baltotal++;
  }
  for (int i = 0; i < n; i++) {
    cout << s[(i + raz) % n];
  }
  while (baltotal > 0) {
    cout << ")";
    baltotal--;
  }
  cout << "\n";
  return 0;
}