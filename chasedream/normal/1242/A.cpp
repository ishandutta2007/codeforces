#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
vector <ll> rev;
long long n;

int main() {
  scanf("%lld", &n);
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      rev.push_back(i);
      while (n % i == 0)
        n /= i;
    }
  }
  if (n > 1) rev.push_back(n);
  sort(rev.begin(), rev.end());
  if (rev.size() == 1) printf("%lld\n", rev.front());
  else if (rev.empty()) printf("%lld\n", n);
  else puts("1");
}