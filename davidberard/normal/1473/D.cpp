#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
pair<int, int> pre[N], suf[N];
int pv[N];
char s[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, m;
    cin >> n >> m;
    cin >> (s+1);
    pre[0] = {0, 0};
    suf[n+1] = {0, 0};
    pv[0] = 0;
    for (int i=1; i<=n; ++i) {
      if (s[i] == '+') {
        pv[i] = pv[i-1]+1;
      } else if (s[i] == '-') {
        pv[i] = pv[i-1]-1;
      }
      pre[i] = pre[i-1];
      pre[i].first = min(pre[i].first, pv[i]);
      pre[i].second = max(pre[i].second, pv[i]);
    }
    for (int i=n; i>=1; --i) {
      if (s[i] == '+') {
        suf[i] = {suf[i+1].first+1, suf[i+1].second+1};
      } else {
        suf[i] = {suf[i+1].first-1, suf[i+1].second-1};
      }
      suf[i].first = min(suf[i].first, 0);
      suf[i].second = max(suf[i].second, 0);
    }
    for (int _tt=1; _tt<=m; ++_tt) {
      int l, r;
      cin >> l >> r;
      int lo = min(pv[l-1]+suf[r+1].first, pre[l-1].first);
      int hi = max(pv[l-1]+suf[r+1].second, pre[l-1].second);
      cout << hi-lo+1 << "\n";
      //cerr << l << "," << r << " : "<< " LO HI " << lo << " " << hi << endl;
    }
  }
  return 0;
}