//Missed me!?

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, c[MAXN];
ll tl[MAXN], tr[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)	scanf("%d", &c[i]);
	for (int i = 1; i < n; i++)
		tl[i] = (c[i - 1] < 2?0:c[i - 1] - (c[i - 1] & 1) + tl[i - 1]);
	for (int i = n - 2; ~i; i--)
		tr[i] = (c[i] < 2?0:c[i] - (c[i] & 1) + tr[i + 1]);
	
	ll ans = 0, mx = 0;
	for (int i = 0; i < n; i++){
		ans = max(ans, tr[i] + mx);
		mx = max(mx, tl[i]);
		if (i + 1 < n){
			c[i]--;
			mx += 1 + (c[i] - (c[i] & 1));
		}
	}
	printf("%lld\n", ans);
	return 0;
}