#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

typedef long long ll;

const int M = 998244353;
const int FACTN = 300000 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M)return a - M;
  if (a < 0)return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % M;
}

int add(int a, int b, int c) {
  return add(add(a, b), c);
}

int mul(int a, int b, int c) {
  return mul(mul(a, b), c);
}

int add(int a, int b, int c, int d) {
  return add(add(a, b, c), d);
}

int mul(int a, int b, int c, int d) {
  return mul(mul(a, b, c), d);
}

int add(int a, int b, int c, int d, int e) {
  return add(add(a, b, c, d), e);
}

int mul(int a, int b, int c, int d, int e) {
  return mul(mul(a, b, c, d), e);
}

int add(int a, int b, int c, int d, int e, int f) {
  return add(add(a, b, c, d, e), f);
}

int mul(int a, int b, int c, int d, int e, int f) {
  return mul(mul(a, b, c, d, e), f);
}

int add(int a, int b, int c, int d, int e, int f, int g) {
  return add(add(a, b, c, d, e, f), g);
}

int mul(int a, int b, int c, int d, int e, int f, int g) {
  return mul(mul(a, b, c, d, e, f), g);
}

int add(int a, int b, int c, int d, int e, int f, int g, int h) {
  return add(add(a, b, c, d, e, f, g), h);
}

int mul(int a, int b, int c, int d, int e, int f, int g, int h) {
  return mul(mul(a, b, c, d, e, f, g), h);
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1)r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

void dvup(int& a, int b) {
  a = dv(a, b);
}

int fact[FACTN], ifact[FACTN];

void computeFACT() {
  fact[0] = 1;
  for (int i = 1; i < FACTN; i++)fact[i] = mul(fact[i - 1], i);
  ifact[FACTN - 1] = dv(1, fact[FACTN - 1]);
  for (int i = FACTN - 2; i >= 0; i--)ifact[i] = mul(ifact[i + 1], i + 1);
}

int getCOMB(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int comb(int n, int k) {
  assert(0 <= k && k <= n && n < FACTN);
  return getCOMB(n, k);
}

const int P = 31;
const int IP = dv(1, P);
const int L = 1 << 23;

void fft(vector<int>& a, int k, bool inv) {
  int n = (1 << k);
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (int bit = 0; bit < k; bit++) {
      if (i & (1 << bit)) {
        j += (1 << (k - 1 - bit));
      }
    }
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (int l = 2; l <= n; l *= 2) {
    int mlt = ((inv) ? (IP) : (P));
    for (int j = l; j < L; j *= 2)mlt = mlt * (ll)mlt % M;
    for (int i = 0; i < n; i += l) {
      int cur = 1;
      for (int j = 0; j < l / 2; j++) {
        int x = a[i + j];
        int y = a[i + l / 2 + j];
        y = y * (ll)cur % M;
        cur = cur * (ll)mlt % M;
        a[i + j] = x + y;
        if (a[i + j] >= M)a[i + j] -= M;
        a[i + l / 2 + j] = x - y;
        if (a[i + l / 2 + j] < 0)a[i + l / 2 + j] += M;
      }
    }
  }
  if (inv) {
    int mlt = dv(1, n);
    for (auto& x : a)x = x * (ll)mlt % M;
  }
}

vector<int>conv_smart(vector<int>a, vector<int>b) {
  int k = 0;
  while ((1 << k) < (int)a.size() + (int)b.size())k++;
  a.resize((1 << k), 0);
  b.resize((1 << k), 0);
  fft(a, k, 0);
  fft(b, k, 0);
  for (int i = 0; i < (1 << k); i++)a[i] = a[i] * (ll)b[i] % M;
  fft(a, k, 1);
  return a;
}

const int N = 1000 + 7;
int n;
int a[N];
int b[N];
int sum[N];
int dif[N];
int ways[N][5 * N];

int main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

  computeFACT();

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  dif[0] = 1;

  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (a[i] + b[i]);
    dif[i] = dif[i - 1] + (a[i] - b[i]);
  }

  ways[0][1] = 1;

  for (int iter = 1; iter <= n; iter++) {
    int init_size = dif[iter - 1];
    int after_size = dif[iter];


    vector<int> x(init_size + 1, 0);
    vector<int> y(init_size + after_size + 1, 0);
    
    for (int i = 1; i <= init_size; i++) {
      x[i] = ways[iter - 1][i];
    }
    for (int j2 = 1; j2 <= init_size + after_size; j2++) {
      if (init_size - b[iter] <= j2 && j2 <= init_size + a[iter]) {
        int j = j2 - init_size;
        if (b[iter] + j >= 0 && a[iter] - j >= 0) { 
          y[j2] = mul(ifact[b[iter] + j], ifact[a[iter] - j]);
        }
      }
    }

    vector<int> z = conv_smart(x, y);



    for (int pos = 0; pos < (int)z.size(); pos++) {
      int y = pos - init_size;
      if (1 <= y && y <= after_size) {
        ways[iter][y] = z[pos];
      }
    }
    for (int y = 1; y <= after_size; y++) {
      mulup(ways[iter][y], fact[a[iter] + b[iter]]);
    }
  }
  int sol = 0;
  for (int x = 1; x <= dif[n]; x++) {
    addup(sol, ways[n][x]);
  }
  cout << sol << "\n";

  exit(0);

  for (int i = 1; i <= n; i++) {
    cout << dif[i] << " ";
  }
  cout << "\n";


  return 0;
}