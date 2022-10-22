#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, m;
	cin >> n >> m;
	int a[m];
	cin >> a[0];
	ll ans = a[0] - 1;
	for (int i = 1; i < m; i++){
		cin >> a[i];
		if(a[i] < a[i - 1])
			ans += n - (a[i - 1] - a[i]);
		else
			ans += a[i] - a[i - 1]; 
	}
	cout << ans;//finish
}