#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int l, r; cin >> l >> r;
  r -= l - 1;
  
  int N = 28;
  vector<vector<int>> D(N, vector<int>(N, 0));
  D[0][N - 1] = 1;
  int last = 1;
  for (int i = 1; (1 << i) <= r; ++i) {
    D[i][N - 1] = 1;
    for (int j = i - 1; j >= 0; --j) {
      int dist = (j == 0 ? 0 : (1 << (j - 1)));
      // dist + ce pun + 1 == last + 1
      D[j][i] = last - dist;
      last = D[0][j] + D[j][i] + 1;
    }
    assert(last == (1 << i));
  }
  D[N - 2][N - 1] = 1;
  for (int j = N - 3; j >= 0; --j) {
    if (D[j][N - 1] == 0) continue;
    int dist = (j == 0 ? 0 : (1 << (j - 1)));
    int to_put = last - dist;
    if (D[0][j] + to_put + 1 <= r) {
      D[j][N - 2] = to_put;
      last = D[0][j] + D[j][N - 2] + 1;
    }
  }
  assert(last == r);

  for (int i = 0; i < N; ++i)
    if (D[i][N - 1] == 1) 
      D[i][N - 1] = l;

  vector<tuple<int, int, int>> ans;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (D[i][j] > 0) 
        ans.emplace_back(i, j, D[i][j]);

  cout << "YES\n";
  cout << N << " " << ans.size() << '\n';
  for (auto [a, b, c] : ans)
    cout << a + 1 << " " << b + 1 << " " << c << endl;

  return 0;
}