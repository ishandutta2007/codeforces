#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,ss,ssss,sss;
int vis[1234];
int main(int argc, char const *argv[]) {
  int n,k;
  int m;

  std::cin >> n >> k;
  for(int i=1;i<=k;i++) {
    std::cin >> ss;
    std::cin >> sss;
    std::cin >> s;
    std::cin >> ssss;
    std::cin >> m;
    if(s=="right") {
      for(int i=1;i<=m;i++) vis[i] = 1;
    }
    else
    {
      for(int i=m;i<=n;i++) vis[i] = 1;
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++) {
    if(vis[i]==0) {
      ans++;
    }
  }
  if(ans==0)std::cout << "-1" << '\n';
  else std::cout << ans << '\n';
  return 0;
}