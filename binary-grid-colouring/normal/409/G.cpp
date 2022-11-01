#include<bits/stdc++.h>
using namespace std;

double x[1234],y[1234];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  double ans = 0.0;
  for(int i=0;i<n;i++) {
    std::cin >> x[i] >> y[i];
    ans += y[i];
  }
  printf("%.4f\n",ans / n + 5);
  return 0;
}