#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n, a[N], b[N];
int go[N];
vector<int> av[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    go[a[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    av[go[i]].push_back(i);
  }
  set<int> po;
  for (int i = 1; i <= n; i++) {
    for (auto &x : av[i - 1]) {
      po.insert(x);
    }
    b[i] = *po.begin();
    po.erase(b[i]);
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
  return 0;
}