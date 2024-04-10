#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
int n,a[200005],u[200005],v[200005],first[200005],nxt[200005],f[200005],size[200005],leave[200005];
inline void dfs(int now){
	size[now]=a[now];
	if (!first[now]){
		leave[now]=1;
		f[now]=a[now];
		return;
	}
	for (int i=first[now];i;i=nxt[i])
		dfs(v[i]),size[now]+=size[v[i]],leave[now]+=leave[v[i]];
	int maxf=0;
	for (int i=first[now];i;i=nxt[i])
		maxf=max(maxf,f[v[i]]);
	maxf=max(maxf,(size[now]+leave[now]-1)/leave[now]);
	f[now]=maxf;
	return;
}
signed main(){
	cin>>n;
	for (int i=2;i<=n;i++){
		scanf("%lld",&u[i]);
		v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(1);
	cout<<f[1]<<endl;
	return 0;
}