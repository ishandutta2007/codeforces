#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n;
ll x, y;

bool grt(ll a, ll b, ll c, ll d){return	a * d >= c * b;}

ld dif(ld a, ld b, ld c, ld d){
	ld ret = abs((a * d - c * b) / (b * d));
	if (ret < 0)	ret *= -1.0;
	return	ret;
}

int main(){
	cin >> x >> y >> n;
	ll aa = -1, bb = -1;
	for (ll i = 1; i <= n; i++){
		ll b = 0, e = 1e9, mid, ret = 0;
		while (b <= e){
			mid = (b + e)/ 2;
			if (grt(x, y, mid, i)){
				ret = mid;
				b = mid + 1;
			}
			else	e = mid - 1;
		}

		if (aa == -1 || dif(x, y, ret, i) < dif(x, y, aa, bb))
			aa = ret, bb = i;

		ret++;
		if (aa == -1 || dif(x, y, ret, i) < dif(x, y, aa, bb))
			aa = ret, bb = i;
	}
	cout << aa << "/" << bb << endl;
	return 0;
}