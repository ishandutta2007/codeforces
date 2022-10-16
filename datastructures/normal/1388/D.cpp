#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[200005],b[200005],f[200005],ans;
int u[200005],v[200005],first[200005],nxt[200005];
inline void dfs(int now){
	f[now]=a[now];
	for (int i=first[now];i;i=nxt[i]){
		dfs(v[i]);
		if (f[v[i]]>0)f[now]+=f[v[i]];
	}
	return;
}
inline void out(int now){
	for (int i=first[now];i;i=nxt[i])
		if (f[v[i]]>0)out(v[i]);
	printf("%lld ",now);
	for (int i=first[now];i;i=nxt[i])
		if (f[v[i]]<=0)out(v[i]);
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)scanf("%lld",&b[i]);
	for (int i=1;i<=n;i++){
		if (b[i]!=-1){
			u[i]=b[i],v[i]=i;
			nxt[i]=first[u[i]],first[u[i]]=i;
		}
	}
	for (int i=1;i<=n;i++)
		if (b[i]==-1)dfs(i);
	for (int i=1;i<=n;i++)ans+=f[i];
	cout<<ans<<endl;
	for (int i=1;i<=n;i++)
		if (b[i]==-1)out(i);
	return 0;
}