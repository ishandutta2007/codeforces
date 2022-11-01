#include <cstdio>
#include <cassert>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 55555;

int mod_num;

struct Matrix2x2 {
  Matrix2x2(const Matrix2x2 &other) {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        mat[i][j] = other.mat[i][j];
  }
  Matrix2x2() {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        mat[i][j] = 0;
  }
  Matrix2x2(int p00, int p01, int p10, int p11) {
    mat[0][0] = p00;
    mat[0][1] = p01;
    mat[1][0] = p10;
    mat[1][1] = p11;
  }

  Matrix2x2 operator*(const Matrix2x2 &rhs) {
    Matrix2x2 ret;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          ret.mat[i][j] = ((long long)mat[i][k] * rhs.mat[k][j] + ret.mat[i][j]) % mod_num;
        }
      }
    return ret;
  }

  int mat[2][2];
} tree[MAXN << 2];
int n, orgm;
long long tar;
int s[MAXN];
pair<long long, int> diff[MAXN];

Matrix2x2 MatPowMod(Matrix2x2 x, long long t) {
  Matrix2x2 ret(1, 0, 0, 1);
  for ( ; t; t >>= 1) {
    if (t & 1) {
      ret = ret * x;
    }
    x = x * x;
  }
  return ret;
}

void BuildTree(int p, int l, int r) {
  if (l == r) {
    tree[p] = Matrix2x2(s[l % n], 1, s[l - 1], 0);
    return;
  }
  int mid = (l + r) / 2;
  BuildTree(p << 1, l, mid);
  BuildTree(p << 1 | 1, mid + 1, r);
  tree[p] = tree[p << 1] * tree[p << 1 | 1];
}

Matrix2x2 Query(int p, int l, int r, int tarl, int tarr) {
  if (tarl <= l && r <= tarr) return tree[p];
  Matrix2x2 ret(1, 0, 0, 1);
  int mid = (l + r) / 2;
  if (tarl <= mid) ret = ret * Query(p << 1, l, mid, tarl, tarr);
  if (tarr > mid) ret = ret * Query(p << 1 | 1, mid + 1, r, tarl, tarr);
  return ret;
}

void Init() {
  assert(scanf("%I64d%d", &tar, &mod_num) == 2);
  assert(scanf("%d", &n) == 1);
  for (int i = 0; i < n; ++i)
    assert(scanf("%d", s + i) == 1);
  assert(scanf("%d", &orgm) == 1);
  for (int i = 0; i < orgm; ++i)
    assert(scanf("%I64d%d", &diff[i].first, &diff[i].second) == 2);
  sort(diff, diff + orgm);

  BuildTree(1, 1, n);
}

Matrix2x2 MulNormal(Matrix2x2 org, long long l, long long r) {
  if (l >= r) return org;
  if (l / n != r / n) {
    if (l % n) {
      int tarl = (l + 1) % n;
      if (!tarl) tarl = n;
      org = org * Query(1, 1, n, tarl, n);
      l = (l / n + 1) * n;
    }
    long long t = (r - l) / n;
    org = org * MatPowMod(Query(1, 1, n, 1, n), t);
    l += t * n;
  }
  if (l != r) {
    int tarl = (l + 1) % n;
    if (!tarl) tarl = n;
    int tarr = r % n;
    assert(tarr);
    org = org * Query(1, 1, n, tarl, tarr);
  }
  return org;
}

void Work() {
  if (tar <= 1) {
    printf("%d\n", int(tar % mod_num)); 
    return;
  }
  Matrix2x2 now(1, 0, 0, 1);
  int m = orgm;
  while (m && diff[m - 1].first >= tar) --m;
  long long last = 0;
  for (int i = 0; i < m; ++i) {
    now = MulNormal(now, last, diff[i].first - 1);
    last = diff[i].first - 1;
    now = now * Matrix2x2(diff[i].second, 1, s[(diff[i].first - 1) % n], 0);
    ++last;
    while (i + 1 < m && diff[i + 1].first == diff[i].first + 1) {
      ++i;
      now = now * Matrix2x2(diff[i].second, 1, diff[i - 1].second, 0);
      ++last;
    }
    if (diff[i].first + 1 < tar) {
      now = now * Matrix2x2(s[(diff[i].first + 1) % n], 1, diff[i].second, 0);
      ++last;
      assert(last == diff[i].first + 1);
    }
  }
  now = MulNormal(now, last, tar - 1);
  printf("%d\n", now.mat[0][0]);
}

int main() {
  Init();
  Work();
  return 0;
}