#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string b, a;
    cin >> n >> b;
    int last = -1;
    for (int i = 0; i < n; i++) {
      int y = b[i] - '0';
      for (int x = 1; x >= 0; x--) {
        if (x + y != last) {
          last = x + y;
          a += (char) ('0' + x);
          break;
        }
      }
    }
    //cout << " = ";
    cout << a << "\n";
  }
}