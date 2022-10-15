#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
bool vis[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE


  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
    }
    cout << "2\n";
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        for (int j = i; j <= n && (vis[j] == 0); j *= 2) {
          cout << j << " ";
          vis[j] = 1;
        }
      }
    }
    cout << "\n";

  }
}