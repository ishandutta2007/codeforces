#include <bits/stdc++.h>

using namespace std;

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

struct magma {
  vector<T> lol;
  T cur, p1000000;
  int ln;
  void init(vector<int> s) {
    ln = (int) s.size();
    lol.resize(ln + 1);
    for (int j = 0; j < C; j++) {
      cur.a[j] = 1;
      p1000000.a[j] = 1000000;
    }
    for (int j = 0; j < ln; j++) {
      T now;
      for (int k = 0; k < C; k++) {
        now.a[k] = s[j];
      }
      cur = cur * p1000000;
      lol[j + 1] = lol[j] + now * cur;
    }
  }
  T get(int l, int r) {
    l++;
    r++;
    if (l <= r) {
      T sol = lol[r] - lol[l - 1];
      T val = p1000000 ^ (l - 1);
      sol = sol / val;
      return sol;
    }
    T x = get(l - 1, ln - 1);
    T y = get(0, r - 1);
    return x + y * (p1000000 ^ (ln - l + 1));
  }
};

const int N = 200000 + 7;
int n;
int m;
int a[N];
int d[N];

int last(int x) {
  int p = 0, l = 1, r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m] <= x) {
      p = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return p;
}

vector<int> b;

magma nor, rev;

bool is(int l, int r) {
  if (l >= r) {
    return 1;
  }
  return nor.get(l, r) == rev.get((int) b.size() - r - 1, (int) b.size() - l - 1);
}

bool pali(int l, int r) {
  return is(l - 1, r - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    d[i] = a[i + 1] - a[i];
    b.push_back(d[i]);
  }
  nor.init(b);
  reverse(b.begin(), b.end());
  rev.init(b);
  vector<int> ret;
  for (int p = 0; p <= n; p++) {
    int x = a[1] + a[p];
    int y = a[p + 1] + a[n] - m;
    int val;
    if (p >= 1 && p < n && x != y) {
      continue;
    }
    if (p == 0) {
      val = y;
    } else {
      val = x;
    }
    if (val < 0 || val >= m || last(val) != p) {
      continue;
    }
    if (pali(1, p - 1) == 0 || pali(p + 1, n - 1) == 0) {
      continue;
    }
    ret.push_back(val);
  }
  cout << (int) ret.size() << "\n";
  for (auto &x : ret) {
    cout << x << " ";
  }
  cout << "\n";
}