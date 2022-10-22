/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int an1 = -1;
		for (int i = 1; i * i <= n; i++){
			if (n % i == 0){
				an1 = max(an1, i);
				if (n / i <= n / 2)
					an1 = max(an1, n / i);
			}
		}
		if (an1 == -1){
			cout << "1 " << n << endl;
		}else{
			cout << an1 << ' ' << n - an1 << endl;
		}
	}
}