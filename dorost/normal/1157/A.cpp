#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int n, ans = 0;
	cin >> n;
	while (n > 9){
		n++;
		while (n % 10 == 0)
			n /= 10;
		ans ++;
	}
	cout << ans + 9;
}