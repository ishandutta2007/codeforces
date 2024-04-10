#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
const ll N = 100005;
const ll M = 10007;
ll a[N];

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a,a+n);
  ll ans = 0;
  for(int i = 0; i < n; ++i)
    ans = (ans+a[i]*a[n-1-i])%M;
  cout << ans << "\n";
  return 0;
}