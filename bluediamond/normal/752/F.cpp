/// similar thinking to the centroid
#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, k, u[N], root, tt[N];
bool ii[N];
vector<int> g[N];

void dd(int a, int p) {
  tt[a] = p;
  for (auto &b : g[a]) {
    if (b != p) {
      dd(b, a);
      u[a] += u[b];
    }
  }
}

vector<int> r;

void dd2(int a, int p) {
  if (ii[a]) {
    r.push_back(a);
  }
  for (auto &b : g[a]) {
    if (b != p) {
      dd2(b, a);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= 2 * k; i++) {
    int a;
    cin >> a;
    u[a] = ii[a] = 1;
  }
  dd(1, -1);
  for (int i = 1; i <= n; i++) {
    bool ok = 1;
    ok &= (u[i] >= k);
    for (auto &j : g[i]) {
      if (j != tt[i]) {
        ok &= (u[j] <= k);
      }
    }
    if (ok) {
      root = i;
      break;
    }
  }

  if (ii[root]) {
    r.push_back(root);
  }
  for (auto &i : g[root]) {
    dd2(i, root);
  }
  cout << "1\n" << root << "\n";
  for (int i = 0; i < k; i++) {
    cout << r[i] << " " << r[i + k] << " " << root << "\n";
  }
}