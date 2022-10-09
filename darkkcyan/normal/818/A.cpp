#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n;)

llong n, k;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> k;
  llong l = 0, r = n;
  while (l < r) {
    llong mid = l + (r - l + 1) / 2;
    if (mid > (n * 1.0 / 2 / (k + 1))) r = mid - 1;
    else l = mid;
  }
  cout << l << ' ' << l * k << ' ' << (n - l - l * k);
  return 0;
}