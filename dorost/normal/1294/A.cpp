#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		ll n, a, b, c;
		cin >> a >> b >> c >> n;
		ll s = a + b + c;
		ll d = s + n;
		if(d % 3 == 0 && d - (a + b + c) <= n && d / 3 >= max({a, b, c}))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}