#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> rep(vector<pair<int, int>> v) {
  sort(v.begin(), v.end());
  vector<pair<int, int>> sol;
  for (auto &it : v) {
    if (!sol.empty() && sol.back().first == it.first) {
      sol.back().second += it.second;
    } else {
      sol.push_back(it);
    }
  }
  return sol;
}



int f(int z, int nonz) {
  if (z == 0) {
    return (nonz == 1);
  }
  return (nonz != 0);
}


int my(vector<int> init) {
  vector<pair<int, int>> v;
  int nonz = 0;
  for (auto &x : init) {
    v.push_back({x, 1});
    nonz += (x != 0);
  }
  v = rep(v);
  while (nonz > 1) {

    nonz = 0;
    vector<pair<int, int>> nxt;
    for (int i = 0; i < (int) v.size(); i++) {
      if (i > 0) {
        nonz++;
        nxt.push_back({v[i].first - v[i - 1].first, 1});
      }
      if (v[i].second > 1) {
        nxt.push_back({0, v[i].second - 1});
      }
    }
    v = rep(nxt);
  }
  int z = 0, w = -1;
  nonz = 0;
  int sol = 0;
  for (auto &it : v) {
    if (it.first == 0) {
      z = it.second;
    } else {
      w = it.first;
      nonz = it.second;
    }
  }
  return f(z, nonz) * w;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  int tst;
  cin >> tst;
  for (int tc = 1; tc <= tst; tc++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    cout << my(a) << "\n";
  }
}