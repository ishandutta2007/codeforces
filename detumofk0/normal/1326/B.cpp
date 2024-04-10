#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n), ans(n);

  int mx = 0;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    ans[i] = mx + a[i];
    mx = max(mx, ans[i]);
  }

  for(int i = 0; i < n; ++i) cout << ans[i] << " ";

  return 0;
}