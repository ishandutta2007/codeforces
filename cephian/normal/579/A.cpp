#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  while(n) {
    ans += (n&1);
    n/=2;
  }
  cout << ans << "\n";
  return 0;
}