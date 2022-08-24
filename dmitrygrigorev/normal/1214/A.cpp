#include <bits/stdc++.h>
#define data suka
#define ll long long
#define db long double

using namespace std;
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, d, e;
	cin >> n >> d >> e;
	int ans = n;
	for (int i=0; i*d <= n; ++i){
		ans = min(ans, (n-i*d)%(5*e));
	}
	cout << ans;
}