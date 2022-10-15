#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = (int) 1e6 + 7;
int n;
ll s[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    n = (int) str.size();
    map<ll, ll> first;
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1];
      if (str[i - 1] == '+') {
        s[i]++;
      } else {
        s[i]--;
      }
    }
    for (int i = n; i >= 0; i--) {
      first[s[i]] = i;
    }
    ll mn = 0;
    for (int i = 1; i <= n; i++) {
      mn = min(mn, s[i]);
    }
    ll lim = -mn;
    lim--;
    ll sol = n;
    for (int x = 0; x <= lim; x++) {
      ll ini = sol;
      sol += first[-(x + 1)];
    }
    cout << sol << "\n";
  }
  return 0;
}