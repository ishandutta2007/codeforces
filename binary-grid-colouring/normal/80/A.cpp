#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(int x)
{
  for(int i=2;i*i<=x;i++) {
    if(x%i==0)return 0;
  }
  return  1;
}
int main(int argc, char const *argv[]) {
  int n,m;std::cin >> n >> m;
  for(int i=n+1;;i++) {
    if(isprime(i)) {
      if(i==m) {
        std::cout << "YES" << '\n';return 0;
      }
      if(i!=m) {
        std::cout << "NO" << '\n';return 0;
      }
    }
    if(i>m)break;
  }
  std::cout << "NO" << '\n';
  return 0;
}