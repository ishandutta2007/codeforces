#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> a(n+1);
  for(int i=1;i<=n;i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for(int i=1;i<=n;i++) {
    int l = i, r = i;
    while(l-1 >= 1 && a[l-1] <= a[l]) l--;
    while(r+1 <= n && a[r] >= a[r+1]) r++;
    ans = max(ans,r-l+1);
  }
  std::cout << ans << '\n';
  return 0;
}