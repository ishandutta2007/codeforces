#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 2e5 + 7;
int n;
int k;
int a[N];
int prefix[N];

int get(int l, int r) {
  return prefix[r] - prefix[l - 1];
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
  }
  int i = 1;
  int ans = -1;
  while (i <= n) {
    int j = i;
    while (j + 1 <= n && a[j + 1] == a[j]) {
      j++;
    }
    int cnt = j - i + 1;
    if (cnt >= k) {
      ans = 0;
      break;
    }
    int cur = (int) 1e18;
    int cnt1 = i - 1;
    int cnt2 = n - j;
    int cost1;
    int cost2;
    cost1 = cnt1 * (a[i] - 1) - get(1, i - 1);
    cost2 = get(j + 1, n) - cnt2 * (a[i] + 1);
    if (cnt1 + cnt >= k) {
      cur = min(cur, cost1);
    }
    if (cnt2 + cnt >= k) {
      cur = min(cur, cost2);
    }
    cur = min(cur, cost1 + cost2);
    cur += k - cnt;
    if (ans == -1) {
      ans = cur;
    } else {
      ans = min(ans, cur);
    }
    i = j + 1;
  }
  cout << ans << "\n";


}