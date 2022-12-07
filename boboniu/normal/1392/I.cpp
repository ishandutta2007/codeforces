#include <bits/stdc++.h>
using namespace std;
#define maxN 2222222
#define P 998244353

int n, m, q;
int a[maxN], b[maxN];
const int L = 18, N = (1 << L);

struct comp {
  double x, y;

  comp() : x(0), y(0) {}
  comp(const double &_x, const double &_y) : x(_x), y(_y) {}
};

inline comp operator+(const comp &a, const comp &b) {
  return comp(a.x + b.x, a.y + b.y);
}
inline comp operator-(const comp &a, const comp &b) {
  return comp(a.x - b.x, a.y - b.y);
}
inline comp operator*(const comp &a, const comp &b) {
  return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
inline comp conj(const comp &a) { return comp(a.x, -a.y); }

const double PI = acos(-1);

comp w[N + 5];
int bitrev[N + 5];

#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long
void fft(comp *a, const int &n) {
  rep(i, 0, n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
  for (int i = 2, lyc = n >> 1; i <= n; i <<= 1, lyc >>= 1)
    for (int j = 0; j < n; j += i) {
      comp *l = a + j, *r = a + j + (i >> 1), *p = w;
      rep(k, 0, i >> 1) {
        comp tmp = *r * *p;
        *r = *l - tmp, *l = *l + tmp;
        ++l, ++r, p += lyc;
      }
    }
}

inline void fft_prepare() {
  rep(i, 0, N) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
  rep(i, 0, N) w[i] = comp(cos(2 * PI * i / N), sin(2 * PI * i / N));
}

void conv(int *x, int *y, ll *z, int K) {
  static comp a[N + 5], b[N + 5];
  static comp dfta[N + 5], dftb[N + 5], dftc[N + 5], dftd[N + 5];

  rep(i, 0, K + 1) a[i] = comp(x[i] & 32767, x[i] >> 15);
  rep(i, 0, K + 1) b[i] = comp(y[i] & 32767, y[i] >> 15);
  rep(i, K + 1, N) a[i] = b[i] = comp(0, 0);
  fft(a, N), fft(b, N);
  rep(i, 0, N) {
    int j = (N - i) & (N - 1);
    static comp da, db, dc, dd;
    da = (a[i] + conj(a[j])) * comp(0.5, 0);
    db = (a[i] - conj(a[j])) * comp(0, -0.5);
    dc = (b[i] + conj(b[j])) * comp(0.5, 0);
    dd = (b[i] - conj(b[j])) * comp(0, -0.5);
    dfta[j] = da * dc;
    dftb[j] = da * dd;
    dftc[j] = db * dc;
    dftd[j] = db * dd;
  }
  rep(i, 0, N) a[i] = dfta[i] + dftb[i] * comp(0, 1);
  rep(i, 0, N) b[i] = dftc[i] + dftd[i] * comp(0, 1);
  fft(a, N), fft(b, N);
  rep(i, 0, N) {
    int da = (ll)(a[i].x / N + 0.5);
    int db = (ll)(a[i].y / N + 0.5);
    int dc = (ll)(b[i].x / N + 0.5);
    int dd = (ll)(b[i].y / N + 0.5);
    z[i] = (da + ((ll)(db + dc) << 15) + ((ll)dd << 30));
  }
}

int f1[N + 1], f2[N + 1];
long long f3[N + 1];
vector<ll> convo(vector<int> a, vector<int> b) {
  memset(f1, 0, sizeof(f1));
  memset(f2, 0, sizeof(f2));
  for (auto x : a)
    f1[x] += 1;
  for (auto x : b)
    f2[x] += 1;
  conv(f1, f2, f3, 100000);
  return vector<ll>(f3, f3 + 200001);
}
vector<int> p1, p2, p3, p4;
int64_t c[maxN];
int main() {
  fft_prepare();
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < m; i++)
    scanf("%d", &b[i]);
  for (int i = 0; i < n - 1; i++) {
    p1.push_back(min(a[i], a[i + 1]));
    p2.push_back(max(a[i], a[i + 1]));
  }
  for (int i = 0; i < m - 1; i++) {
    p3.push_back(min(b[i], b[i + 1]));
    p4.push_back(max(b[i], b[i + 1]));
  }
  auto c1 = convo(p1, p3);
  auto c2 = convo(p2, p3);
  auto c3 = convo(p1, p4);
  auto c4 = convo(p2, p4);
  for (int i = 0; i <= 200000; i++) {
    c[i] = c1[i] - c2[i] - c3[i] + c4[i];
    if (i > 0)
      c[i] += c[i - 1];
  }
  int th = *min_element(a, a + n) + *max_element(b, b + m);
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    long long ans = c[x - 1];
    int bc = 0;
    if (th < x)
      bc = 0;
    else
      bc = 1;
    if (bc)
      ans -= 2;
    else
      ans += 2;
    for (auto i : {0, n - 1})
      for (auto j : {0, m - 1}) {
        int pc = a[i] + b[j] >= x;
        if (pc != bc) {
          if (pc == 0)
            ans += 1;
          else
            ans -= 1;
        }
      }
    printf("%lld\n", -ans / 2);
  }
}