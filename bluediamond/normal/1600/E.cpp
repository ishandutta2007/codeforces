#include <bits/stdc++.h>

using namespace std;


void print(vector<int> v) {
  cout << " ----> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

const int N = (int) 2e5 + 7;
int n, a[N];
vector<int> x, y;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  {
    int eq = 0;
    int sm = 0;
    int bg = 0;
    for (int i = 1; i < n; i++) {
      eq += (a[i] == a[i + 1]);
      sm += (a[i] < a[i + 1]);
      bg += (a[i] > a[i + 1]);
    }
    if (sm == n - 1 || bg == n - 1) {
      cout << "Alice\n";
      return 0;
    }
  }
  vector<int> x, y;
  for (int i = 1; i <= n; i++) {
    if (x.empty() || x.back() < a[i]) {
      x.push_back(a[i]);
    } else {
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (y.empty() || y.back() < a[i]) {
      y.push_back(a[i]);
    } else {
      break;
    }
  }

  int mx = max(x[0], y[0]);
  if (x[0] == mx && (int) x.size() % 2 == 1) {
    cout << "Alice\n";
    return 0;
  }
  if (y[0] == mx && (int) y.size() % 2 == 1) {
    cout << "Alice\n";
    return 0;
  }

  if (x[0] < mx && (int) x.size() % 2 == 1) {
    cout << "Alice\n";
    return 0;
  }
  if (y[0] < mx && (int) y.size() % 2 == 1) {
    cout << "Alice\n";
    return 0;
  }
  cout << "Bob\n";

  return 0;
}
/**
2 3 4 5 |   10  9   8  7
             B  A   B  A

5 8 10                       10  9
A                             A   B
**/