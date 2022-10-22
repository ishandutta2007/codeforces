#include<iostream>

using namespace std;

typedef long long ll;

int main(){
	ll k, b, n, t;	cin >> k >> b >> n >> t;
	int ans = n;
	ll a = k + b;
	while (a <= t)
		ans--, a = (a * k) + b;
	cout << max(0, ans) << endl;
	return 0;
}