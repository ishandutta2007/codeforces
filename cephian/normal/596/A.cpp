#include <iostream>
#include<cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int x0=1005, y0=1005, x1=-1005, y1=-1005;
  for(int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    x0 = min(x0, x);
    x1 = max(x1, x);
    y0 = min(y0, y);
    y1 = max(y1, y);
  }
  if((x0-x1)*(y0-y1) == 0) cout << "-1\n";
  else cout << abs((x0-x1)*(y0-y1)) << "\n";
  return 0;
}