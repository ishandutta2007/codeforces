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

const int oo = 1e9, maxn = 255, maxe = 1000001;
int e = 1, to[maxe], ne[maxe], he[maxn], cap[maxe], cost[maxe];
int d[maxn], vis[maxn], ln[maxe], l, r, S, T, fl[maxn], inx, from[maxn];
int ans;
int n, q;
int mi[maxn], mx[maxn];

void link(int x, int y, int v, int c){
	to[++e] = y, ne[e] = he[x], he[x] = e, cap[e] = 0, cost[e] = c;
	to[++e] = x, ne[e] = he[y], he[y] = e, cap[e] = v, cost[e] = -c;
}

bool spfa(){
	memset(d, 127, sizeof(d));
	d[S] = 0, fl[S] = oo;
	for(vis[ln[l = r = 1] = S] = ++inx; l <= r; vis[ln[l++]] = 0){
		for(int j = he[ln[l]]; j; j = ne[j])
			if(cap[j ^ 1] && d[to[j]] > d[ln[l]] + cost[j]){
				d[to[j]] = d[ln[l]] + cost[j];
				fl[to[j]] = min(fl[ln[l]], cap[j ^ 1]);
				from[to[j]] = j;
				if(vis[to[j]] < inx){
					vis[to[j]] = inx;
					ln[++r] = to[j];
				}
			}
	}
	if(d[T] > oo) return 0;
	int f = fl[T]; ans += f * d[T];
	for(int t = T; t != S; t = to[from[t] ^ 1])
		cap[from[t]] += f, cap[from[t] ^ 1] -= f;
	return 1;
}

void init(){
	e = 1;
	memset(he, 0, sizeof(he));
}

int solve(){
	init();
	S = 2 * n + 1, T = S + 1;
	for(int i = 1; i <= n; ++i){
		if(mi[i] > mx[i]) return -1;
		for(int j = mi[i]; j <= mx[i]; ++j)
			link(j, i + n, 1, 0);
		link(i + n, T, 1, 0);
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			link(S, i, 1, j * j - (j - 1) * (j - 1));
	while(spfa());
	return ans;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		mi[i] = 1, mx[i] = n;
	for(int i = 1; i <= q; ++i){
		static int ty, l, r, v;
		scanf("%d%d%d%d", &ty, &l, &r, &v);
		if(ty == 1){
			for(int j = l; j <= r; ++j)
				mi[j] = max(mi[j], v);
		}else{
			for(int j = l; j <= r; ++j)
				mx[j] = min(mx[j], v);			
		}
	}
	
	printf("%d\n", solve());
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}