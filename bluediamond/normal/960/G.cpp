#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
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

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int N = (int) 1e5 + 7;
const int B = 31;
const int INVB = dv(1, B);
const int K = (1 << 23);

int nx, a, b, fact[N], ifact[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

void fft(vector<int> &a, bool inv) {
  int n = (int) a.size(), k = log2(n);
  for (int i = 0; i < n; i++) {
    int j = 0, te = 0;
    for (int b = 0; b < k; b++) {
      if (i & (1 << b)) {
        j += (1 << (k - b - 1));
        te += (1 << b);
      }
    }
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (int l = 2; l <= n; l *= 2) {
    int ml = inv ? INVB : B;
    for (int j = l; j < K; j *= 2) {
      ml = mul(ml, ml);
    }
    for (int i = 0; i < n; i += l) {
      int cur = 1;
      for (int j = 0; j < l / 2; j++) {
        int x = a[i + j];
        int y = mul(cur, a[i + l / 2 + j]);
        a[i + j] = add(x, y);
        a[i + l / 2 + j] = add(x, -y);
        cur = mul(cur, ml);
      }
    }
  }
  if (inv) {
    n = dv(1, n);
    for (auto &x : a) {
      x = mul(x, n);
    }
  }
}

vector<int> smart(vector<int> a, vector<int> b) {
  int n = (int) a.size() + (int) b.size(), k = 1;
  while (k <= n) {
    k *= 2;
  }
  a.resize(k, 0);
  b.resize(k, 0);
  fft(a, 0);
  fft(b, 0);
  for (int i = 0; i < k; i++) {
    a[i] = mul(a[i], b[i]);
  }
  fft(a, 1);
  while (!a.empty() && a.back() == 0) {
    a.pop_back();
  }
  return a;
}

vector<int> dumb(vector<int> a, vector<int> b) {
  int n = (int) a.size(), m = (int) b.size();
  vector<int> c(n + m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      addup(c[i + j], mul(a[i], b[j]));
    }
  }
  while (!c.empty() && c.back() == 0) {
    c.pop_back();
  }
  for (auto &x : c) {
    assert(x >= 0);
  }
  return c;
}

vector<int> get(int l, int r) {
  assert(l <= r);
  if (l == r) {
    vector<int> sol(2);
    sol[0] = 1;
    sol[1] = l;
    return sol;
  }
  int m = (l + r) / 2;
  vector<int> a = get(l, m);
  vector<int> b = get(m + 1, r);
  return smart(a, b);
}


int get(int a) {
  if (nx <= 1) {
    return (a == nx);
  }
  auto ve = get(0, nx - 1);
  ve.push_back(0);
  reverse(ve.begin(), ve.end());
  return ve[a];
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  /**
  vector<int> aa = {1, 4, 41, 42};
  vector<int> bb = {7, 42, 34, 24};
  vector<int> c = smart(aa, bb);
  vector<int> d = dumb(aa, bb);
  for (auto &x : c) {
    cout << x << " ";
  }
  cout << "\n";
  for (auto &x : d) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;**/

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
      fact[i] = mul(fact[i - 1], i);
    }
    ifact[N - 1] = dv(1, fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
      ifact[i] = mul(ifact[i + 1], i + 1);
    }
  }

  cin >> nx >> a >> b;
  nx--;
  a--;
  b--;

  if (a + b > nx) {
    cout << "0\n";
    return 0;
  }

  int sol = get(a + b);
  sol = mul(sol, comb(a + b, a));


  cout << sol << "\n";
  if (home) {
    assert(sol == 770478666);
  }
  return 0;
}
/**



**/