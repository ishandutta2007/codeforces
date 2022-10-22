#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, k, c = 0;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
		if (5 - a[i] >= k)
			c++;
	cout << c / 3;
}