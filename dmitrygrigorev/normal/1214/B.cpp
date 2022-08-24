#include <bits/stdc++.h>
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
	int b, g, n;
	cin >> b >> g >> n;
	int ans = 0;
	for (int i=0; i <= n; ++i){
		int B = i, G = n-i;
		if (B <= b && G <= g) ans++;
	}
	cout << ans;
}