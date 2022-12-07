#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

ll f[11][61][1 << 10];
ll g[11][61];
int q, b;
ll l, r;
int a[100];

void init(){
	for(int b = 2; b <= 10; ++b){
		f[b][0][0] = 1;
		for(int len = 1; len <= 60; ++len){
			for(int mask = 0; mask < 1 << b; ++mask){
				//int odd = __builtin_popcount(mask), even = b - odd;
				for(int i = 0; i < b; ++i)
					f[b][len][mask] += f[b][len - 1][mask ^ (1 << i)];
			}
			for(int i = 1; i < b; ++i)
				g[b][len] += f[b][len - 1][1 << i];
		}
	}
}

ll work(ll n, int b){
	int l = 0;
	while(n) a[++l] = n % b, n /= b;

	ll res = 0;
	int mask = 0;
	for(int i = l; i >= 1; --i){
		for(int j = i == l ? 1 : 0; j < a[i]; ++j)
			res += f[b][i - 1][mask ^ (1 << j)];
		if(i < l) res += g[b][i];
		mask ^= 1 << a[i];
	}
	return res;
}

int main(){
	init();
	scanf("%d", &q);
	while(q--){
		scanf("%d%lld%lld", &b, &l, &r);
		printf("%lld\n", work(r + 1, b) - work(l, b));
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}