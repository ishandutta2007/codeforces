#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,m;
int main(int argc, char const *argv[]) {

  double ans =1e9;
  std::cin >> n >> m;
  for(int i=1;i<=n;i++) {
    int x,y;
    std::cin >> x >> y;
    double res = 1.0 * m * x / y;
    if(res < ans) {
      ans = res;
    }
  }
  printf("%.8f\n", ans);
  return 0;
}