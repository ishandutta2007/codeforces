#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


int n;
ll k, x;
ll a[200007];


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k >> x;
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<ll> t;
  
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (a[i] + x < a[i + 1]) {
      t.pb((a[i + 1] - a[i] - 1) / x);
    }
  }

  int res = t.size() + 1;

  sort(all(t));


  for (auto x : t) {
    if (x <= k) {
      res--; k -= x;
    } else break;
  }

  cout << res;
}