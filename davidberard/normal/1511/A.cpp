#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) 
  {
    int n;
    cin >> n;
    int up = 0;
    for (int i=1; i<=n; ++i) {
      int x;
      cin >> x;
      if (x == 1 || x == 3) {
        ++up;
      } 
    }
    cout << up << "\n";
  }
  return 0;
}