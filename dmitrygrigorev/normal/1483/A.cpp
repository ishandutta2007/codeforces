#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {

  int n, m;
  cin >> n >> m;

  vector<vector<int> > free(m);
  vector<int> cnt(n, 0);

  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    free[i].assign(k, -1);
    for (int j = 0; j < k; ++j) {
      cin >> free[i][j];
      free[i][j]--;
    }
    ans[i] = free[i][0];
    cnt[free[i][0]]++;
  }

  int spec = -1;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] > (m+1)/2) spec = i;
  }

  for (int i = 0; i < m; ++i) {
    if (free[i][0] == spec) {
      if (free[i].size() == 1) continue;
      if (cnt[spec] <= (m+1)/2) continue;
      cnt[spec]--;
      ans[i] = free[i][1];
    }
  }

  spec = -1;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] > (m+1)/2) spec = i;
  }

  if (spec!=-1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto x : ans) cout << x+1 << " ";
  cout << '\n';



}


int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}