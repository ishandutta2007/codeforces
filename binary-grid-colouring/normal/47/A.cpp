#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::map<int, int> mp;

int a[250010];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  for(int i=1;i<=500;i++) {
    a[i*(i+1)>>1] = 1;
  }
  if(a[n]==1) {
    std::cout << "YES" << '\n';
  }
  else std::cout << "NO" << '\n';
  return 0;
}