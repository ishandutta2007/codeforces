#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,E=524288,N=300005;
int t,n,a[N],ans,f[N],siz[1005],s,m,u,v;
int Find(int x){
	return f[x]?f[x]=Find(f[x]):x;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d %d",&u,&v);
		int x=Find(u),y=Find(v);
		if(x!=y)
			f[x]=y;
		else
			++s;
		memset(siz,0,sizeof(siz));
		for(int j=1;j<=n;++j)
			++siz[Find(j)];
		sort(siz+1,siz+1+n);
		int ans=0;
		for(int i=n;i>=n-s;--i)
			ans+=siz[i];
		printf("%d\n",ans-1);
	}
}