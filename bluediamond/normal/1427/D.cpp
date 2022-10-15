#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> get(vector<int> a) {
  vector<pair<int, int>> b;
  int n = (int) a.size();
  int i = 0;
  while (i < n) {
    int j = i;
    while (j + 1 < n && a[j + 1] == a[j] + 1) {
      j++;
    }
    b.push_back({a[i], a[j]});
    i = j + 1;
  }
  return b;
}

vector<int> operator ^ (vector<int> a, vector<int> x) {
  vector<vector<int>> e;
  int y = 0;
  for (auto &l : x) {
    e.push_back({});
    for (int j = 1; j <= l; j++) {
      e.back().push_back(a[y++]);
    }
  }
  reverse(e.begin(), e.end());
  y = 0;
  for (auto &vec : e) {
    for (auto &val : vec) {
      a[y++] = val;
    }
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> ret;
  while (1) {
    vector<pair<int, int>> b = get(a);
    if ((int) b.size() == 1) {
      break;
    }
    int m = (int) b.size();
    for (int i = 0; i < m; i++) {
      int k = -1;
      for (int j = i + 1; j < m; j++) {
        if (b[j].second == b[i].first - 1) {
          k = j;
          break;
        }
      }
      if (k == -1) {
        continue;
      }
      int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
      for (int j = 0; j < i; j++) {
        x1 += b[j].second - b[j].first + 1;
      }
      for (int j = i; j < k; j++) {
        x2 += b[j].second - b[j].first + 1;
      }
      x3 = b[k].second - b[k].first + 1;
      for (int j = k + 1; j < m; j++) {
        x4 += b[j].second - b[j].first + 1;
      }
      vector<int> x;
      if (x1 > 0) {
        x.push_back(x1);
      }
      if (x2 > 0) {
        x.push_back(x2);
      }
      if (x3 > 0) {
        x.push_back(x3);
      }
      if (x4 > 0) {
        x.push_back(x4);
      }
      a = a ^ x;
      ret.push_back(x);
      break;
    }
  }
  cout << (int) ret.size() << "\n";
  for (auto &v : ret) {
    cout << (int) v.size() << " ";
    for (auto &l : v) {
      cout << l << " ";
    }
    cout << "\n";
  }
}