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

const int inf = (1e9) + 7;

int n, q, r;
ll p;
int x;

int main(){
	scanf("%d%lld%d%d", &n, &p, &q, &r);

	ll f, g, h, x;
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &x);
		if(i == 1) f = p * x, g = f + q * x, h = g + r * x;
		else{
			f = max(f, p * x);
			g = max(g, f + q * x);
			h = max(h, g + r * x);
		}
	}
	printf("%lld\n", h);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}