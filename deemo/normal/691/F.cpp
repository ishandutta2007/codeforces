#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 1e6 + 10;
const ll MAXVAL = 3e6 + 10;

ll n, sz;
pair<ll, ll>	vec[MAXN];
ll ss[MAXVAL];
ll cnt[MAXVAL], f[MAXVAL];
bool pr[MAXVAL + 5];
vector<ll>	dv;
pair<ll, ll>	sec[MAXN];

void gen(ll rem, ll cur = 1){
	if (rem == 0){
		dv.push_back(cur);
		return;
	}

	rem--;
	gen(rem, cur);
	for (ll j = 0; j < sec[rem].S; j++){
		cur *= sec[rem].F;
		gen(rem, cur);
	}
}

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++){
		ll temp;	scanf("%I64d", &temp);
		cnt[temp]++;
	}
	
	pr[0] = pr[1] = 1;
	for (ll i = 2; i < MAXVAL; i++)
		if (!pr[i])
			for (ll j = i; j < MAXVAL; j += i)
				f[j] = i, pr[j] = 1;
	
	ss[1] = ll(cnt[1]) * ll(cnt[1] - 1);

	for (ll i = 2; i < MAXVAL; i++){
		ss[i] = ss[i - 1];

		ll temp = i, t = 0;
		while (temp-1){
			if (!t || sec[t - 1].F != f[temp])
				sec[t++] = {f[temp], 1};
			else
				sec[t - 1].S++;
			temp /= f[temp];
		}
	
		dv.clear();
		gen(t);

		for (ll v:dv){
			if (v * v != i)
				ss[i] += ll(cnt[v]) * cnt[i/v];
			else
				ss[i] += ll(cnt[v]) * ll(cnt[v] - 1);
		}
	}

	ll q;	scanf("%I64d", &q);
	while (q--){
		ll p;	scanf("%I64d", &p);
		printf("%I64d\n", ll(n) * ll(n - 1) - ss[p - 1]);
	}
	return 0;
}