#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long 

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort (a, a + n);
		reverse (a, a + n);
		int sum = 0, an = 0;
		for (int i = 0; i < n; i++){
			sum += a[i];
			if (sum / (i + 1) >= x)
				an = i + 1;
		}
		cout << an << endl;
	}
}