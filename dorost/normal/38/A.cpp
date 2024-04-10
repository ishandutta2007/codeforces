#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n - 1], l, r, ans = 0;
	for (int i = 0; i < n- 1; i++){
		cin >> a[i];
	}
	cin >> l >> r;
	for (int i = l; i < r; i++){
		ans += a[i - 1];
	}
	cout << ans;
}