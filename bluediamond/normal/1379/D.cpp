#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
ll h, m, k;

struct Segment {
  ll l;
  ll r;
};

vector<Segment> get(ll l, ll r) {
  l %= (m / 2);
  r %= (m / 2);
  vector<Segment> c;
  if (l <= r) {
    c.push_back({l, r});
  } else {
    c.push_back({l, m / 2 - 1});
    c.push_back({0, r});
  }
  return c;
}

vector<Segment> operator + (vector<Segment> a, vector<Segment> b) {
  map<ll, int> mp;
  for (auto &it : a) {
    mp[it.l]++;
    mp[it.r + 1]--;
  }
  for (auto &it : b) {
    mp[it.l]++;
    mp[it.r + 1]--;
  }
  vector<Segment> c;
  ll ant;
  int cur = 0;
  for (auto &it : mp) {
    if (cur > 0) {
      c.push_back({ant, it.first - 1});
    }
    ant = it.first;
    cur += it.second;
  }
  return c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> h >> m >> k;
  map<ll, vector<pair<bool, int>>> mp;
  if (k > 1) {
    for (int i = 1; i <= n; i++) {
      ll h2, m2, pos;
      cin >> h2 >> m2;
      pos = h2 * m + m2;
      /// pos is bad if we use t in [pos + 1, pos + k - 1] or [pos + m / 2 + 1, pos + m / 2 + k - 1]
      vector<Segment> c = get(pos + 1, pos + k - 1) + get(pos + m / 2 + 1, pos + m / 2 + k - 1);
      for (auto &it : c) {
        mp[it.l].push_back({1, i});
        mp[it.r + 1].push_back({0, i});
      }
    }
  }
  mp[0].push_back({0, 0});
  mp[0].pop_back();
  int best = (int) 1e9, who;
  for (int step = 1; step <= 2; step++) {
    if (step == 2) {
      cout << best << " " << who << "\n";
    }
    set<int> s;
    for (auto &it : mp) {
      if (it.first >= m / 2) {
        break;
      }
      vector<pair<bool, int>> vec = it.second;
      sort(vec.begin(), vec.end());
      for (auto &pr : vec) {
        if (pr.first == 1) {
          s.insert(pr.second);
        } else {
          s.erase(pr.second);
        }
      }
      if (step == 1) {
        if ((int) s.size() < best) {
          best = (int) s.size();
          who = it.first;
        }
      }
      if (step == 2 && who == it.first) {
        for (auto &idx : s) {
          cout << idx << " ";
        }
        cout << "\n";
        return 0;
      }
    }
  }
  return 0;
}