#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

vector<int> Manacher(vector<int64> s, bool parity) {
  int n = s.size(), z = parity, l = 0, r = 0;
  vector<int> ret(n - !z, 0);
  
  for (int i = 0; i < n - !z; ++i) {
    if (i + !z < r) ret[i] = min(r - i, ret[l + r - i - !z]);
    int L = i - ret[i] + !z, R = i + ret[i];
    while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1])
      ++ret[i], --L, ++R;
    if (R > r) l = L, r = R;
  }
  
  return ret;
}

int Count(vector<int64> v) {
  // Counts the number of palindromic
  // subsequences of v.
  if (v.empty()) return 0;
  int ans = 0;
  for (int z = 0; z < 2; ++z) {
    auto man = Manacher(v, z);
    for (auto& x : man) {
      if (z == 1) ans += x + 1;
      else ans += x;
    }
  }
  return ans;
}

int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<string> mat(n);
  for (int i = 0; i < n; ++i)
    cin >> mat[i];

  vector<vector<vector<bool>>> ok(
      n, vector<vector<bool>>(
        m, vector<bool>(m)));
  
  vector<vector<vector<int64>>> has(
      n, vector<vector<int64>>(
        m, vector<int64>(m)));
  
  vector<int64> rnd(30);
  for (int i = 0; i < 30; ++i) {
    for (int j = 0; j < 4; ++j) {
      rnd[i] = rnd[i] * RAND_MAX + rand();
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vector<int> freq(30, 0);
      int64 freq_hash = 0;

      int odd_count = 0;

      for (int k = j; k < m; ++k) {
        int now = mat[i][k] - 'a';
        freq_hash += rnd[now];

        if (freq[now] % 2 == 0)
          odd_count += 1;
        else
          odd_count -= 1;
        freq[now] += 1;

        if (odd_count <= 1) {
          ok[i][j][k] = true;
        } else {
          ok[i][j][k] = false;
        }
        has[i][j][k] = freq_hash;
      }
    }
  }

  int64 ans = 0;
  for (int j = 0; j < m; ++j) {
    for (int k = j; k < m; ++k) {
      vector<int64> hashes;
      for (int i = 0; i < n; ++i) {
        if (!ok[i][j][k]) {
          ans += Count(hashes);
          hashes.clear();
          continue;
        }
        hashes.push_back(has[i][j][k]);
      }
      ans += Count(hashes);
    }
  }

  cout << ans << endl;

  return 0;  
}