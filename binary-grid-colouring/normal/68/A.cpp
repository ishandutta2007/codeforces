#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(int argc, char const *argv[]) {
  int ans = 0;
  int p1,p2,p3,p4;
  int a,b;
  std::cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  for(int i=a;i<=b;i++) {
    if(((((i%p1) % p2) % p3) % p4) == i) {
      ans++;
    }
  }
  std::cout << ans << '\n';
  return 0;
}