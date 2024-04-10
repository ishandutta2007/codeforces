#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, m;
bool b[200100];
vector<int> g[200100];
int f[200100], from[200100];

void exgcd(ll a, ll b, ll &d, ll &x, ll &y){
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= x * (a / b);
}//ax+by=d

int get(int p, int v){
	ll g, x, y;
	exgcd(p, m, g, x, y);
	return ((ll)x * (v / g) % m + m) % m;
}

int print(int gcd){
	if(!gcd) return 1;
	int p = print(from[gcd]);
	for(auto v : g[gcd]){
		int x = get(p, v);
		printf("%d ", x);
		p = v;
	}
	return p;
}

int main(){
	scanf("%d%d", &n, &m);
	int x;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		b[x] = 1;
	}
	for(int i = 1; i < m; ++i){
		if(b[i]) continue;
		int gcd = __gcd(i, m);
		g[gcd].pb(i);
	}
	int p = 0;
	for(int i = 1; i < m; ++i){
		if(!g[i].size()) continue;
		for(int j = 2; j < m; ++j)
			if(g[(ll)i * j % m].size() && (ll)i * j % m != i)
				if(f[i] + g[i].size() > f[(ll)i * j % m])
					f[(ll)i * j % m] = f[i] + g[i].size(), from[(ll)i * j % m] = i;
		if(f[i] + g[i].size() > f[p] + g[p].size()) p = i;
	}
	printf("%d\n", f[p] + g[p].size() + !b[0]);
	print(p);
	if(!b[0]) printf("0\n");
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}