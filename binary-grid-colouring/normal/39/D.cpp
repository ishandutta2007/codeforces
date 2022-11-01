#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  int a,b,c;
  int d,e,f;
  std::cin >> a >> b >> c;
  std::cin >> d >> e >> f;
  if(a+d==1 && b+e==1 && c+f==1) {
    std::cout << "NO" << '\n';
  }
  else std::cout << "YES" << '\n';
  return 0;
}