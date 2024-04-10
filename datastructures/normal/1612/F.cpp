#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define mod1 19260817
#define mod2 19999999
using namespace std;
map<int,int> d[500005];
int n,m,q,x,y,ans=1000000000;
bool qwq[20000005],awa[20000005];
int val[200005];
int f[200005],g[200005];
int id1(int x,int y){
	return (1ll*x*200000+y)%mod1;
}
int id2(int x,int y){
	return (1ll*x*200000+y)%mod2;
}
void dfs(int a,int b,int c){
	if (a==n&&b==m){
		ans=min(ans,c);
		return;
	}
	if (a==n){
	    ans=min(ans,g[b]+c);
	    return;
	}
	if (b==m){
	    ans=min(ans,f[a]+c);
	    return;
	}
	if (a+b<val[c-1]||c>200000)return;
	int x=a+b;
	if (qwq[id1(a,b)]&&awa[id2(a,b)]&&d[a][b]==1)x++;
	if (a!=n)dfs(min(x,n),b,c+1);
	if (b!=m)dfs(a,min(x,m),c+1);
	return;
}
int main(){
	cin>>n>>m;
	cin>>q;
	while(q--){
		scanf("%d%d",&x,&y);
		qwq[id1(x,y)]=1;
		awa[id2(x,y)]=1;
		d[x][y]=1;
	}
	int x=1,y=1;
	for (int i=1;i<=200000;i++){
		int qwq=x+y;
		if ((i&1)&&x<n)x=min(n,qwq);
		else y=min(m,qwq);
		val[i]=x+y;
	}
	for (int i=n-1;i>=1;i--){
	    if (d[i][m]==1)f[i]=f[min(n,i+1+m)]+1;
	    else f[i]=f[min(n,i+m)]+1;
	}
	for (int i=m-1;i>=1;i--){
	    if (d[n][i]==1)g[i]=g[min(m,i+1+n)]+1;
	    else g[i]=g[min(m,i+n)]+1;
	}
	dfs(1,1,0);
	cout<<ans<<endl;
	return 0;
}