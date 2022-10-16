#include <iostream>
#include <cstdio>
#define int long long
#define inf 1000000000000000
using namespace std;
int n,u[200005],v[200005],first[200005],nxt[200005];
int s[200005],a[200005];
int ans,fg=1;
void dfs(int now,int fa){
	if (s[now]==-1){
		s[now]=inf;
		for (int i=first[now];i;i=nxt[i])s[now]=min(s[now],s[v[i]]);
		if (s[now]==inf)s[now]=s[fa];
	}
	a[now]=s[now]-s[fa];
	if (a[now]<0)fg=0;
	else ans+=a[now];
	for (int i=first[now];i;i=nxt[i])dfs(v[i],now);
	return;
}
signed main(){
	cin>>n;
	for (int i=2;i<=n;i++){
		scanf("%lld",&u[i]);
		v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	for (int i=1;i<=n;i++)scanf("%lld",&s[i]);
	dfs(1,0);
	if (fg==1)cout<<ans<<endl;
	else puts("-1");
	return 0;
}