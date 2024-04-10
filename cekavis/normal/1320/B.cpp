#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, m, k, r, ansl, ansr, a[N], q[N], dis[N];
bool vis[N];
vector<int> e[N], ie[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<=m; ++i)
		scanf("%d%d", &x, &y), e[x].push_back(y), ie[y].push_back(x);
	scanf("%d", &k);
	for(int i=1; i<=k; ++i) scanf("%d", a+i);
	q[r=1]=a[k], vis[a[k]]=1;
	for(int l=1; l<=r; ++l){
		int u=q[l];
		for(int v:ie[u]) if(!vis[v]) vis[v]=1, dis[v]=dis[u]+1, q[++r]=v;
	}
	for(int i=1; i<k; ++i){
		if(dis[a[i+1]]>=dis[a[i]]) ++ansl, ++ansr;
		else{
			for(int v:e[a[i]]) if(dis[v]==dis[a[i]]-1 && v!=a[i+1]){
				++ansr;
				break;
			}
		}
	}
	printf("%d %d\n", ansl, ansr);
	return 0;
}