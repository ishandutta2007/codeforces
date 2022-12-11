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
  int n;
  cin >> n;
  vi V(n), S(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    S[x] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> V[i];
    --V[i];
  }
  int ma = n+1;
  int res = 0;
  for (int i = n-1; i >= 0; --i) {
    if (S[V[i]] > ma) ++res;
    ma = min(ma, S[V[i]]);
  }
  cout << res << '\n';

}