#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll n, a[30];

int main(){
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	for (ll i = n - 1; i > 0; i--)
		if (a[i - 1] >= a[i])	a[i - 1] = a[i] - 1;
	long long ans = 0;
	for (ll i = 0; i < n; i++)	ans += max(0LL, a[i]);
	cout << ans << "\n";
	return	0;
}