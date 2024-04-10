#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int n, k;
	cin >> n >> k;
	ld l, r;
	ld a[n];
	for (int i = 0; i < n; i++){
		cin >> l >> r;
		a[i] = l / r;
	} 
	sort (a, a + n);
	cout << fixed << setprecision(10);
	cout << k * a[0];
}