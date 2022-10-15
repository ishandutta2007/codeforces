#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 7;
int n, want, sum[N];

int cnt(int l, int r) {
  return (r - l + 1) / 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i < N; i++) {
    sum[i] = sum[i - 1] + cnt(1, i - 1);
  }
  cin >> n >> want;
  if (want > sum[n]) {
    cout << "-1\n";
    return 0;
  }
  int len = 1;
  while (sum[len + 1] <= want) {
    len++;
  }
  vector<int> ans;
  for (int i = 1; i <= len; i++) {
    ans.push_back(i);
  }
  for (int j = 1; j <= len; j++) {
    if (cnt(j, len) == want - sum[len]) {
      ans.push_back(j + len);
      break;
    }
  }
  int printing = n - (len + 1);
  for (int i = 1; i <= printing; i++) {
    ans.push_back((int) 1e8 + (int) 1e4 * i);
  }
  while ((int) ans.size() > n) {
    ans.pop_back();
  }
  for (auto &x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}