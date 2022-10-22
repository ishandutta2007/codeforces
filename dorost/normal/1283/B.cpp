#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int t;
	cin >> t;
	while (t--){
		ll n, k;
		cin >> n >> k;
		cout << n / k * k + (min(n % k, (k) / 2)) << endl;
	}
}