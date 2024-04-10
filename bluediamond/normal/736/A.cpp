#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1000 + 7;
int need[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  need[0] = 1;
  need[1] = 2;
  for (int i = 2; i < N; i++) {
    need[i] = need[i - 1] + need[i - 2];
  }

  int n, sol = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (need[i] > n) break;
    sol = i;
  }
  cout << sol << "\n";
}