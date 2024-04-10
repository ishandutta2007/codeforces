#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000 + 7;
int n;
int k;
int a[N];
vector<int> b;
vector<int> r;
vector<int> c;

typedef long long ll;
const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

int pw(int a, int b) {
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

int modular_inverse(int a) {
  return pw(a, mod - 2);
}

int inverse(int x, int lg_n) {
  int y = 0;
  for (int i = 0; i < lg_n; i++) {
    if (x & (1 << i)) {
      y ^= (1 << (lg_n - 1 - i));
    }
  }
  return y;
}

void fft(vector<int> &a, bool inv) {
  int n = (int) a.size(), lg_n = log2(n);
  for (int i = 0; i < n; i++) {
    int j = inverse(i, lg_n);
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (int len = 2; len <= n; len *= 2) {
    //double ang = 2 * PI / len * (inv ? -1 : 1);
    //cd mul(cos(ang), sin(ang));
    int mul = inv ? root_1 : root;
    for (int j = len; j < root_pw; j *= 2) {
      mul = (ll) mul * mul % mod;
    }
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; j++) {
        int x = a[i + j], y = (ll) a[i + len / 2 + j] * w % mod;
        a[i + j] = x + y;
        a[i + len / 2 + j] = x - y;
        if (a[i + j] >= mod) {
          a[i + j] -= mod;
        }
        if (a[i + len / 2 + j] < 0) {
          a[i + len / 2 + j] += mod;
        }
        w = (ll) w * mul % mod;
      }
    }
  }
  if (inv) {
    int x = modular_inverse(n);
    for (int i = 0; i < n; i++) {
      a[i] = (ll) a[i] * x % mod;
    }
  }
}

vector<int> multiply(vector<int> a, vector<int> b) {
  int n = 1;
  while (n < (int) a.size() + (int) b.size()) {
    n *= 2;
  }
  a.resize(n);
  b.resize(n);
  fft(a, 0);
  fft(b, 0);
  for (int i = 0; i < n; i++) {
    a[i] = (ll) a[i] * b[i] % mod;
  }
  fft(a, 1);
  for (int i = 0; i < n; i++) {
    a[i] = !!a[i];
  }
  while (!a.empty() && a.back() == 0) {
    a.pop_back();
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  b.push_back(1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    while (!(a[i] < (int) r.size())) {
      r.push_back(0);
    }
    r[a[i]] = 1;
  }
  while (k) {
    if (k & 1) { /// b = mul(b, r)
      b = multiply(b, r);
    }
    k /= 2;
    if (k) { /// r = mul(r, r)
      r = multiply(r, r);
    }
  }
  for (int i = 0; i < (int) b.size(); i++) {
    if (b[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}