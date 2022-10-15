#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 100000 + 7;
int n;

vector<int> rep(vector<int> v) {
  vector<int> ret;
  int last = -(int) 1e9;
  for (auto &x : v) {
    if (x == 0) continue;
    if (x != last) {
      last = x;
      ret.push_back(x);
    }
  }
  return ret;
}

vector<int> get(vector<int> v) {
  v = rep(v);
  if (v.empty()) return {};
  if ((int) v.size() == 1 && abs(v[0]) == 1) return v;
  bool odd = 0;
  for (auto &x : v) {
    if (x % 2 != 0) {
      odd = 1;
    }
  }
  if (!odd) {
    for (auto &x : v) {
      x /= 2;
    }
    auto ret = get(v);
    for (auto &x : ret) {
      x *= 2;
    }
    return ret;
  }
  vector<int> f = v, s = v;
  for (auto &x : f) if (x % 2 != 0) x++;
  for (auto &x : s) if (x % 2 != 0) x--;
  for (auto &x : f) x /= 2;
  for (auto &x : s) x /= 2;
  vector<int> ff = get(f), ss = get(s);
  for (auto &x : ff) x *= 2;
  for (auto &x : ss) x *= 2;
  if ((int) ff.size() < (int) ss.size()) {
    ff.push_back(-1);
    return ff;
  } else {
    ss.push_back(1);
    return ss;
  }
}

signed realMain() {
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
  }
  sort(v.begin(), v.end());
  auto ret = get(v);
  cout << (int) ret.size() << "\n";
  for (auto &it : ret) {
    cout << it << " ";
  }
  cout << "\n";
  return 0;
}