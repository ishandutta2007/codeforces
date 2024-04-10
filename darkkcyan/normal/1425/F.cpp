#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  cin >> l;
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> sums;
  for (int i = 1; i < n; i++) {
    sums.push_back(query(i, i + 1));
  }
  int sum123 = query(1, 3);
  vector<int> a(n);
  int a2 = sums[0] + sums[1] - sum123;
  a[0] = sums[0] - a2;
  a[1] = a2;
  for (int i = 2; i < n; i++) {
    a[i] = sums[i - 1] - a[i - 1];
  }
  cout << "! ";
  for (int x : a) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}