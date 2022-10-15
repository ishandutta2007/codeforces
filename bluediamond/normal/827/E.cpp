#include <bits/stdc++.h>

using namespace std;

const double PI = 2.0 * acos(0.0);
using cd = complex<double>;

int lg(int x) {
  int ret = 0;
  while (x > 1) ret++, x /= 2;
  return ret;
}

int nxt(int x) {
  int n = 1;
  while (n < x) n *= 2;
  return n;
}

int get_inverse(int x, int lg) {
  int sol = 0;
  for (int i = 0; i < lg; i++) {
    if (x & (1 << i)) {
      sol += (1 << (lg - 1 - i));
    }
  }
  return sol;
}

void fft(vector<cd> &a, bool inv) {
  int n = (int) a.size(), k = lg(n);
  for (int i = 0; i < n; i++) {
    int j = get_inverse(i, k);
    if (j < i) {
      swap(a[i], a[j]);
    }
  }
  for (int len = 2; len <= n; len *= 2) {
    double ang = 2 * PI / len * (inv ? -1 : 1);
    cd mlt(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd x = a[i + j], y =w *  a[i + len / 2 + j];
        a[i + j] = x + y;
        a[i + len / 2 + j] = x - y;
        w *= mlt;
      }
    }
  }
  if (inv) {
    for (int i = 0; i < n; i++) a[i] /= n;
  }
}

vector<int> mul(vector<int> a, vector<int> b) {
  int k = nxt((int) a.size() + (int) b.size());
  a.resize(k, 0);
  b.resize(k, 0);
  vector<cd> x(a.begin(), a.end()), y(b.begin(), b.end());
  fft(x, 0);
  fft(y, 0);
  for (int i = 0; i < k; i++) x[i] *= y[i];
  fft(x, 1);
  for (int i = 0; i < k; i++) a[i] = round(real(x[i]));
  return a;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n;
    string s, dict = "VK";
    cin >> n >> s;
    vector<int> bad(n + 1, 0);
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) {
      a[i] = (s[i] == 'V');
      b[i] = (s[i] == 'K');
    }
    reverse(a.begin(), a.end());
    vector<int> c = mul(a, b);
    for (int sum = 0; sum < (int) c.size(); sum++) {
      int dif = sum - n + 1;
      dif = abs(dif);
      if (1 <= dif && dif <= n){
        bad[dif] += c[sum];
      }
    }
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
      bool ok = 1;
      for (int j = i; j <= n; j += i) {
        if (bad[j]) {
          ok = 0;
        }
      }
      if (ok) {
        ret.push_back(i);
      }
    }
    cout << (int) ret.size() << "\n";
    for (auto &i : ret) {
      cout << i << " ";
    }
    cout << "\n";
  }

}