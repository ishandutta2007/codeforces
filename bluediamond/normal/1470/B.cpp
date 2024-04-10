#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e6 + 7;
bool prime[N];
int nosq[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  nosq[1] = 1;
  for (int i = 2; i < N; i++) {
    prime[i] = 1;
    nosq[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = 2 * i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (int i = 1; i * i < N; i++) {
    if (prime[i]) {
      int x = i * i;
      for (int j = x; j < N; j += x) {
        while (nosq[j] % x == 0) {
          nosq[j] /= x;
        }
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> f;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      f[nosq[x]]++;
    }
    int alpha = 0, beta = 0;
    for (auto &it : f) {
      alpha = max(alpha, it.second);
    }
    for (auto &it : f) {
      if (it.first == 1 || it.second % 2 == 0) {
        beta += it.second;
      }
    }
    beta = max(alpha, beta);
    int q;
    cin >> q;
    while (q--) {
      ll x;
      cin >> x;
      if (x) {
        cout << beta << "\n";
      } else {
        cout << alpha << "\n";
      }
    }

  }
}