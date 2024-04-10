#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

ll arr[200005];
ll x2[200005];

map<ll,ll> seen;

int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for(int i =0; i < n; ++i)
    cin >> arr[i];
  for(int j = n-1; j >=0; --j) {
    x2[j] = seen[arr[j]*k];
    ++seen[arr[j]];
  }
  seen.clear();
  ll ans = 0;
  for(int j = n-1; j >= 0; --j) {
    ans += seen[arr[j]*k];
    seen[arr[j]] += x2[j];
  }
  cout << ans << "\n";

  return 0;
}