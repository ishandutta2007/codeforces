#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int n, x, t;
    cin >> n >> x >> t;

    int go = t/x;
    go = min(go, n - 1);

    int ans = n * go - go*(go + 1) / 2;
    cout << ans << '\n';


  }

}