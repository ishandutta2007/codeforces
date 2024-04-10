#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll n, a[5];
ll ans;

int main(){
	cin >> n;
	cin >> a[0] >> a[1] >> a[3] >> a[2];
	ll mn = 1e9;
	for (int i = 0; i < 4; i++)
		mn = min(mn, a[i] + a[(i+1)%4]);
	ll mx = 0;
	for (int i = 0; i < 4; i++)
		mx = max(mx, a[i] + a[(i+1)%4]);
	ll dif = mx - mn;
	cout << max(0LL, n * (n-dif)) << "\n";
	return 0;
}