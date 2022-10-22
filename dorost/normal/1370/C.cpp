/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		if (n == 1){
			cout << "FastestFinger\n";
			continue;
		}
		if (n == 2){
			cout << "Ashishgup\n";
			continue;
		}
		if (n % 2){
			cout << "Ashishgup\n";
			continue;
		}
		int ans = 0;
		vector <int> v;
		for (int i = 2; i * i <= n; i ++){
			if (n % i)
				continue;
			if (i % 2){
				v.push_back(i);
			}
			int x = n / i;
			if (x == 1)
				continue;
			if (x % 2){
				v.push_back(n / i);
			}
		}
		sort (v.begin(), v.end());
		for (int i = 0; i < v.size(); i++){
			int x = v[i];
			while (n % x == 0){
				ans ++;
				n /= x;
			}
		}
//		cerr << ans << endl;
		if (n == 2){
			cout << (ans == 1 ? "FastestFinger" : "Ashishgup") << endl;
		}else{
			if (ans == 0){
				cout << "FastestFinger" << endl;
			}else{
				cout << ("Ashishgup") << endl;
			}
		}
	}
}