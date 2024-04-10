#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BR putchar('\n')
#define MS0(ar) memset(ar, 0, sizeof(ar))
#define MS1(ar) memset(ar, -1, sizeof(ar))
#define F first
#define S second
#define MP make_pair
#define MT make_tuple
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef complex<double> CD;

void R(int &x) { scanf("%d", &x); }
void R(LL &x) { scanf("%lld", &x); }
void R(ULL &x) { scanf("%llu", &x); }
void R(double &x) { scanf("%lf", &x); }
void R(LD &x) { scanf("%Lf", &x); }

template <typename T> void R(T &t) { cin >> t; }
template <typename T> void R(vector<T> &ar) {
  for (auto &it : ar)
    R(it);
}

template <typename T, typename... Args> void R(T &t, Args &... args) {
  R(t);
  R(args...);
}

void W(const char &c) { putchar(c); };
void W(const int &x) { printf("%d", x); }
void W(const LL &x) { printf("%lld", x); }
void W(const ULL &x) { printf("%llu", x); }
void W(const double &x) { printf("%lf", x); }
void W(const LD &x) { printf("%Lf", x); }

template <typename T> void W(const T &t) { cout << t; }
template <typename T> void W(const vector<T> &ar) {
  for (size_t i = 0; i < ar.size(); ++i) {
    W(ar[i]);
    putchar(" \n"[i + 1u == ar.size()]);
  }
}
template <typename T, typename... Args>
void W(const T &t, const Args &... args) {
  W(t);
  W(args...);
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;


int n;

int aa[] = {3, 1, 3, 10};
int bb[] = {1, 5, 10, 999};
int count(int *r, int *b) {
  return r[0] <= b[0] && r[1] <= b[1] && r[2] >= b[2] && r[3] >= b[3];
}

int query(int a, int b, int c, int d) {
  printf("? %d %d %d %d\n", a, b, c, d);
  fflush(stdout);
  int res;
  ///int box[] = {a, b, c, d};
  // res = count(box, aa) + count(box, bb);
  scanf("%d", &res);
  return res;
}

int g(int dim, int t) {
  int a[] = {1, 1, n, n};
  int l = 1, r = n, ret = r;
  while (l <= r) {
    int m = (l + r) >> 1;
    a[dim] = m;
    int res = query(a[0], a[1], a[2], a[3]);
    if (res >= t) {
      ret = m;
      if (dim >= 2) r = m - 1;
      else l = m + 1;
    }
    else {
      if (dim < 2) r = m - 1;
      else l = m + 1;
    }
  }
  return ret;
}

bool vis[4][4][4][4] = {};
void gg(int *x, int *y, int a, int b, int c, int d) {
  if (vis[a][b][c][d])
    return ;
  if (a >= 2 || b >= 2 || c < 2 || d < 2) return ;
  vis[a][b][c][d] = true;
  if (a + 1 < c) {
    gg(x, y, a + 1, b, c, d);
    gg(x, y, a, b, c - 1, d);
  }
  if (b + 1 < d) {
    gg(x, y, a, b + 1, c, d);
    gg(x, y, a, b, c, d - 1);
  }
  if (x[a] > x[c] || y[b] > y[d]) return ;
  if (query(x[a], y[b], x[c], y[d]) == 1) {
    printf("! %d %d %d %d", x[a], y[b], x[c], y[d]);
    vector<int> aa, bb;
    REP(i, 4) if (i != a && i != c) aa.PB(x[i]);
    REP(i, 4) if (i != b && i != d) bb.PB(y[i]);
    printf(" %d %d %d %d\n", aa[0], bb[0], aa[1], bb[1]);
    exit(0);
  }
}

int main() {
  scanf("%d", &n);
  int x[4] = { g(0, 2), g(0, 1), g(2, 1), g(2, 2) };
  int y[4] = { g(1, 2), g(1, 1), g(3, 1), g(3, 2) };
  gg(x, y, 0, 0, 3, 3);

  return 0;
}