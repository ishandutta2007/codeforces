#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int LOG = 19;
const int N = 1 << LOG;
const ld PI = acos(-1);

template<int MOD>
struct modInt {
  int x;

  void normalize() {
    if (x < 0) x += MOD;
    else if (x >= MOD) x -= MOD;
  }

  modInt() = default;

  modInt(int x) : x(x) {
    normalize();
  }

  modInt(ll x) : x(int(x % MOD)) {
    normalize();
  }

  friend modInt operator+(const modInt &a, const modInt &b) {
    return modInt(a.x + b.x);
  }

  friend modInt operator-(const modInt &a, const modInt &b) {
    return modInt(a.x - b.x);
  }

  friend modInt operator*(const modInt &a, const modInt &b) {
    return modInt((ll) a.x * b.x);
  }

  friend modInt operator/(modInt a, modInt b) {
    int p = MOD - 2;
    while (p > 0) {
      if (p % 2) {
        a = a * b;
      }
      b = b * b;
      p /= 2;
    }
    return a;
  }

  modInt &operator+=(const modInt &b) {
    return *this = *this + b;
  }

  modInt &operator-=(const modInt &b) {
    return *this = *this - b;
  }

  modInt &operator*=(const modInt &b) {
    return *this = *this * b;
  }

  modInt &operator/=(const modInt &b) {
    return *this = *this / b;
  }

  bool operator<(const modInt &other) const {
    return x < other.x;
  }

  bool operator>(const modInt &other) const {
    return x > other.x;
  }

  bool operator<=(const modInt &other) const {
    return x <= other.x;
  }

  bool operator>=(const modInt &other) const {
    return x >= other.x;
  }

  bool operator==(const modInt &other) const {
    return x == other.x;
  }

  bool operator!=(const modInt &other) const {
    return x != other.x;
  }
};

template<int MOD>
ostream &operator<<(ostream &out, modInt<MOD> const &x) {
  out << x.x;
  return out;
}

template<int MOD>
istream &operator>>(istream &in, modInt<MOD> &x) {
  x = 0;
  int c;
  while (isdigit(c = in.get())) {
    x *= 10;
    x += c - '0';
  }
  return in;
}

using mint = modInt<1'000'000'007>;

int inv[N];
cd w[N];

void init() {
  for (int i = 0; i < N; i++) {
    ld ang = 2 * PI * i / N;
    w[i] = cd(cos(ang), sin(ang));
  }
  for (int i = 1; i < N; i++) {
    inv[i] = (inv[i >> 1] >> 1) | ((i & 1) << (LOG - 1));
  }
}

void fft(vector<cd> &a) {
  int n = (int) a.size();
  for (int i = 0; i < n; i++) {
    if (i < inv[i]) {
      swap(a[i], a[inv[i]]);
    }
  }
  for (int lvl = 0; lvl < LOG; lvl++) {
    int len = 1 << lvl;
    for (int i = 0; i < n; i += 2 * len) {
      for (int j = 0; j < len; j++) {
        cd x = a[i + j], y = a[i + j + len] * w[j << (LOG - lvl - 1)];
        a[i + j] = x + y;
        a[i + j + len] = x - y;
      }
    }
  }
}

vector<mint> mult(vector<ll> a, vector<ll> b, int k) {
  vector<cd> A(N), B(N);
  copy(a.begin(), a.end(), A.begin());
  copy(b.begin(), b.end(), B.begin());
  fft(A);
  fft(B);
  for (int i = 0; i < N; i++) {
    A[i] *= B[i];
  }
  fft(A);
  reverse(A.begin() + 1, A.end());
  vector<mint> res(k);
  for (int i = 0; i < N; i++) {
    res[i % k] += (ll)floor(A[i].real() / N + 0.5);
  }
  return res;
}

int n, m, k;
vector<int> a;

void gen() {
  n = 3;//rand() % 5 + 1;
  m = 2;//rand() % 5 + 1;
  k = rand() % 5 + 1;
  a.resize(n);
  for (int &e : a) {
    e = rand() % 5 + 1;
  }
}

void read() {
  cin >> n >> m >> k;
  a.resize(n);
  for (int &e : a) {
    cin >> e;
  }
}

mint slow_solve() {
  ll ans = 0;
  ll sum = accumulate(a.begin(), a.end(), 0ll) * m % k;
  for (int l = 0; l < n * m; l++) {
    ll cur = 0;
    for (int r = l; r < n * m; r++) {
      cur += a[r % n];
      if (cur % k == 0) {
        ans++;
      }
      if ((sum - cur % k + k) % k == 0 && (l != 0 && r != n * m - 1)) {
        ans++;
      }
    }
  }
  return ans;
}

mint solve() {
  vector<mint> cnt(k);
  cnt[0] = 1;
  ll sum = accumulate(a.begin(), a.end(), 0ll) % k;
  ll pref = 0;
  mint ans = 0;
  for (int i = 0; i < n; i++) {
    pref = (pref + a[i]) % k;
    ans += cnt[pref];
    cnt[pref] += 1;
  }
  if (m == 1) {
    pref = 0;
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < n - 1; i++) {
      pref = (pref + a[i]) % k;
      ans += cnt[(pref - sum % k + k) % k];
      cnt[pref] += 1;
    }
  } else {
    ans *= m;
    vector<ll> polyPref(k), polySuff(k);
    ll curPref = 0, curSuff = 0;
    for (int i = 0; i < n; i++) {
      curPref = (curPref + a[i]) % k;
      if (i != n - 1) {
        polyPref[curPref]++;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      curSuff = (curSuff + a[i]) % k;
      if (i != 0) {
        polySuff[curSuff]++;
      }
    }
    auto res0 = mult(polyPref, polySuff, k);
    vector<ll> empty(N); empty[0] = 1;
    auto resLeft = polySuff;
    auto resRight = polyPref;
    for (int t = 0; t <= m - 2; t++) {
      ll curSum = sum * t % k;
      ans += (res0[(k - curSum) % k]) * m;
      ans += (resLeft[(k - (curSum + sum) % k) % k]) * m;
      ans += (resRight[(k - (curSum + sum) % k) % k]) * m;
    }
    for (int t = 2; t <= m - 1; t++) {
      if (sum * t % k == 0) {
        ans += m;
      }
    }
    if (sum * m % k == 0) {
      ans += 1;
    }
    pref = 0;
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < n - 1; i++) {
      pref = (pref + a[i]) % k;
      ans += cnt[(pref % k - sum * m % k + k) % k] * m;
      cnt[pref] += 1;
    }
  }
  return ans;
}

void stress() {
  while (true) {
    gen();
    auto A = solve();
    auto B = slow_solve();
    if (A != B) {
      cout << n << " " << m << " " << k << endl;
      for (int &e : a) {
        cout << e << " ";
      }
      cout << endl;
      cout << A << " " << B << endl;
      exit(0);
    }
    cout << "YES" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
//  stress();
  read();
  cout << solve() << endl;
  return 0;
}