#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int K = 210;
int cnt[K];
int lst[K];
int offset[K];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    memset(cnt, 0, sizeof cnt);
    memset(lst, 0, sizeof lst);
    memset(offset, 0, sizeof offset);

    int n;
    cin >> n;

    vector<vector<int>> of(n+5, vector<int>(210));
    vector<int> a(n+5);
    for (int i=0; i<=200; ++i) {
      lst[i] = n+1;
    }
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
      for (int j=0; j<=200; ++j) {
        of[i][j] = of[i-1][j];
      }
      of[i][a[i]]++;
    }

    int ans = 1;

    for (int i=1; i<=n; ++i) {
      ++cnt[a[i]];
      ++offset[a[i]];
      for (--lst[a[i]]; a[lst[a[i]]] != a[i] && lst[a[i]] > i; --lst[a[i]]);
      if (lst[a[i]] <= i) {
        continue;
      }

      for (int j=0; j<=200; ++j) {
        ans = max(ans, cnt[a[i]]*2 + of[lst[a[i]]-1][j] - offset[j]);
        //cerr << " I J " << i << " " << j << " : " << cnt[a[i]]*2 + of[lst[a[i]]-1][j] - offset[j] << endl;
      }
    }

    cout << ans << '\n';
  }
  return 0;
}