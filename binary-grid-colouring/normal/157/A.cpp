#include<bits/stdc++.h>

using namespace std;
const int maxn = 200100;
const double eps = 1e-9;

int a[32][32];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      std::cin >> a[i][j];
    }
  }
  if(n==1) {
    std::cout << "0" << '\n';
    return 0;
  }
  int c=0,r=0;
  int ans = 0;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      c = r = 0;
      for(int k=1;k<=n;k++) {
        c += a[k][j];
      }
      for(int k=1;k<=n;k++){
        r += a[i][k];
      }
      if(c>r){
        ans++;
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}