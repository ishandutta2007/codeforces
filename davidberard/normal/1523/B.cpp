#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1010;
int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
    }
    cout << n*3 << "\n";
    for (int i=1; i<=n; i+=2) {
      int j= i+1;
      for (int q=0; q<3; ++q) {
        cout << "1 " << i << " " << j << "\n";
        cout << "2 " << i << " " << j << "\n";
      }
    }
  }
  return 0;
}