#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 200
int n, m;
int mi[maxn], ma[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) {
    string s; cin >> s;
    mi[i] = m;
    ma[i] = -1;
    rep(f, m) {
      if (s[f] != 'W') continue;
      if (mi[i] == m) mi[i] = f;
      ma[i] = f;
    }
  }
  while (n > 0 and mi[n - 1] == m) --n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  
  ma[n] = -1;
  mi[n] = m;
  int p = 0;
  int ans = n - 1;
  for (int i = 0; i < n; ) {
    int next = i + 1;
    while (next + 1 < n and ma[next] == -1) ++ next;
    if (((next + i) & 1) == 0) next = i + 1;
    int t;
    if ((~i) & 1) {
      t = max(ma[i] == -1 ? p : ma[i], ma[next]);
      ans += t - p;
    } else {
      t = min(mi[i] == m ? p : mi[i], mi[next]);
      ans += p - t;
    }
    p = t;
    i = next;
  }
  cout << ans;
  
  return 0;
}