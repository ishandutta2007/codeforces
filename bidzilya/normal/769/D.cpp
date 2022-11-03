#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

const int LIM = 1e+4 + 1;
const int MAX_BIT = 14;

void dfs(int val, int bit_num, int left_to_flip, vector<int>& buf) {
  if (left_to_flip < 0)
    return;

  if (bit_num == MAX_BIT) {
    if (left_to_flip == 0 && val < LIM)
      buf.push_back(val);
    return;
  }

  int left_bits = MAX_BIT - bit_num;
  if (left_bits < left_to_flip)
    return;

  dfs(val, bit_num + 1, left_to_flip, buf);
  dfs(val ^ (1 << bit_num), bit_num + 1, left_to_flip - 1, buf);
}

void fill_buffer(int val, int k, vector<int>& buf) {
  buf.clear();
  dfs(val, 0, k, buf);
}

int main() {
  auto start = high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> cnt(LIM, 0);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  sort(a.begin(), a.end());

  long long ans = 0;
  vector<int> buf;
  buf.reserve(LIM);

  long long prev = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || a[i] != a[i - 1]) {
      fill_buffer(a[i], k, buf);
      prev = 0;
      for (int it : buf)
        prev += cnt[it];

      if (k == 0)
        --prev;
    }
    ans += prev;
  }

  cout << ans / 2 << endl;

  //vector<vector<bool>> is_ok(LIM, vector<bool>(LIM, false));
  //for (int i = 0; i < LIM; ++i)
  //  for (int j = i; j < LIM; ++j)
  //    is_ok[i][j] = is_ok[j][i] = __builtin_popcount(i ^ j) == k;

  //long long ans2 = 0;
  //for (int i = 0; i < n; ++i)
  //  for (int j = i + 1; j < n; ++j)
  //    ans2 += is_ok[a[i]][a[j]];

  //cout << ans2 << endl;


  cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

  return 0;
}