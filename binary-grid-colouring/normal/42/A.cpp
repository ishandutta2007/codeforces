#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::map<int, int> mp;

int n;
double V;
double a[1234],b[1234];
int main(int argc, char const *argv[]) {
  std::cin >> n >> V;
  for(int i=0;i<n;i++) {
    cin>> a[i];
  }
  for(int i=0;i<n;i++) {
    std::cin >> b[i];
  }
  double m = V;
  for(int i=0;i<n;i++) {
    m = min(m, b[i] / a[i]);
  }
  double ans= 0;
  for(int i=0;i<n;i++) {
    ans += (m * a[i]);
  }
  ans = min(ans,V);
  printf("%.4f\n",ans);
  return 0;
}