#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vi V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];
    int maxi = 0;
    bool tr = false;
    for (int i = 0; i < n; ++i) {
      maxi = max(V[i], maxi);
      if (V[i] == x) tr = true;
    }
    if (tr) cout << 1 << '\n';
    else {
      cout << max(2,(x + maxi -1)/maxi) << '\n';
    }
  }
}