#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool f  = true;
		for (int i = 0; i < n - 1; i++){
			if (abs(a[i] - a[i + 1]) >= 2){
				cout << "YES" << endl;
				cout << i + 1  << ' ' << i + 2 << endl;
				f = false;
				break;
			} 
		}
		if (f){
			cout << "NO" << endl;
		}
	}
}