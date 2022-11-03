#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    ll n, x, t;
    cin >> n >> x >> t;
    ll res = 0;

    ll cc = t / x;

    ll f1 = min(cc, n);
    ll f2 = n - f1;

    res += f2 * cc;
    res += f1 * (f1 - 1) / 2;

    cout << res << endl;
  }

}