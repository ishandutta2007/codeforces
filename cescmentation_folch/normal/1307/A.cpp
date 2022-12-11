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
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vi V(n);
    for (int i = 0; i < n; ++i) {
      cin >> V[i];
    }
    int res = V[0];
    for (int i = 1; i < n; ++i) {
      int k = min(V[i],d/i);
      d -= k*i;
      res += k;
    }
    cout << res << '\n';
  }

}