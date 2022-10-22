#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int ans = n;
	for (int i = 1; i <= n; i++){
		if(i % a && i % b && i % c && i % d)
			ans--;
	}
	cout << ans;
}