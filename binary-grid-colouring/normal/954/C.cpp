#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5+100;
char s[1234];
int dp[1234];
int a[maxn];
struct node
{
  int x,y;
}AA[maxn];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  int f = 0;
  int id = 0;
  int limit = 1e9;
  for(int i=1;i<=n;i++) {
    std::cin >> a[i];
  }
  for(int i=2;i<=n;i++) {
    if(a[i] == a[i-1]) {
      std::cout << "NO" << '\n';exit(0);
    }
    if(abs(a[i] - a[i-1] )!= 1) {
      if(f==0) {
        f = abs(a[i] - a[i-1]);
      }
      else {
        if(abs(a[i] - a[i-1]) != f) {
          std::cout << "NO" << '\n';exit(0);
        }
      }
    }
    else {
      AA[++id]=(node){a[i],a[i-1]};
    }
  }
  if(f!=0) {
    for(int i=1;i<=id;i++) {
      if((AA[i].x - 1) / f != (AA[i].y - 1) / f) {
        std::cout << "NO" << '\n';exit(0);
      }
    }
  std::cout << "YES" << '\n';
  printf("%d ",limit);
  std::cout << f << '\n';
  }
  else {
    std::cout << "YES" << '\n';
    std::cout << limit << " " << limit << '\n';
  }
  return 0;
}