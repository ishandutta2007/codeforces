/* 	* In the name of GOD 
	* Thanks God */
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
		int n, x;
		cin >> n >> x;
		int ans = 0;
		for (int i = 0; i < n - 1; i++){
			int u, v;
			cin >> u >> v;
			if (u == x || v == x)
				ans ++;
		}
		if (ans == 0 || ans == 1){
			cout << "Ayush\n";
		}else{
			cout << (n % 2 == 0 ? "Ayush" : "Ashish") << endl;
		}
	}
}