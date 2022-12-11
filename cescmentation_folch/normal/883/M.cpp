#include <bits/stdc++.h>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << 2 * (max(abs(x1 - x2), 1) + 1) + 2 * (max(abs(y1 - y2), 1) + 1) << endl;
}