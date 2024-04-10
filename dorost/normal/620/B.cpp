#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int l, r, ans = 0,a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	cin >> l >> r;
	for (int x = l; x <= r; x++){
		int m = x;
		while(m){
			ans += a[m % 10];
			m /= 10;	
		}
	}	
	cout << ans;
}