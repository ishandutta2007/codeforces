#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> s;

bool inside(int r, int c) {
  return 1 <= r && 1 <= c && r <= 999 && c <= 999;
}

bool ok(int r, int c) {
  for (auto &it : s) {
    if (it.first == r && it.second == c) {
      return 0;
    }
  }
  return 1;
}

bool in_check(int x, int y) {
  for (auto &it : s) {
    if (it.first == x || it.second == y) {
      return 1;
    }
  }
  return 0;
}

vector<pair<int, int>> mvs(int r, int c) {
  vector<pair<int, int>> ret;
  for (int dr = -1; dr <= +1; dr++) {
    for (int dc = -1; dc <= +1; dc++) {
      if (max(abs(dr), abs(dc)) == 1) {
        int rn = r + dr, cn = c + dc;
        if (inside(rn, cn) && ok(rn, cn)) {
          ret.push_back({rn, cn});
        }
      }
    }
  }
  assert(!ret.empty());
  return ret;
}

int dist(pair<int, int> it, int r, int c) {
  return abs(it.first - r) + abs(it.second - c);
}

pair<int, int> what[1000];
int cnt[5];

int main() {
  int x, y;
  cin >> x >> y;
  for (int i = 1; i <= 666; i++) {
    int r, c;
    cin >> r >> c;
    what[i] = {r, c};
    s.insert({r, c});
  }
  int a = 500, b = 500;
  while (x != a || y != b) {
    auto vec = mvs(x, y);
    vector<pair<int, pair<int, int>>> po;
    for (auto &it : vec) {
      po.push_back({dist(it, a, b), it});
    }
    sort(po.begin(), po.end());
    x = po[0].second.first;
    y = po[0].second.second;
    cout << x << " " << y << endl;
    if (in_check(x, y)) {
      return 0;
    }
    int k, x, y;
    cin >> k >> x >> y;
    if (k == -1 || k == 0) {
      return 0;
    }
    s.erase(what[k]);
    what[k] = {x, y};
    s.insert(what[k]);
  }
  for (auto &it : s) {
    int type;
    if (it.first < a) {
      if (it.second < a) type = 1;
      else type = 2;
    } else {
      if (it.second < a) type = 3;
      else type = 4;
    }
    cnt[type]++;
  }
  int mn = min({cnt[1], cnt[2], cnt[3], cnt[4]});
  if (cnt[1] == mn) a = 1000, b = 1000;
  if (cnt[2] == mn) a = 1000, b = 1;
  if (cnt[3] == mn) a = 1, b = 1000;
  if (cnt[4] == mn) a = 1, b = 1;
  while (x != a || y != b) {
    auto vec = mvs(x, y);
    vector<pair<int, pair<int, int>>> po;
    for (auto &it : vec) {
      po.push_back({dist(it, a, b), it});
    }
    sort(po.begin(), po.end());
    x = po[0].second.first;
    y = po[0].second.second;
    cout << x << " " << y << endl;
    if (in_check(x, y)) {
      return 0;
    }
    int k, x, y;
    cin >> k >> x >> y;
    if (k == -1 || k == 0) {
      return 0;
    }
    s.erase(what[k]);
    what[k] = {x, y};
    s.insert(what[k]);
  }
  return 0;
}