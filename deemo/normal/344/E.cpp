//One of these days the mountains are gonna fall into the seas and they'll know..

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll max_n = 1e5 + 10;

ll n, m;
vector<ll>	vec, sec;
ll pos[max_n], pat[max_n];

void init(){
	for (ll i = 0; i < n; i++)
		pos[i] = upper_bound(sec.begin(), sec.end(), vec[i]) - sec.begin();
}

bool check(ll l, ll r, ll ind, ll x){
	ll c = 0, z = 0, y = 0;
	if (pos[ind] > l)
		y = vec[ind] - sec[l];
	
	if (pos[ind] <= r)
		z = sec[r] - vec[ind];
	if (z > y)	swap(y, z);
	c = 2 * z + y;
	return	c <= x;
}

bool ok(ll x){
	ll a = 0, b = 0;
	for (ll i = 0; i < vec.size(); i++){
		while (b < m && check(a, b, i, x))	b++;
		a = b;
	}
	return	b >= m;
}

int main(){
	scanf("%I64d%I64d", &n, &m);
	vec.resize(n);
	for (ll i = 0; i < n; i++)
		scanf("%I64d", &vec[i]);
	sec.resize(m);
	for (ll i = 0; i < m; i++)
		scanf("%I64d", &sec[i]);
	init();

	ll b = 0, e = 1e11, ret = 1e11, mid;
	while (b <= e){
		mid = (b + e)/ 2;
		if (ok(mid)){
			ret = mid;
			e = mid - 1;
		}
		else	b = mid + 1;
	}	
	printf("%I64d\n", ret);
	return 0;
}