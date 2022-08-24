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
	freopen("P_input.txt", "r", stdin);
	//freopen("P_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; ++i) cin >> v[i];

	int sum = 0;

	for (int i=0;i<n;++i) sum += v[i];
	if (sum==1){
		cout << "-1";
		exit(0);
	}

	vector<int> pd;
	int Q = sum;

	for (int i=2; i * i <= Q; ++i){
		if (sum % i == 0){
			pd.push_back(i);
			while (sum % i == 0) sum /= i;
		}
	}

	if (sum != 1) pd.push_back(sum);

	//for (int i=0;i<pd.size(); ++i) cout <<pd[i] <<" ";

	int ans = 1e18;

	for (int i=0; i < pd.size(); ++i){
		int dv = pd[i];
		int S = 0;
		int tut = 0;
		for (int j=0; j < n; ++j){
			S += v[j];
			int R = S%dv;
			tut += min(R, dv-R);
		}
		ans = min(ans, tut);
	}

	cout << ans;

}