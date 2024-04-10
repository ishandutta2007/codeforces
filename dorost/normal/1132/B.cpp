#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, m;
	cin >> n;
	int a[n], y;
	ll x = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		x += a[i];
	}
	sort(a, a + n);
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> y;
		cout << x - a[n - y] << endl;
	}	
}