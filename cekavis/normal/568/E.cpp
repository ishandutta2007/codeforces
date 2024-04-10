#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, m, mx, last, a[N], b[N], c[N], d[N], f[N], g[N], pre[N], ans[N];
bool vis[N];
vector<int> v[N];
bool cmp(int x, int y){ return a[x]<a[y];}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	scanf("%d", &m);
	for(int i=1; i<=m; ++i) scanf("%d", b+i);
	sort(b+1, b+m+1);
	fill(c+1, c+n+1, 2e9);
	for(int i=1; i<=n; ++i) if(~a[i]){
		f[i]=lower_bound(c+1, c+n+1, a[i])-c, g[i]=d[f[i]-1];
		c[f[i]]=a[i], d[f[i]]=i, v[f[i]].push_back(i);
		mx=max(mx, f[i]);
	}
	else{
		int k=n;
		for(int j=m; j; --j){
			while(c[k-1]>=b[j]) --k;
			c[k]=b[j], d[k]=i;
			mx=max(mx, k);
		}
		pre[i]=last, last=i;
	}
	for(int i=d[mx], x=c[mx], id=mx; id; --id){
		if(~a[i]) i=g[i], x=~a[i]?a[i]:*(lower_bound(b+1, b+m+1, x)-1);
		else{
			ans[i]=x, vis[lower_bound(b+1, b+m+1, x)-b]=1;
			while(v[id-1].size() && (v[id-1].back()>i || a[v[id-1].back()]>=x))
				v[id-1].pop_back();
			if(v[id-1].empty()) i=pre[i], x=*(lower_bound(b+1, b+m+1, x)-1);
			else i=v[id-1].back(), x=a[i];
		}
	}
	for(int i=1, j=1; i<=n; ++i)
		if(ans[i] || ~a[i]) printf("%d ", ~a[i]?a[i]:ans[i]);
		else{ 
			while(vis[j]) ++j;
			printf("%d ", b[j++]);
		}
	return 0;
}