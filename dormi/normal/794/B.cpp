// March 25, 2020
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, h;
  cin >> n >> h;
  cout.precision(10);
  cout << fixed;
  for (int i = 1; i <= n - 1; i++) {
    double a = (double) i / n * h / 2;
    if (i > 1) {
      cout << ' ';
    }
    cout << sqrt(2 * a * h);
  }
  cout << '\n';


  return 0;
}