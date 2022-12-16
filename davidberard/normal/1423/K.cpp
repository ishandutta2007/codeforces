#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1001000;
bool inp[N];

void setup() {
  for (ll i=2; i<N; ++i) {
    if (inp[i]) {
      continue;
    }
    for (ll j=i*i; j<N; j+=i) {
      inp[j] = 1;
    }
  }
}

int ans[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int TT;
  cin >> TT;
  vector<pair<int, int>> queries;
  for (int i=1; i<=TT; ++i) {
    int x;
    cin >> x;
    queries.push_back({x, i});
  }
  sort(queries.begin(), queries.end());
  int cv = 1;
  ll nr = 2;
  int cur = 1;
  for (auto& [n, idx] : queries) {
    while (cv < n) {
      ++cv;
      if (!inp[cv]) {
        ++cur;
      }
    }
    while (nr*nr <= cv) {
      --cur;
      ++nr;
      while (inp[nr]) {
        ++nr;
      }
    }
    ans[idx] = cur;
  }
  for (int i=1; i<=TT; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}