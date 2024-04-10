#include <cstdio>
#include <cstring>

long long gcdex (long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
      x = 0; y = 1;
      return b;
    }
    long long x1, y1;
    long long d = gcdex(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int m;

long long h1, a1, x1, y1;
long long h2, a2, x2, y2;
long long di[1 << 20];

int params(long long h, long long a, long long x, long long y,
    long long &s, long long &l, long long &c) {

  memset(di, -1, sizeof(di));
  long long k = h;
  long long cd = 0;
  while (di[k] == -1) {
    di[k] = cd++;

    //printf("DI %lld %lld %lld\n", k, di[k], cd);
    k = k * x + y;
    if (k >= m) {
      k %= m;
    }
  }
  l = di[a] - di[k];
  s = di[k];
  c = cd - di[k];

  if (di[a] == -1) {
    return false;
  }
  if (di[a] < di[k]) {
    return false;
  }

  return true;
}

void bf(int lim) {
  //printf("BF!\n");
  for (int i = 0; i <= lim * 2; ++i) {
    if (h1 == a1 && h2 == a2) {
      printf("%d\n", i);
      return;
    }
    h1 = (h1 * x1 + y1) % m;
    h2 = (h2 * x2 + y2) % m;
  }
  printf("-1\n");
}

int main() {
  scanf("%d", &m);
  scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);
  scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);

  long long s1, l1, c1;
  long long s2, l2, c2;

  if (!params(h1, a1, x1, y1, s1, l1, c1)) {
    bf(s1);
    return 0;
  }
  if (!params(h2, a2, x2, y2, s2, l2, c2)) {
    bf(s2);
    return 0;
  }

  // printf("Params %lld %lld %lld ; %lld %lld %lld\n", s1, l1, c1, s2, l2, c2);

  long long x, y;
  long long d = gcdex(c1, c2, x, y);

  long long t1, t2;
  t1 = l1 + s1;
  t2 = l2 + s2;
  if ((t1 - t2) % d != 0) {
    printf("-1\n");
    return 0;
  }

  long long rm = t1 % d;
  t1 /= d;
  t2 /= d;
  c1 /= d;
  c2 /= d;

  gcdex(c1, c2, x, y);
  long long k = t2 * x * c1 + t1 * y * c2;
  // printf("%lld %lld %lld %lld\n", d, k, c1 * c2, k * d + rm);
  if (k >= c1 * c2) {
    k %= (c1 * c2);
  }
  while (k * d + rm < s1 || k * d + rm < s2) {
    k = k + c1 * c2;
  }
  k = k * d + rm;
  printf("%lld\n", k);

  return 0;
}