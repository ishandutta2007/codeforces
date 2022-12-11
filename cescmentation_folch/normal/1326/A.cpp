#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << -1 << '\n';
      continue;
    }
    if ((n-1)%3 == 0) {
      for (int i = 0; i + 2 < n; ++i) cout << '2';
      cout << "33\n";
    }
    else {
      for (int i = 0; i + 1 < n; ++i) cout << '2';
      cout << "3\n";
    }
  }
}