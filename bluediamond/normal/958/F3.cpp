#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

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


using cd = complex<double>;

int getInverse(int x, int k) {
  int y = 0;
  for (int j = 0; j < k; j++) {
    if (x & (1 << j)) y += (1 << (k - 1 - j));
  }
  return y;
}

void fft(vector<cd> &a, bool inv) {
  int n = (int) a.size(), k = 0;
  while ((1 << k) < n) k++;
  assert((1 << k) == n);
  for (int i = 0; i < n; i++) {
    int j = getInverse(i, k);
    if (j < i) swap(a[i], a[j]);
  }
  for (int l = 2; l <= n; l *= 2) {
    double ang = 4.0 * acos(0.0) / (double) l * (inv ? -1 : 1);
    cd mult(cos(ang), sin(ang));
    for (int i = 0; i < n; i += l) {
      cd now(1);
      for (int j = 0; j < l / 2; j++) {
        cd x = a[i + j];
        cd y = now * a[i + j + l / 2];
        now *= mult;
        a[i + j] = x + y;
        a[i + j + l / 2] = x - y;
      }
    }
  }
  if (inv) {
    for (int i = 0; i < n; i++) {
      a[i] /= n;
    }
  }
}

struct T {
  vector<int> v;
};

bool operator < (T a, T b) {
  return (int) a.v.size() > (int) b.v.size();
}

const int N = (int) 2e5 + 7;
int n, m, k, f[N];
priority_queue<T> q;


signed realMain() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    f[x]++;
  }
  for (int i = 1; i <= m; i++) {
    if (f[i]) {
      vector<int> vec((int) f[i] + 1, 1);
      q.push({vec});
    }
  }
  while ((int) q.size() > 1) {
    auto a = q.top().v;
    q.pop();
    auto b = q.top().v;
    q.pop();
    int sum = (int) a.size() + (int) b.size(), n = 1;
    while (n <= sum) {
      n *= 2;
    }
    a.resize(n);
    b.resize(n);
    vector<cd> x(a.begin(), a.end()), y(b.begin(), b.end());
    fft(x, 0);
    fft(y, 0);
    for (int i = 0; i < n; i++) x[i] *= y[i];
    fft(x, 1);
    for (int i = 0; i < n; i++) a[i] = round(real(x[i])), a[i] %= 1009;
    while (a.back() == 0) {
      a.pop_back();
    }
    q.push({a});
  }
  cout << q.top().v[k] << "\n";
  return 0;
}