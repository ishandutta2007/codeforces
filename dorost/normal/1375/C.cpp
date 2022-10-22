/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 301234;
int a[N], dp[N], dp1[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		/*bool h = false;
		for (int i = 1; i < n; i++){
			if (a[i] > a[i - 1])
				h = true;
		}
		if (!h){
			cout << "No\n";
			continue;
		}
		dp[0] = 1000000000000ll;
		for (int i = 1; i < n; i++){
			dp[i] = min(dp[i - 1], a[i - 1]);
		}
		dp1[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--){
			dp1[i] = max(dp1[i + 1] , a[i + 1]);
		}
		bool f = true;
		for (int i = 1; i < n - 1; i++){
			if (dp[i] > dp1[i])
				f = false;//, cout << a[i] << ':' << dp[i] << ',' << dp1[i] << endl;
		}
		*/
		cout << (a[n - 1] > a[0] ? "Yes" : "No") << endl;
	}
}