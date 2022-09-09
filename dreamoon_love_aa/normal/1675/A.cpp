#include <iostream>
using namespace std;
void solve() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  x -= a;
  y -= b;
  if(max(0, x) + max(0, y) <= c) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}