#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int main(){
	int b, g, n, ans = 0;
	cin >> b >> g >> n;
	for (int i = 0; i <= b; i++)
		for (int j = 0; j <= g; j++)
			ans += ((i + j) == n);
	cout << ans;
}