#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,s[1000005],u[1000005],v[1000005],nxt[1000005],first[1000005];
int a[1000005],maxs[1000005],flag=1;
inline void add(int uu,int vv,int i){
	u[i]=uu,v[i]=vv;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
inline int get(int now,int fa){
	maxs[now]=2e9;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		maxs[now]=min(maxs[now],get(v[i],now));
	}
	if (s[now]!=-1)maxs[now]=min(maxs[now],s[now]);
	return maxs[now];
}
inline void dfs(int now,int fa,int sum){
	if (s[now]==-1){
		if (maxs[now]!=2e9)s[now]=maxs[now];
		else s[now]=sum;
		a[now]=s[now]-sum;
		for (int i=first[now];i;i=nxt[i])
			if (v[i]!=fa)dfs(v[i],now,s[now]);
		return;
	}
	else{
		a[now]=s[now]-sum;
		for (int i=first[now];i;i=nxt[i])
			if (v[i]!=fa)dfs(v[i],now,s[now]);
		return;
	}
	return;
}
signed main(){
	cin>>n;
	for (int i=2;i<=n;i++){
		int f;
		scanf("%I64d",&f);
		add(f,i,i);
	}
	for (int i=1;i<=n;i++)scanf("%I64d",&s[i]);
	get(1,0);
	dfs(1,0,0);
	int ans=0; 
	for (int i=1;i<=n;i++)ans+=a[i];
	for (int i=1;i<=n;i++)
		if (a[i]<0)flag=0;
	if (flag==1)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}