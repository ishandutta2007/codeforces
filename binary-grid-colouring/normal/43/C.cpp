#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(int argc, char const *argv[]) {

 std::vector<int> a(4);
  int m;
  std::cin >> m;
  for(int i=1;i<=m;i++) {
    int n;
    std::cin >> n;
    int sum = 0;
    while(n){
      sum += (n%10);
      n /= 10;
    }
    a[sum%3]++;
  }
  // match themself + remainder 1 and 2 match eack other
   std::cout << a[0] / 2 + min(a[1],a[2]) << '\n';
   return 0;
}