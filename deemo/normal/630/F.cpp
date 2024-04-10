#include<iostream>

using namespace std;

typedef long long ll;

const ll MOD = 100;

int mark[20], g;

ll f(ll a, ll b){
	g++;
	ll ret = 1;
	for (ll j = a; j > a - b; j--){
		ret *= j;
		for (int i = 2; i <= b; i++)
			if (mark[i] != g && ret % i == 0){
				ret /= i;
				mark[i] = g;
			}
	}
	return	ret;
}

int main(){
	ll n, ans = 0;	cin >> n;
	for (ll i = 5; i <= 7; i++)
		ans += f(n, i);
	cout << ans << "\n";
	return	0;
}