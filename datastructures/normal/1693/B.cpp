#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath> 
#define int long long
using namespace std;
int t,n,u[200005],v[200005],first[200005],nxt[200005];
int l[200005],r[200005],f[200005];
int ans;
void dfs(int now,int fa){
	int s=0;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa){
			dfs(v[i],now);
			s+=f[v[i]];
		}
	if (s<l[now]){
		ans++;
		f[now]=r[now];
	}
	else f[now]=min(s,r[now]);
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=2;i<=n;i++){
			scanf("%lld",&u[i]);
			v[i]=i;
			nxt[i]=first[u[i]],first[u[i]]=i;
		}
		for (int i=1;i<=n;i++)scanf("%lld%lld",&l[i],&r[i]);
		dfs(1,0);
		cout<<ans<<endl;
		ans=0;
		for (int i=0;i<=n;i++)first[i]=nxt[i]=f[i]=0;
	}
	return 0;
}