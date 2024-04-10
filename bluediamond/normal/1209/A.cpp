#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 7;
int n;
bool u[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    u[x] = 1;
  }

  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    if (u[i]) {
      ans++;
      for (int j = i; j <= 100; j += i) {
        u[j] = 0;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}