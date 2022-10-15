#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int M = (int) 1e9 + 7;

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = (ll) r * a % M;
    }
    a = (ll) a * a % M;
    b /= 2;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = (ll) fact * i % M;
  }
  int sol = fact - pw(2, n - 1);
  if (sol < 0) {
    sol += M;
  }
  cout << sol <<"\n";

  return 0;
}