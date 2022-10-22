#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}

ll f, w, hh;
ll ss[MAXN], tt[MAXN];

ll choose(ll a, ll b){
	if (min(a, b) < 0) return 0;
	if (b > a) return 0;
	return ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++) ss[i] = 1ll*ss[i-1]*i%MOD;
	tt[0] = tt[1] = 1;
	for (int i = 2; i < MAXN; i++) tt[i] = 1ll*tt[i-1]*pw(i,MOD-2)%MOD;

	cin >> f >> w >> hh;
	if (hh == 0||w==0){
		cout << "1\n";
		return 0;
	}
	ll c1 = 0, c2 = 0;
	if (f == 0){
		c2++;
		if (w > hh) c1++;
	}

	for (int i = 1; i <= f; i++){
		ll g = choose(f-1, i-1);

		ll h = choose(w-1+2, i);
		c2 = (c2 + h*g) % MOD;
		
		{
			ll rem = w - 1ll*i*(hh+1);
			if (rem >= 0)
				c1 = (c1 + choose(rem-1+i, i-1) * g) % MOD;
		}

		{
			ll rem = w - 1ll*i*(hh+1);
			if (rem >= 0)
				c1 = (c1 + choose(rem-1+i, i-1) * g) % MOD;
		}

		if (i - 1){
			ll rem = w - 1ll*(i-1)*(hh+1);
			if (rem >= 0)
				c1 = (c1 + choose(rem-1+(i-1), i-2) * g) % MOD;
		}

		{
			ll rem = w - 1ll*(i+1)*(hh+1);
			if (rem >= 0)
				c1 = (c1 + choose(rem-1+(i+1), i) * g) % MOD;
		}
	}

	cout << c1*pw(c2, MOD-2)%MOD << "\n";
	return 0;
}