#include<iostream>

using namespace std;

typedef long long ll;

ll n;
ll mark[10];

int main(){
	cin >> n;
	ll ans = 1;
	for (ll i = n + 3 - 1; i > n - 1; i--){
		ans *= i;
		if (mark[2] == 0 && ans % 2 == 0)	mark[2] = 1, ans /= 2;
		if (mark[3] == 0 && ans % 3 == 0)	mark[3] = 1, ans /= 3;
	}
	
	for (ll i = 1; i < 7; i++)
		mark[i] = 0;
	
	for (ll i = n + 5 - 1; i > n - 1; i--){
		ans *= i;
		for (ll j = 2; j <= 5; j++)
			if (mark[j] == 0 && ans % j == 0){
				mark[j] = 1;
				ans /= j;
			}
	}
	cout << ans << "\n";
	return	0;
}