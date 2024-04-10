#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = 2e18;

ll get(int n) {
  if (n == 0) return 1;
  if (n > 61) return INF;
  return (1LL<<(n-1));
}

void solve() {
  int n;
  ll k;
  cin >> n >> k;

  int add = 0;

  if (get(n) < k) {
    cout << "-1\n";
    return;
  }

  while (n > 0) {
    vector<int> res;
    while (true) {
      n--;
      ll T = get(n);
      res.pb(add++);
      if (k <= T) {
        break;
      }
      k -= T;
    }
    reverse(all(res));
    for (auto x : res) cout << x+1 << " ";
  }

  cout << '\n';

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}