#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int day[366];
int main(int argc, char const *argv[]) {
  int n,k;
  int c;
  std::cin >> n >> k >> c;
  for(int i=0;i<c;i++) {
    std::cin >> day[i];
  }
  int cnt = 0;
  int ans = 0;
  int id = 0;
  for(int i=0;i<=n;i++) {
    if(i==day[id] && i!=0) {
      cnt = 0;
      ans ++;
      id++;
    }
    if(cnt==k) {
      cnt = 0;
      ans ++;
    }
    cnt++;
  }
  std::cout << ans << '\n';
  return 0;
}