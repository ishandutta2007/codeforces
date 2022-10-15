#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 7;
int n, op, a[N], l[N], f[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> op;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[a[i]]++;
    l[a[i]] = i;
  }

  int i = 1, ans = 0;
  while (i <= n) {
    int j = i, maxf = 0, len = 0;
    while (i <= j) {
      len++;
      maxf = max(maxf, f[a[i]]);
      j = max(j, l[a[i]]);
      i++;
    }
    ans += len - maxf;
  }
  cout << ans << '\n';


  return 0;
}