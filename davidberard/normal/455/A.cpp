#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
ll dp[N];
ll ep[N];
ll amt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    int x;
    cin >> x;
    ++amt[x];
  }
  for (int i=1; i<N; ++i) {
    dp[i] = amt[i]*i + (i > 1 ? ep[i-2] : 0);
    ep[i] = max(ep[i-1], dp[i]);
  }
  cout << ep[N-1] << endl;
  return 0;
}