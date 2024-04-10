#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 7;
int n, s[N], nxt[N];
unordered_map<int, int> f;

ll brute(int k) {
  ll ret = 0;
  for (int j = 0; j <= n; j++) {
    ret += f[j - s[j] * k]++;
  }
  f.clear();
  return ret;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string str;
  cin >> str;
  n = (int) str.size();
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + str[i - 1] - '0';
  nxt[n + 1] = N;
  for (int i = n; i >= 1; i--) {
    if (s[i] - s[i - 1] == 1) nxt[i] = i;
    else nxt[i] = nxt[i + 1];
  }
  ll ret = 0;
  int rad = 300;
  for (int i = 1; i <= n; i++) {
    int j = nxt[i], delta = i - 1;
    while (j <= n) {
      int j2 = min(n, nxt[j + 1] - 1), cnt = s[j] - s[i - 1];
      if (cnt * rad > n) break;

      int l = j - delta, r = j2 - delta;
      if (l % cnt == 0) {
        l /= cnt;
      } else {
        l = l / cnt + 1;
      }
      r /= cnt;
      ret += max(0, r - max(l, rad + 1) + 1);
      j = j2 + 1;
    }
  }
  for (int k = 1; k <= rad; k++) {
    ret += brute(k);
  }
  cout << ret << "\n";
  return 0;
}