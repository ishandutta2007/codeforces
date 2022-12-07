#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
ll a[100100], b[100100];
vector<pair<int, int> > g[100100];
int x[100100], k[100100];
ll sum;
bool flag = 1;

void dfs(int t){
	for(auto e : g[t]){
		int v = e.se, k = e.fi;
		dfs(v);
		if(b[v] > 0) b[t] += b[v];
		else{
			double x = 1. * b[v] * k;
			if(b[t] + x < -sum) flag = 0;
			b[t] += b[v] * k;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", b + i), sum += b[i];
	for(int i = 1; i <= n; ++i) scanf("%lld", a + i), b[i] -= a[i];
	for(int i = 2; i <= n; ++i){
		scanf("%d%d", x + i, k + i);
		g[x[i]].pb(mkp(k[i], i));
	}
	dfs(1);
	flag &= b[1] >= 0;
	puts(flag ? "YES" : "NO");
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}