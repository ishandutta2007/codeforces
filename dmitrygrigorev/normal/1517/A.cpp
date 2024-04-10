#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {

  ll x;
  cin >> x;

  if (x%2050 != 0) {
    cout << "-1\n";
    return;
  }

  x /= 2050;
  int ans = 0;
  while (x != 0) {
    ans += (x%10);
    x /= 10;
  }

  cout << ans << '\n';

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}