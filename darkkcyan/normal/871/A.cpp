#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 1111
int ans[maxn];

bool isprime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ans[0] = ans[1] = ans[2] = ans[3] = -1;
  for (int i = 4; i < maxn; ++i) {
    ans[i] = isprime(i) ? -1 : 1;
    for (int f = 4; f < i; ++f) {
      if (isprime(f) or ans[i - f] == -1) continue;
      ans[i] = max(ans[i], ans[i - f] + 1);
    }
  }
  
  int q; cin >> q;
  while (q--) {
    llong n; cin >> n;
    llong c4 = n / 4, r = n % 4;
    llong res = (r == 0 ? c4 : -1);
    
    while (true) {
      r += 4;
      --c4;
      if (r >= maxn or r > n) break;
      if (ans[r] != -1) res = max(res, ans[r] + c4);
    }
    cout << res << '\n';
  }
  
  return 0;
}