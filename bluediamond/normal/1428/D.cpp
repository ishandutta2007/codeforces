#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int a[N];
bool taken[N];
vector<pair<int, int>> sol;

void add(int x, int y) {
  y = n + 1 - y;
  sol.push_back({y, x});
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> ones;
  for (int i = n; i >= 1; i--) {
    if (a[i] == 1) {
      ones.push_back(i);
    }
  }
  int level = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 2) {
      while (!ones.empty() && ones.back() < i) {
        ones.pop_back();
      }
      if (ones.empty()) {
        cout << "-1\n";
        return 0;
      }
      int j = ones.back();
      ones.pop_back();
      level++;
      taken[i] = taken[j] = 1;
      add(i, level);
      add(j, level);
    }
  }
  vector<int> nonz;
  for (int i = n; i >= 1; i--) {
    if (taken[i] && a[i] == 1) {
      continue;
    }
    if (a[i] > 0) {
      nonz.push_back(i);
    }
  }
  int top_level = n + 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 3) {
      while (!nonz.empty() && nonz.back() <= i) {
        nonz.pop_back();
      }
      if (nonz.empty()) {
        cout << "-1\n";
        return 0;
      }
      int j = nonz.back();
      nonz.pop_back();
      top_level--;
      add(i, top_level);
      add(j, top_level);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == 1 && taken[i] == 0) {
      top_level--;
      add(i, top_level);
    }
  }
  cout << (int) sol.size() << "\n";
  for (auto &x : sol) {
    cout << x.first << " " << x.second << "\n";
  }
}