#include <bits/stdc++.h>

using namespace std;

vector<int> get(int n) {
  if (n == 1) {
    return {1};
  }
  if (n == 2) {
    return {3, 4};
  }
  vector<int> a;

  if (n % 2 == 0) {
    int k = n / 2;
    for (int i = 1; i <= 2 * k - 1; i++) {
      a.push_back(1);
    }
    a.push_back(k - 1);
  } else {
    int k = n / 2;
    for (int i = 1; i <= 2 * k - 1; i++) {
      a.push_back(1);
    }
    a.push_back(2);
    a.push_back(k + 1);
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> a = get(n), b = get(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i] * b[j] << " ";
    }
    cout << "\n";
  }
}