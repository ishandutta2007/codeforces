%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128


const int N = 5000005;
const int mod = 1e9 + 7;
int a[N], n;
long long dp[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    vector <int> p;
    for (int j = 1, sq = (int)sqrt(a[i]); j <= sq; j++) {
      if (a[i] % j != 0) continue;
      p.push_back(j);
      if (j != a[i] / j) p.push_back(a[i] / j);
    }
    vector <int> q;
    int len = p.size();
    if (len & 1) {
      for (int j = 0; j < len - 1; j += 2) {
        q.push_back(p[j]);
      }
      q.push_back(p[len - 1]);
      for (int j = len - 2; j >= 1; j -= 2) {
        q.push_back(p[j]);
      }
    }
    else {
      for (int j = 0; j < len; j += 2) {
        q.push_back(p[j]);
      }
      for (int j = len - 1; j >= 1; j -= 2) {
        q.push_back(p[j]);
      }
    }
    
    for (int j = len - 1; j >= 0; j--) {
      int v = q[j];
      dp[v] = (dp[v] + dp[v - 1]) % mod;
    }
  }
  
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[i]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}