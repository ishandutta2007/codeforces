#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int B = 31;
const int BINV = dv(1, B);
const int P = 22;

void fft(vector<int> &a, bool inv) {
  int n = (int) a.size(), k = log2(n);
  for (int i = 0; i < n; i++) {
    int j = 0, dif = 0;
    for (int b = 0; b < k; b++) {
      if (i & (1 << b)) {
        j += (1 << (k - 1 - b));
        dif += (1 << b);
      }
    }
    assert(dif == i);
   /// cout << " : " << i << " and " << j << "\n";
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (int l = 2; l <= n; l *= 2) {
    int mult = inv ? BINV : B;
    for (int j = l; j <= (1 << P); j *= 2) {
      mult = mul(mult, mult);
    }
    for (int i = 0; i < n; i += l) {
      int cur = 1;
      for (int j = 0; j < l / 2; j++) {
        int x = a[i + j], y = mul(cur, a[i + l / 2 + j]);
        a[i + j] = add(x, y);
        a[i + l / 2 + j] = add(x, -y);
        cur = mul(cur, mult);
      }
    }
  }
  if (inv) {
    int invn = dv(1, n);
    for (auto &x : a) {
      x = mul(x, invn);
    }
  }
}

vector<int> mult(vector<int> a, vector<int> b) {
  int n = 1;
  while (n < (int) a.size() + (int) b.size()) {
    n *= 2;
  }
  a.resize(n);
  b.resize(n);
  fft(a, 0);
  fft(b, 0);
  for (int i = 0; i < n; i++) {
    a[i] = mul(a[i], b[i]);
  }
  fft(a, 1);
  return a;
}

struct T {
  vector<int> v;
};

bool operator < (T a, T b) {
  return (int) a.v.size() > (int) b.v.size();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  int n;
  map<int, int> fr;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    fr[x]++;
  }
  vector<int> cnt;
  for (auto &it : fr) cnt.push_back(it.second);
  priority_queue<T> pq;
  for (auto &x : cnt) {
    vector<int> lol(x + 1, 1);
    pq.push({lol});
  }
  while ((int) pq.size() > 1) {
    vector<int> v1 = pq.top().v; pq.pop();
    vector<int> v2 = pq.top().v; pq.pop();
    pq.push({mult(v1, v2)});
  }
  int ret = 0;
  auto vec = pq.top().v;
  pq.pop();
  cout << vec[n / 2] << "\n";
}