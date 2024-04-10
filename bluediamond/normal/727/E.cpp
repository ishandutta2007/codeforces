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

const int K = (int) 1e6 + 7;
T kwk[K], iki[K];

struct magma {
  vector<T> lol;
  T cur, p26;
  int ln;
  magma(string s) {
    ln = (int) s.size();
    lol.resize(ln + 1);
    for (int j = 0; j < C; j++) {
      cur.a[j] = 1;
      p26.a[j] = 26;
    }
    for (int j = 0; j < ln; j++) {
      T now;
      for (int k = 0; k < C; k++) {
        now.a[k] = s[j] - 'a';
      }
      cur = cur * p26;
      lol[j + 1] = lol[j] + now * cur;
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

void upd(vector<int> x) {
  for (auto &it : x) {
    if (it == -1) {
      return;
    }
  }
  vector<int> y = x;
  sort(y.begin(), y.end());
  for (int i = 1; i < (int) y.size(); i++) {
    if (y[i] == y[i - 1]) {
      return;
    }
  }
  cout << "YES\n";
  for (auto &it : x) {
    cout << it << " ";
  }
  cout << "\n";
  exit(0);
}


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
  int n, k, g;
  string s;
  cin >> n >> k >> s >> g;
  vector<string> a(g);
  vector<T> vals(g);
  map<T, int> where;
  for (int i = 0; i < g; i++) {
    cin >> a[i];
    magma temp(a[i]);
    vals[i] = temp.get(0, (int) a[i].size() - 1);
    where[vals[i]] = i + 1;
  }
  magma ms(s);
  vector<int> pos(n * k);
  for (int i = 0; i < n * k; i++) {
    int j = (i + k - 1) % (n * k);
    T it = ms.get(i, j);
    if (where.count(it) == 0) {
      pos[i] = -1;
    } else {
      pos[i] = where[it];
    }
  }
  vector<int> cur;
  for (int j = 0; j < n; j++) {
    cur.push_back(pos[j * k]);
  }
  upd(cur);
  for (int i = n * k - k + 1; i < n * k; i++) {
    vector<int> cur;
    for (int j = 0; j < n; j++) {
      cur.push_back(pos[(i + j * k) % (n * k)]);
    }
    upd(cur);
  }
  cout << "NO\n";
  return 0;
}