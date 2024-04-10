#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 1e5 + 7;
int n, k, sol = N;
string s;
vector<int> a;

int eval(int x, int y, int i) {
  return max(abs(x - a[i]), abs(y - a[i]));
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k >> s;
  k++;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '0') {
      a.push_back(i);
    }
  }
  assert((int) a.size() >= k);
  int j = 0;
  for (int i = 0; i + k - 1 < (int) a.size(); i++) {
    int x = a[i], y = a[i + k - 1];
    while (j + 1 < (int) a.size() && eval(x, y, j + 1) < eval(x, y, j)) j++;
    sol = min(sol, eval(x, y, j));
  }
  cout << sol << "\n";
  return 0;
}