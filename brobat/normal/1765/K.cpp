#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<vector<int64_t>> a(n, vector<int64_t>(n));
  int64_t A =0;
  for (auto& x : a){
    for (auto& y : x) {
      cin >> y;
      A += y;
    }
  }
  int64_t ans = 0;
  for (int i =0; i < n; i++){
    ans = max(ans, A - a[i][n - 1 - i]);
  }
  cout << ans << '\n';
}