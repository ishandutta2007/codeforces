#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> s;

int ask(int i, int j) {
  if (s.count({i, j})) return i;
  if (s.count({j, i})) return j;
  cout << "? " << i << " " << j << endl;
  string ret;
  cin >> ret;
  if (ret == "<") {
    s.insert({i, j});
    return i;
  } else {
    s.insert({j, i});
    return j;
  }
}

int fmin(vector<int> a) {
  if ((int) a.size() == 1) {
    return a[0];
  }
  vector<int> b;
  for (int i = 0; i < (int) a.size(); i += 2) {
    if (i == (int) a.size() - 1) {
      b.push_back(a[i]);
    } else {
      b.push_back(ask(a[i], a[i + 1]));
    }
  }
  return fmin(b);
}

vector<int> del(vector<int> a, int i) {
  vector<int> b;
  for (auto &x : a) {
    if (x != i) {
      b.push_back(x);
    }
  }
  return b;
}

int n;
vector<int> a, b;

void add(int i) {
  if ((int) a.size() < (int) b.size()) {
    a.push_back(i);
  } else {
    b.push_back(i);
  }
}

void extract() {
  int x = fmin(a);
  int y = fmin(b);
  if (ask(x, y) == x) {
    a = del(a, x);
  } else {
    b = del(b, y);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    s.clear();
    a.clear();
    b.clear();
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      add(i);
      if (i >= n + 1) {
        extract();
      }
    }
    cout << "!" << endl;
  }
}