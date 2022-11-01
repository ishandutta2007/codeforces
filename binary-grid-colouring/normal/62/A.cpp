#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(int argc, char const *argv[]) {

  int n,m;
  int a,b;
  std::cin >> n >> m;
  std::cin >> a >> b;

  if(a>=m-1 && a<=(m+1)*2) {
    std::cout << "YES" << '\n';return 0;
  }
  if(b>=n-1 && b<=(n+1)*2) {
    std::cout << "YES" << '\n';return 0;
  }

  std::cout << "NO" << '\n';
  return 0;
}