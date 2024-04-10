// zzfy003
%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

ull seed1, seed2;
void randomize(ull fake1, ull fake2) {
  seed1 = fake1 + fake2;
  seed2 = fake1 * fake2 % 2030602527;
}

unsigned long long random() {
  seed1 ^= seed2 << 12;
  seed2 ^= seed1 >> 9;
  seed1 ^= seed2 << 6;
  seed2 ^= seed1 >> 3;
  seed2 ^= seed1 << 12;
  seed1 =  ~seed1;
  seed2 =  ~seed2;
  swap(seed1, seed2);
  return seed1;
}

const int N = 1000005;
ll a[N], g[N], b[N], cnt[N];
int n, half;
ll ans;


ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

void SA() {
  ll tmp = a[(int)(random() % n)+ 1];
  for (int i = 1; i <= n; i++) {
    g[i] = gcd(a[i], tmp);
  }
  sort(g + 1, g + n + 1);
  
  int m = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i] != g[i - 1]) {
      b[++m] = g[i];
      cnt[m] = 1;
    }
    else cnt[m]++;
  }
  
  ll sum = 0, res = -1;
  for (int i = 1; i <= m; i++) {
    sum = 0;
    for (int j = 1; j <= m; j++) {
      if (b[j] % b[i] == 0) sum += cnt[j]; 
    }
    if (sum >= half)
      res = b[i];
  }
  ans = max(ans, res);
}

int main() {
  randomize(time(0), time(0));
  scanf("%d", &n);
  a[0] = -1; half = (n + 1) >> 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  
  for (int i = 1; i <= 50; i++) {
    if (clock() > 3800) break;
    SA();
  }
  printf("%lld\n", ans);
  return 0;
}