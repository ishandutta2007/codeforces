#include <cstdio>
#include <cstring>

const int mod = 1000000007;

int n, k;
char s[1 << 20];

long long ha[1 << 20];
long long hp[1 << 20];

int finok[1 << 20];

void init_hash() {
  ha[n] = 0;
  for (int i = n - 1; i >= 0; --i) {
    ha[i] = ha[i + 1] * 32 + s[i];
    if (ha[i] >= mod) {
      ha[i] %= mod;
    }
  }
  hp[0] = 1;
  for (int i = 1; i < (1 << 20); ++i) {
    hp[i] = hp[i - 1] * 32;
    if (hp[i] >= mod) {
      hp[i] %= mod;
    }
  }
}

// [le, ri)
long long get_hash(int le, int ri) {
  if (le == ri) {
    return -1;
  }
  long long sub = ha[ri] * hp[ri - le];
  if (sub >= mod) sub %= mod;
  long long sl = ha[le] - sub + mod;
  if (sl >= mod) sl %= mod;
  return sl;
}

int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  init_hash();
  memset(finok, -1, sizeof(finok));

  for (int i = 0; i < n; ++i) {
    if ((i + 1) % k != 0) {
      continue;
    }
    int j = (i + 1) / k;
    // printf("IJH %d %d %lld _ %lld\n", i, j, get_hash(0, i + 1 - j), get_hash(j, i + 1));
    if (get_hash(0, i + 1 - j) == get_hash(j, i + 1)) {
      // fprintf(stderr, "OK %d\n", i);
      // ok. get finok.
      finok[i] = i;
      int le, ri, mi;
      le = i; ri = i + j + 1;
      if (ri >= n) ri = n;
      while (le + 1 < ri) {
        mi = (le + ri) / 2;
        // printf("BS %d %d %d :: %lld %lld\n", le, ri, mi, get_hash(0, mi - i), get_hash(i + 1, mi + 1));
        if (get_hash(0, mi - i) == get_hash(i + 1, mi + 1)) {
          le = mi;
        } else {
          ri = mi;
        }
      }
      // printf("OK %d\n", le);
      finok[i] = le;
    }
  }

  int o = -1;
  for (int i = 0; i < n; ++i) {
    if (finok[i] > o) o = finok[i];
    if (o >= i)
      s[i] = '1';
    else
      s[i] = '0';
  }
  printf("%s\n", s);
  return 0;
}