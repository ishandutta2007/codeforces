#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	int x = n / 7;
	if (x == 0){
		if (n == 6)
			cout << 1 << ' ' << 2;
		else
			cout << 0 << ' ' << min(2, n);
		return 0;
	}
	if (n % 7 == 6){
		cout << x * 2 + 1 << ' ' << x * 2 + min(2, n % 7);
	}else
		cout << x * 2 << ' ' << x * 2 + min(2, n % 7);
}