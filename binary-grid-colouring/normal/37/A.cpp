#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::map<int, int> mp;
int a[1234];
int main(int argc, char const *argv[]) {
  int n,ans = 0;
  std::cin >> n;
  for(int i=1;i<=n;i++) {
    int b;
    std::cin >> b;
    a[i] = b;
    mp[b]++;
    ans = max(mp[b],ans);
  }
  sort(a+1,a+n+1);
  int res = unique(a+1,a+n+1)-a-1;
  std::cout << ans << " ";
  std::cout << res << '\n';
  return 0;
}