#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, k;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> k;


  if (k < n * (n + 1) / 2) {
    cout << "-1\n";
    exit(0);
  }

  {
    int sm = 0;
    for (int i = 1; i <= n; i++) {
      sm += max(i, n + 1 - i);
    }
    if (sm <= k) {
      cout << sm << "\n";
      for (int i = 1; i <= n; i++) cout << i << " "; cout << "\n";
      for (int i = 1; i <= n; i++) cout << n + 1 - i << " "; cout << "\n";
      exit(0);
    }
    assert(n * (n + 1) / 2 <= k && k < sm);
  }
  vector<int> sol(n);
  iota(sol.begin(), sol.end(), 1);
  int need = k - n * (n + 1) / 2;
  int l = 0, r = n - 1;

  while (1) {
    int max_add = r - l;
    if (max_add <= need) {
      swap(sol[l], sol[r]);
      l++;
      r--;
      need -= max_add;
    } else {
      swap(sol[l], sol[l + need]);
      break;
    }
  }

  cout << k << "\n";
  for (int i = 1; i <= n; i++) cout << i << " "; cout << "\n";
  for (auto &i : sol) cout << i << " "; cout << "\n";
}