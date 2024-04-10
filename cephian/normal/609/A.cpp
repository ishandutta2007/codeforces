#include <iostream>
#include <algorithm>

using namespace std;

int a[105];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a, a + n);
  int ans = 0;
  for(int i = n-1; i>=0; --i) {
    if(m <=0) break;
    m -= a[i];++ans;
  }
  cout << ans << "\n";
  return 0;
}