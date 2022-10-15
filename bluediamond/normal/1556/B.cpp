#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll) 1e18;

vector<int> gen(int n, int first) {
  vector<int> sol(n);
  for (int i = 0; i < n; i++) {
    sol[i] = (i + first) % 2;
  }
  return sol;
}

vector<vector<int>> distribution(vector<int> a) {
  vector<vector<int>> inds(2);
  for (int i = 0; i < (int) a.size(); i++) {
    inds[a[i]].push_back(i);
  }
  return inds;
}

ll dist(vector<int> x, vector<int> y) {
  auto a = distribution(x);
  auto b = distribution(y);
  if ((int) a[0].size() != (int) b[0].size()) {
    return INF;
  }
  assert((int) a[1].size() == (int) b[1].size());
  ll sol = 0;
  for (int i = 0; i < (int) a[0].size(); i++) {
    sol += abs(a[0][i] - b[0][i]);
  }
  return sol;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
      x %= 2;
    }
    ll sol = min(dist(a, gen(n, 0)), dist(a, gen(n, 1)));
    if (sol == INF) {
      sol = -1;
    }
    cout << sol << "\n";
  }
  return 0;
}