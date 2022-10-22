#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n], b[n];
		bool f = true;
		for (int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
			if (i != 0){
				if (a[i] < a[i - 1] || b[i] < b[i - 1]){
					f = false;
				}
				if ((a[i] - a[i - 1]) < (b[i] - b[i - 1])){
					f = false;
				}
			}
			if (a[i] < b[i])
				f = false;
		}
		cout << (f ? "YES\n" : "NO\n");
	}
}