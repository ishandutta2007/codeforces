//Only memories we thought we could deny..

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, a[MAXN], sm;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (ll i = 0; i < n; i++)	cin >> a[i], sm += a[i];	sort(a, a + n);
	ll b = 0, e = 2e9, ret = 2e9;
	while (b <= e){	
		ll mid = (b + e)/ 2;
		if (mid >= a[n - 1] && sm <= mid * (n - 1))
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	cout << ret << "\n";
	return	0;		
}