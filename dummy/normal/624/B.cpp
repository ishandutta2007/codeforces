#include <bits/stdc++.h>

using namespace std;

int n;
long long a[30];

int main() {
  cin >> n;
  for(int i = 0; i<n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  long long now = a[n-1];
  long long ans = 0;
  for(int i = n-1; i>=0; i--) {
    now = min(now, a[i]);
    ans += now;
    now--;
    if(now < 0)
      break;
  }
  cout << ans << endl;
  return 0;
}