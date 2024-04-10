#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100 + 7;
int n, a[N];
bool seen[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      seen[i] = 0;
    }
    for (int i = 1; i <= 2 * n; i++) {
      int x;
      cin >> x;
      if (seen[x] == 0) {
        cout << x << " ";
        seen[x] = 1;
      }
    }
    cout << "\n";
  }
  return 0;
}