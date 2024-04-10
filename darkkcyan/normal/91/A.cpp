#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 10101
string a, b;
int nxt[maxn * 2][26];
int last[26];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> b;
  memset(nxt, -1, sizeof(nxt));
  memset(last, -1, sizeof(last));
  a += a;
  for (int i = len(a); i--; ) {
    memcpy(nxt[i], last, sizeof(last));
    last[a[i] - 'a'] = i;
  }
  // rep(i, len(a)) {
  //   clog << i << ':';
  //   rep(f, 26) clog << char(f + 'a') <<  nxt[i][f] << ' ';
  //   clog << endl;
  // }
  
  llong ans = 0;
  int f = len(a) / 2 - 1;
  rep(i, len(b)) {
    int t = nxt[f][b[i] - 'a'];
    // clog <<t << endl;
    if (t == -1) {
      cout << -1;
      return 0;
    }
    if (t >= len(a) / 2) {
      ++ans;
      t -= len(a) / 2;
    }
    f = t;
  }
  cout << ans;
  
  return 0;
}