#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll a[3], l, ans, b[3];

ll get(ll rem){
	ll ret = (rem + 2) * (rem + 1)/ 2;
	if (b[0] <= rem)	
		ret -= ((rem - b[0]) + 2) * ((rem - b[0]) + 1)/ 2;
	if (b[1] <= rem)	
		ret -= ((rem - b[1]) + 2) * ((rem  - b[1]) + 1)/ 2;
	if (b[0] + b[1] <= rem)
		ret += ((rem - b[0] - b[1]) + 2) * ((rem - b[0] - b[1]) + 1)/ 2;
	return	ret;
}

int main(){
	for (ll i = 0; i < 3; i++)	cin >> a[i];	cin >> l;
	b[0] = 2, b[1] = 1;
	for (ll i = 0; i < 3; i++)
		for (ll j = 0; j <= l; j++){
			bool fl = 1;
			for (ll w = 0; w < 3; w++)
				if (i != w){
					if (w < i && a[w] >= a[i] + j)	fl = 0;
					if (w > i && a[w] > a[i] + j)	fl = 0;
				}
			if (!fl)	continue;

			ll t = 0;
			for (ll w = 0; w < 3; w++)
				if (i != w){
					if (w < i)	b[t++] = a[i] + j - a[w] - 1 + 1;
					if (w > i)	b[t++] = a[i] + j - a[w] + 1;
				}
			ans += get(l - j);
			ll sm = 0;
			for (ll w = 0; w < 3; w++)
				if (i != w)	sm += a[w];
			if (a[i] + j >= sm)
				ans -= get(min(a[i] + j - sm, l - j));
		}
	cout << ans << "\n";
	return	0;
}