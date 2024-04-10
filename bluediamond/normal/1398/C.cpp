#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    string s;
    cin >> n >> s;
    ll sol = 0;
    map<int, int> f;
    f[0]++;
    for (int i = 1; i <= n; i++) {
      sum += s[i - 1] - '0' - 1;
      sol += f[sum]++;
    }
    cout << sol << "\n";
  }
  return 0;
}
/**
**/