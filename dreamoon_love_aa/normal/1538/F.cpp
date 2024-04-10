#include <iostream>

using namespace std;
int f(int x) {
    int _x = x;
    int cnt = x;
    while(x) {
        cnt -= x % 10;
        x /= 10;
    }
    return _x + cnt / 9;
}
void solve () {
  int L, R;
  cin >> L >> R;
  cout << f(R) - f(L) << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}