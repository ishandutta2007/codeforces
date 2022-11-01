#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  int n,m;
  std::cin >> n >> m;
  if(n%2==0) {
    std::cout << n / 2 * m << '\n'; exit(0);
  }
  if(m%2==0) {
    std::cout << m / 2 * n << '\n';return 0;
  }
  std::cout << (n - 1) / 2 * m + m / 2 << '\n';
  return 0;
}