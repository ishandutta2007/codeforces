#include<bits/stdc++.h>

using namespace std;
const int maxn = 2000;
const double eps = 1e-9;
int  x[maxn];
double ans[maxn];
int main(int argc, char const *argv[]) {
  /* code */
  int n,r;
  std::cin >> n >> r;
  for (size_t i = 1; i <= n; i++) {
    /* code */
    double maxx = 0.0;
    std::cin >> x[i];
    for(int j=1;j<=i-1;j++) {
      if(abs(x[i]-x[j]) > 2 * r) continue;
      double tmp = 4 * r * r - (x[i] - x[j]) * (x[i] - x[j]);
      maxx = max(maxx,ans[j]-r+sqrt(tmp));
    }
    ans[i] = maxx + r;
  }
  for (size_t i = 1; i <= n; i++) {
    /* code */
    printf("%.8lf ", ans[i]);
  }
  std::cout  << '\n';
  return 0;
}