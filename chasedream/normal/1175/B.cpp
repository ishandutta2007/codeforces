%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 300005;
const ll flow = (1LL << 32) - 1; 

stack <ll> s;
long long ans = 0LL;
int n;

int main() {
  scanf("%d", &n);
  s.push(1);
  for (int i = 1; i <= n; i++) {
    string str; cin >> str;
    if (str == "for") {
      int x; scanf("%d", &x);
      s.push(min(flow + 1, (ll)x * s.top()));
    }
    else if (str == "add") {
      ans += s.top();
    }
    else {
      s.pop();
    }
    if (ans > flow) {
      puts("OVERFLOW!!!");
      exit(0);
    }
  }
  printf("%lld\n", ans);
  return 0;
}