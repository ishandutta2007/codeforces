#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

int main(int argc, char const *argv[]) {
  int x1,y1,x2,y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  int x,y;
  std::cin >> x >> y;
  if(abs(x2-x1) % x ==0 && abs(y2-y1) % y == 0 && ( abs(x2-x1) / x )% 2 == (abs(y2-y1) / y) %2) {
    std::cout << "YES" << '\n';
  }
  else std::cout << "NO" << '\n';
  return 0;
}