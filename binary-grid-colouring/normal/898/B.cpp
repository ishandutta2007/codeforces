#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e6+3;
const ll INF =2e15;

ll n,a,b;
int main(int argc, char const *argv[]) {

  std::cin >> n >> a >> b;
  for(int i=0;i*a<=n;i++) {
    if((n-i*a)%b==0) {
      std::cout << "YES" << '\n';
      std::cout << i << " " <<(n-i*a)/b<< '\n';
      return 0;
    }
  }
  std::cout << "NO" << '\n';
  return 0;
}