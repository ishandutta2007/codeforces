#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7777;
int n, cnt[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int w;
    cin >> w;
    cnt[w]++;
  }

  int sol = 0;
  for (int i = 0; i < N - 1; i++) {
    cnt[i + 1] += cnt[i] / 2;
    sol += cnt[i] % 2;
  }
  cout << sol << "\n";


  return 0;
}