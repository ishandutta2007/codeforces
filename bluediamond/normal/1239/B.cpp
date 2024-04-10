#include <bits/stdc++.h>

using namespace std;

const int N = 300000 + 7;
int n, sum_init[2 * N], sum[N], shift;
string str;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> str;
  for (int i = 1; i <= n; i++) {
    sum_init[i] = sum_init[i - 1] + (str[i - 1] == '(' ? 1 : -1);
    sum_init[i + n] = sum_init[i];
  }
  if (sum_init[n] != 0) {
    cout << "0\n1 1\n";
    return 0;
  }
  int mn = 0;
  for (int i = 1; i <= n; i++) {
    mn = min(mn, sum_init[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (sum_init[i] == mn) {
      for (int j = 1; j <= n; j++) {
        sum[j] = sum_init[j + i] - sum_init[i];
      }
      shift = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    assert(sum[i] >= 0);
  }
  int best = 0, l = 1, r = 1;
  vector<int> ones, zeroes = {0};
  for (int i = 1; i <= n; i++) {
    if (sum[i] == 1) {
      ones.push_back(i);
    }
    if (sum[i] == 0) {
      zeroes.push_back(i);
    }
  }
  best = (int) zeroes.size() - 1;
  /// aim bot for sum = 0
  for (int i = 0; i + 1 < (int) ones.size(); i++) {
    if (sum[ones[i] + 1] == 2) {
      int now = (int) zeroes.size() - 1;
      for (int j = ones[i] + 1; j < ones[i + 1]; j++) {
        now += (sum[j] == 2);
      }
      if (now > best) {
        best = now;
        l = ones[i] + 1;
        r = ones[i + 1];
      }
    }
  }
  /// aim bot for sum = 1
  for (int i = 0; i + 1 < (int) zeroes.size(); i++) {
    int now = 0;
    for (int j = zeroes[i] + 1; j < zeroes[i + 1]; j++) {
      now += (sum[j] == 1);
    }
    if (now > best) {
      best = now;
      l = zeroes[i] + 1;
      r = zeroes[i + 1];
    }
  }
  l += shift;
  r += shift;
  if (l > n) l -= n;
  if (r > n) r -= n;
  cout << best << "\n" << l << " " << r << "\n";
}