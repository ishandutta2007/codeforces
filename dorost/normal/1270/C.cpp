#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n;
		int a = 0, b = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			a += x;
			b ^= x;
		}
		cout << 2 << endl << b << ' ' << a + b << endl;
	}	
}