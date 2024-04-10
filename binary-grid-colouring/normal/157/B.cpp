#include<bits/stdc++.h>

using namespace std;
const int maxn = 200100;
const double eps = 1e-9;
const double pi = 3.1415926536;

int a[123];
int cmp(int a,int b){
  return a>b;
}
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) {
    cin>>a[i];
  }
  sort(a+1,a+n+1,cmp);
  double ans = 0;
  for(int i=1;i<=n;i++) {
    if(i&1){
      ans += pi*a[i]*a[i];
    }
    else {
      ans -= pi*a[i]*a[i];
    }
  }
printf("%.10f\n", ans);
  return 0;
}