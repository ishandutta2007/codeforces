#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

long long l, r, g;
ll d[20];

long long gs(ll x){
	ll ret = 1;
	g = 0;
	while (x){
		ret *= 10;
		x /= 10;
		g++;
	}
	return ret / 10;
}

ll cal(ll x){	
	long long ret = 1;
	while (x)
		x--, ret *= 10;
	return	ret;
}

long long get(ll x){
	if (x / 10 == 0)	return	x;
	ll size = gs(x), ret = 0;
	for (ll i = 1; i < g; i++)	ret += d[i];

	ll t = (x / size) % 10;
	if (t > 1)	ret += cal(g - 2) * (t - 1);
	ll temp = t;
	g--;	size /= 10;

	while (g > 0){
		if (g == 1){
			if (x % 10 >= temp)	ret++;
			break;
		}
		t = (x / size) % 10;
		if (t != 0)	ret += cal(g - 2) * (t);
		size/=10, g--;
	}
	return	ret;
}

int main(){	
	d[1] = 9, d[2] = 9;
	for (ll i = 3; i <= 18; i++)
		d[i] = d[i - 1] * 10;
	cin >> l >> r;
	cout << get(r) - get(l - 1) << endl;
	return 0;
}