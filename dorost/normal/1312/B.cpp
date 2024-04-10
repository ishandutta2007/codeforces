#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		reverse(a, a + n);
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}
}