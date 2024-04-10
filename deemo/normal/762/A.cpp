#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, k;
	cin >> n >> k;
	ll i;
	for (i = 1; i * i <= n; i++)
		if (n % i == 0){
			k--;
			if (k == 0){
				cout << i << "\n";
				return 0;
			}
		}
	while (i*i >= n)	i--;
	for (; i; i--)
		if (n % i == 0){
			k--;
			if (k == 0){
				cout << n/i << "\n";
				return 0;
			}
		}
	cout << "-1\n";
	return 0;
}