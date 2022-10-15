#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

void print(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int n;
  cin >> n;
  vector<pair<int, int>> points(n);
  vector<vector<int>> nec(n);
  vector<bool> killed(n, false);
  for (auto &it : points) {
    cin >> it.first >> it.second;
  }
  vector<vector<int>> dists(n, vector<int> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dists[i][j] = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
    }
  }
  for (int i = 0; i < n; i++) {
    int Minimum = numeric_limits<int>::max();
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      Minimum = min(Minimum, dists[i][j]);
    }
    for (int j = 0; j < n; j++) {
      if (i == j) {
        nec[i].push_back(i);
        continue;
      }
      if (dists[i][j] == Minimum) {
        nec[i].push_back(j);
      }
    }
  }

  function<void(int)> kill = [&] (int a) {
    if (killed[a]) return;
    killed[a] = true;
  };

  for (int i = 0; i < n; i++) {

    for (auto &j : nec[i]) {
      if (nec[j] != nec[i]) {
        kill(i);
      }
    }
  }

  vector<int> dims;
  for (int i = 0; i < n; i++) {
    assert(!nec[i].empty());
    if (killed[i]) {
      dims.push_back(1);
    } else {
      if (i == nec[i][0]) {
        dims.push_back((int) nec[i].size());
      }
    }
  }
  vector<int> ways(n + 1, 0);
  ways[n] = 1;

  for (auto &d : dims) {
    vector<int> new_ways(n + 1, 0);
    for (int i = n; i >= 1; i--) {
      addup(new_ways[i - 1], ways[i]);
      if (d > 1 && i - d >= 0) {
        addup(new_ways[i - d], ways[i]);
      }
    }
    ways = new_ways;
  }

  int sol = 0, multiply = 1;
  for (int i = n; i >= 0; i--) {
    addup(sol, mul(ways[i], multiply));
    mulup(multiply, i);
  }
  cout << sol << "\n";
}