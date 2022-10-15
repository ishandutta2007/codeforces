#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (int) 1e5 + 7;
int n, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int s = 0;
  for (int i = 1; i <= n; i++) s += a[i] % 2;
  if (1 <= s && s < n) sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << "\n";

}