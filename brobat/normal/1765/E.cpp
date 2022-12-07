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

  int tt;
  cin >> tt;
  while(tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b) {
      cout << 1 << '\n';
    } else {
      cout << (n+a-1)/a << '\n';
    }
  }
}