#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define lll __int128
#define pii pair <int, int>

const int N = 105;
const int mod = 998244353;

char s[N];
int d[N], n;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

//  
map <pii, long long> dp[2][2][11][11];
int tot1[15], tot2[15];

template <typename T>
void add(T &a, T b) {
  a += b;
  if (a >= mod) a -= mod; 
}

long long solve(int x, int y) {
  memset(dp, 0, sizeof(dp));
  memset(tot1, 0, sizeof(tot1));
  memset(tot2, 0, sizeof(tot2));
  
  for (int i = 1; i * y < 10; i++) { // y > x
    tot1[i * x] = 1 << (i - 1);
    tot2[i * y] = 1 << (i - 1);
    //printf("tot1[%d] = %d\n", i, 1 << (i - 1));
  }
  
  // init_dp
  int c = 0, b = 1;
  for (int depth = 0; depth < 2; depth++) {
    for (int l = 0; l < 10; l++) {
      for (int r = 0; r < 10; r++) {
        dp[c][depth][l][r].clear();
      }
    }
  }
  
  dp[c][0][0][0][{0, 0}] = 1;
  for (int i = 0; i < n; i++) {
    swap(b, c);
    // init_dp
    for (int depth = 0; depth < 2; depth++) {
      for (int l = 0; l < 10; l++) {
        for (int r = 0; r < 10; r++) {
          dp[c][depth][l][r].clear();
        }
      }
    }
    
    for (int depth = 0; depth < 2; depth++) {
      for (int l = 0; l < 10; l++) {
        for (int r = 0; r < 10; r++) {
          for (auto u: dp[b][depth][l][r]) {
            long long now = u.second;
            if (now == 0) continue;
            pii fi = u.first;
            int fa = fi.first, fb = fi.second;
            
            for (int k = 0; k < 10; k++) {
              int l0 = l + x * k, r0 = r + y * k;
              int dl = l0 % 10, dr = r0 % 10;
              
              l0 /= 10, r0 /= 10;
              int more;
              if (dr > d[i]) more = 1;
              else if (dr == d[i]) more = depth;
              else more = 0;
              add(dp[c][more][l0][r0][{fa | tot1[dl], fb | tot2[dr]}], now);
              //printf("dp[%d][%d][%d][%d][%d][%d] = %d\n", c, more, l0, r0, fa | tot1[dl], fb | tot2[dr], dp[c][more][l0][r0][{fa | tot1[dl], fb | tot2[dr]}]);
            }
          }
        }
      }
    }
  }
  //system("pause");
  
  long long ans = 0LL;
  for (auto u: dp[c][0][0][0]) {
    pii f = u.first;
    if (f.first & f.second)
      add(ans, u.second);
  }
  return ans;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++)
    d[n - 1 - i] = s[i] - '0';
  d[n] = 0;
  
  //printf("qwq !\n");

  long long ans = 0LL;
  for (int x = 1; x <= 9; x++) {
    for (int y = x + 1; y <= 9; y++) {
      if (gcd(x, y) != 1) continue;
      //printf("do %d %d\n", x, y);
      ans = (ans + 2 * solve(x, y)) % mod; // (x, y) & (y, x)
      //printf("%d\n", ans);
    }
  }
  ans = (ans + solve(1, 1)) % mod;
  printf("%lld\n", ans);
  return 0;
}