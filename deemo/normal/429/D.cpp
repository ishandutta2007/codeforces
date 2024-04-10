#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int C = 500;

int n, a[MAXN];
ll p[MAXN];

ll get(ll l, ll r){
	ll ret = (r - l) * (r - l);
	ret += (p[r + 1] - p[l + 1]) * (p[r + 1] - p[l + 1]);
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), p[i + 1] = p[i] + a[i];
	
	ll ans = 5e18;
	for (int i = 0; i < n; i++){
		for (int j = i - 1; ~j && j > i - C; j--)
			ans = min(ans, get(j, i));
		for (int j = 0; j < i && j < C; j++)
			ans = min(ans, get(j, i));
	}
	printf("%lld\n", ans);
	return 0;
}