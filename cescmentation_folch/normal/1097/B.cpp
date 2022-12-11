#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<pld> vpld;
typedef vector<vpld> vvpld;

int main() {
  int n;
  cin >> n;
  int k[n];
  for (int i = 0; i < n; ++i) cin >> k[i];
  for (int mask = 0; mask < (1<<n); ++mask) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (mask&(1<<i)) {
        res = (res + k[i])%360;
      } else {
        res = (res - k[i] + 360)%360;
      }
    }
    if (res == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}