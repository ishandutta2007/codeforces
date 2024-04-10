#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e5 + 7;
const int X = 30 + 7;
string s, t;
int n, m, x;
int best[X][N];

typedef long long ll;

int pw(int a, int b, int mod) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = (ll) r * a % mod;
    }
    a = (ll) a * a % mod;
    b /= 2;
  }
  return r;
}

int dv(int a, int b, int mod) {
  return (ll) a * pw(b, mod - 2, mod) % mod;
}

const int C = 3;
const int mods[] = {1000000271, 1000000787, 1000000931};

struct T {
  int a[C];
  T() {
    for (int j = 0; j < C; j++) {
      a[j] = 0;
    }
  }
};

bool operator < (T f, T s) {
  for (int i = 0; i < C; i++) {
    if (f.a[i] != s.a[i]) {
      return f.a[i] < s.a[i];
    }
  }
  return 0;
}

T operator + (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] += s.a[j];
    if (f.a[j] >= mods[j]) {
      f.a[j] -= mods[j];
    }
  }
  return f;
}

T operator - (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] -= s.a[j];
    if (f.a[j] < 0) {
      f.a[j] += mods[j];
    }
  }
  return f;
}

T operator * (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] = (ll) f.a[j] * s.a[j] % mods[j];
  }
  return f;
}

T operator ^ (T f, int x) {
  for (int j = 0; j < C; j++) {
    f.a[j] = pw(f.a[j], x, mods[j]);
  }
  return f;
}

T operator / (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] = dv(f.a[j], s.a[j], mods[j]);
  }
  return f;
}

bool operator == (T f, T s) {
  for (int j = 0; j < C; j++) {
    if (f.a[j] != s.a[j]) {
      return 0;
    }
  }
  return 1;
}

const int K = (int) 1e5 + 7;
T kwk[K], iki[K];

struct magma {
  vector<T> lol;
  int ln;
  magma(string s) {
    ln = (int) s.size();
    lol.resize(ln + 1);
    for (int j = 0; j < ln; j++) {
      T now;
      for (int k = 0; k < C; k++) {
        now.a[k] = s[j] - 'a';
      }
      lol[j + 1] = lol[j] + now * kwk[j + 1];
    }
  }
  T get(int l, int r) {
    l++;
    r++;
    if (l <= r) {
      T sol = lol[r] - lol[l - 1];
      sol = sol * iki[l - 1];
      return sol;
    }
    T x = get(l - 1, ln - 1);
    T y = get(0, r - 1);
    T it = kwk[ln - l + 1];
    return x + y * it;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  T p26;
  for (int j = 0; j < C; j++) {
    p26.a[j] = 26;
    kwk[0].a[j] = 1;
  }
  for (int j = 1; j < K; j++) {
    kwk[j] = kwk[j - 1] * p26;
  }
  for (int j = 0; j < K; j++) {
    iki[j] = kwk[0] / kwk[j];
  }
  cin >> n >> s >> m >> t >> x;
  s = " " + s;
  t = " " + t;
  magma ms(s), mt(t);
  function<int(int, int)> lcp_smart = [&] (int i, int j) {
    int ln1 = n - i + 1;
    int ln2 = m - j + 1;
    int sol = 0, lo = 1, hi = min(ln1, ln2);
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (ms.get(i, i + mid - 1) == mt.get(j, j + mid - 1)) {
        sol = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return sol;
  };
  for (int i = 1; i <= n; i++) {
    for (int it = 0; it < x; it++) {
      int lcp = lcp_smart(i, best[it][i - 1] + 1);
      best[it + 1][i + lcp - 1] = max(best[it + 1][i + lcp - 1], best[it][i - 1] + lcp);
    }
    for (int it = 0; it <= x; it++) {
      best[it][i] = max(best[it][i], best[it][i - 1]);
    }
  }
  if (best[x][n] == m) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}