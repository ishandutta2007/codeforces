#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin >> t;
	while (t--){
		ll n, g, b;
		cin >> n >> g >> b;
		ll s = (n + 1) / 2;
		cout << max(n, (((s + g - 1) / g) - 1) * (g + b) + min(g, s - ((((s + g - 1) / g) - 1) * g))) << endl;
	}
}