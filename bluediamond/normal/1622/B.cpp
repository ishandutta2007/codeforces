#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n;
int a[N];
int liked[N];
int sol[N];
string s;
vector<pair<int, int>> guys[2];
vector<int> guys2[2];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    guys[0].clear();
    guys[1].clear();
    guys2[0].clear();
    guys2[1].clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    cin >> s;
    int lk = 0;
    assert((int) s.size() == n);
    for (int i = 1; i <= n; i++) {
      liked[i] = s[i - 1] - '0';
      guys[liked[i]].push_back({a[i], i});
      lk += liked[i];
    }
    for (int i = 1; i <= n - lk; i++) {
      guys2[0].push_back(i);
    }
    for (int i = n - lk + 1; i <= n; i++) {
      guys2[1].push_back(i);
    }

    for (int step = 0; step < 2; step++) {
      sort(guys[step].begin(), guys[step].end());
      assert((int) guys[step].size() == (int) guys2[step].size());
      for (int j = 0; j < (int) guys[step].size(); j++) {
        sol[guys[step][j].second] = guys2[step][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}