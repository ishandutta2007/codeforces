#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int32_t main(){
	ios::sync_with_stdio(0);
 	int n;
	cin >> n;
	int a[n];
	bool f = false, h = false;;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] % 2)
			f = true;
		else
			h = true;
	}
	if (f && h){
		sort (a, a + n);
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
}