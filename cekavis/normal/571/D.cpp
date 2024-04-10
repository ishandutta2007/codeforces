#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005;
int n, m, a[N], b[N], last[N];
ll ans[N];
bool old[N];
vector<int> F[N], G[N], H[N], *f[N], *g[N], *h[N];
vector<pair<int,ll>> V[N], *v[N];
int find(int x, int *f){ return f[x]==x?x:f[x]=find(f[x], f);}
ll query(int x){
	int A=find(x, a), B=find(x, b);
	// printf(">> %d %lld\n", x, ans[x]);
	if(old[x]) return ans[x]+v[A]->back().second;
	return v[A]->back().second-(lower_bound(v[A]->begin(), v[A]->end(), make_pair(last[B], 0ll))-1)->second;
}
int main() {
	// freopen("1.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
		a[i]=b[i]=i, (v[i]=V+i)->push_back(make_pair(-1, 0)),
		(f[i]=F+i)->push_back(i), (g[i]=G+i)->push_back(i), h[i]=H+i;
	for(int ti=1; ti<=m; ++ti){
		char opt[3];
		int x, y;
		scanf("%s%d", opt, &x);
		if(opt[0]=='U'){
			scanf("%d", &y);
			bool t=f[x]->size()<f[y]->size();
			for(int i:*f[t?x:y])
				ans[i]=query(i)-v[t?y:x]->back().second, old[i]=1,
				h[find(i, b)]->push_back(i);
			if(t) swap(f[x], f[y]);
			f[x]->insert(f[x]->end(), f[y]->begin(), f[y]->end());
			if(t) swap(v[x], v[y]);
			a[find(y, a)]=x;
		}
		else if(opt[0]=='M'){
			scanf("%d", &y);
			bool t=g[x]->size()<g[y]->size();
			for(int i:*g[t?x:y])
				ans[i]=query(i)-v[find(i, a)]->back().second, old[i]=1,
				h[find(i, b)]->push_back(i);
			if(t) swap(g[x], g[y]), swap(last[x], last[y]);
			g[x]->insert(g[x]->end(), g[y]->begin(), g[y]->end());

			if(h[x]->size()<h[y]->size()) swap(h[x], h[y]);
			h[x]->insert(h[x]->end(), h[y]->begin(), h[y]->end());
			b[find(y, b)]=x;
		}
		else if(opt[0]=='A'){
			v[x]->push_back(make_pair(ti, f[x]->size()+v[x]->back().second));
		}
		else if(opt[0]=='Z'){
			last[x]=ti;
			for(int i:*h[x]) old[i]=0;
			h[x]->clear();
		}
		else printf("%lld\n", query(x));
	}
	return 0;
}