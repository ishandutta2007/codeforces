#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  if(n==2) {
    std::cout << "3" << '\n';return 0;
  }
  if(n==4) {
    std::cout << "6" << '\n';
  }
  if(n>=6) {
    std::cout << n / 2 * 3 << '\n';
  }
  return 0;
}