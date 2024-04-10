#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

string gen(string a, int k) {
  int n = (int) a.size();
  string s;
  for (int i = k - 1; i < n; i++) {
    s += a[i];
  }
  string s2;
  for (int i = 0; i < k - 1; i++) {
    s2 += a[i];
  }
  if ((n + k) % 2 == 0) {
    reverse(s2.begin(), s2.end());
  }
  s += s2;
  return s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, kmin = 1;
    string s, best;
    cin >> n >> s;
    best = s;
    for (int i = 2; i <= n; i++) {
      string cur = gen(s, i);
      if (cur < best) {
        best = cur;
        kmin = i;
      }
    }
    cout << best << "\n" << kmin << "\n";
  }

}