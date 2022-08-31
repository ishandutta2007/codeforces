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
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i=0;i<n;++i){
		cin >> a[i];
	}
	for (int i=0;i<n;++i) cin >> b[i];
	vector<int> best(n);
	int ans = 0;
	for (int i=0; i < n; ++i){
		for (int j=0; j < n; ++j){
			int X = a[i]^(a[i]&a[j]);
			if (X!=0) best[i]++;
		}
	}

	int sum = 0;
	for (int i=0;i<n;++i) sum += b[i];

	for (int i=0;i<n-1;++i){
		int cur = n-i-1;
		int kok = -1;
		for (int j=0; j < n; ++j){
			if (best[j] == cur) kok = j;
		}
		if (kok == -1){
			ans = max(ans, sum);
			break;
		}
		sum -= b[kok];
		best[kok] = -1;
		for (int j=0;j<n;++j){
			int X = a[j]^(a[kok]&a[j]);
			if (X!=0) best[j]--;
		}
	}
	cout << ans;
	
}