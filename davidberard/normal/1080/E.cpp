#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 260;

int ord(char c) {
  return c-'a';
}

char grid[N][N];
int cnt[N][30];
const ll B = 1789;
const ll MOD = 1e9+7;
ll pw[N];
ll mh[N];
int len[N*2];
bool is_good[N];
int n, m;

void setup() {
  pw[0] = 1;
  for (int i=1; i<N; ++i) {
    pw[i] = pw[i-1]*B%MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  ll ans = 0;
  cin >> n >> m;
  for (int i=1; i<=n; ++i) {
    cin >> (grid[i]+1);
  }
  for (int a=1; a<=m; ++a) {
    memset(cnt, 0, sizeof cnt);
    memset(mh, 0, sizeof mh);
    for (int b=a; b<=m; ++b) {
      for (int i=1; i<=n; ++i) {
        mh[i] = (mh[i] + pw[ord(grid[i][b])])%MOD;
        cnt[i][ord(grid[i][b])]++;
        int oddcount = 0;
        for (int j=0; j<26; ++j) {
          oddcount += cnt[i][j]%2;
        }
        is_good[i] = oddcount <= 1;
      }
      int fl = 0, fr = 0;
      for (int i=1; i<2*n; ++i) {
        int x = (i+1)/2, y = (i+2)/2;
        len[i] = 0;
        if (y <= fr) {
          int idx = fl*2-1 + (fr*2-1 - i);
          len[i] = max(0, min(len[idx], fr-y+1));
        }
        while (
            x-len[i] >= 1
         && y+len[i] <= n
         && mh[x-len[i]] == mh[y+len[i]]
         && is_good[x-len[i]]
         && is_good[y+len[i]]) {
          ++len[i];
        }
        ans += len[i];
        if (fr < y+len[i]-1) {
          fr = y+len[i]-1;
          fl = x-len[i]+1;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}