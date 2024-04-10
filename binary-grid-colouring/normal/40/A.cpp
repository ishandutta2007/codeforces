#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::map<int, int> mp;

int main(int argc, char const *argv[]) {
  int x,y;
  std::cin >> x >> y;
  if(x==0||y==0) {
    std::cout << "black" << '\n';
    return 0;
  }
  int r = 0;
  while (r * r < x * x + y * y) {
    /* code */
    r++;
  }
  int black = (x * x + y * y == r * r);
  black |= (r % 2== 0 != (x * y >= 0));
  if(black) {
    std::cout << "black" << '\n';
  }
  else std::cout << "white" << '\n';
  return 0;
}