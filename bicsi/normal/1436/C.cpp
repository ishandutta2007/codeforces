#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
const int kMod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, x, pos; cin >> n >> x >> pos;
  int left = 0, right = n;
  int cs = 0, cg = 0;
  while (left < right) {
    int mid = (left + right) / 2;
    if (mid <= pos) {
      left = mid + 1;
      if (mid != pos) cs += 1;
    } else {
      right = mid;
      cg += 1;
    }
  }
  
  cerr << "cs = " << cs << " cg = " << cg << endl; 
  if (left - 1 != pos) {
    cout << 0 << '\n';
  } else {
    vector<vector<int>> choose(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
      choose[i][0] = choose[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % kMod;
      }
    }

    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i)
      fact[i] = 1LL * fact[i - 1] * i % kMod;
    cout << 1LL * choose[x - 1][cs] * choose[n - x][cg] % kMod * fact[cs] % kMod * fact[cg] % kMod * fact[n - cs - cg - 1] % kMod << '\n';
  }

  return 0;
}