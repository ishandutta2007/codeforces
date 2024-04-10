%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 1000005;
long long a[N];
int n;
long long k;
 
bool check(ll mid) {
  ll cnt = 0;
  for (int i = (n + 1) / 2; i <= n; i++) {
    if (a[i] > mid) break;
    else {
      cnt += mid - a[i];
      //printf("cnt %lld\n", cnt);
      if (cnt > k) return 1;
    }
  } 
  return 0;
}
 
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  } 
  sort(a + 1, a + n + 1);
  
  long long l = 1, r = 1e16;
  long long ans;
 
  while (l < r) {
    //printf("%lld %lld\n", l, r);
    
    long long mid = (l + r) >> 1;
    //printf("mid %lld\n", mid);
  
    if (check(mid)) r = mid;
    else l = mid + 1, ans = mid;
  }
  printf("%d\n", ans);
  return 0;
}