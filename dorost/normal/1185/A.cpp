#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int a[3], k, ans = 0;
	cin >> a[0] >> a[1] >> a[2] >> k;
	sort (a, a +  3);
	if (a[1] - a[0] < k){
		ans += k - (a[1] - a[0]);
		a[0] = a[1] - k;
	}
	if (a[2] - a[1] < k){
		ans += k - (a[2] - a[1]);
		a[2] = a[1] + k;
	}
	cout << ans;
}