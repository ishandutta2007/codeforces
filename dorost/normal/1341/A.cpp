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
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		bool f = false, h = false;
		for (int i = a - b; i <= a + b; i++){
				if (i * n <= c + d)
					f = true;
				if (i * n >= c - d)
					h = true;
			
		}
		cout << (f && h ? "YES\n" : "NO\n");
	}
}