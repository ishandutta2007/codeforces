#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005];
int ans[100005];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> arr[i];
  int mx = 0;
  for(int i = n-1; i >=0; --i) {
    ans[i] = max(0, mx - arr[i]+1);
    mx = max(mx, arr[i]);
  }
  for(int i = 0; i < n; ++i) {
    cout << ans[i];
    if(i == n-1) cout << "\n";
    else cout << " ";
  }
}