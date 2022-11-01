#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[3];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  for(int i=1;i<=n;i++) {
    int a;
    std::cin >> a;
    cnt[a] ++;
  }
  int mx = max(cnt[1],max(cnt[2],cnt[3]));
  std::cout << n-mx << '\n';
  return 0;
}