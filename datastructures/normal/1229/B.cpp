#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int n,a[100005],u[200005],v[200005],first[200005],nxt[200005],depth[100005],fa[100005][25],g[100005][25];
int ans;
int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
void dfs(int now,int f,int d,int last){
	depth[now]=d;
	fa[now][0]=f,g[now][0]=a[now];
	for (int i=1;i<=20;i++){
		fa[now][i]=fa[fa[now][i-1]][i-1];
		g[now][i]=gcd(g[now][i-1],g[fa[now][i-1]][i-1]);
	}
	int val=a[now],pos=now;
	if (val==0)ans=(ans+last)%mod;
	int awa=0;
	while(val>0&&pos!=0){
		int qwq=pos;
		for (int i=20;i>=0;i--)
			if (fa[pos][i]!=0&&g[pos][i]%val==0&&a[fa[pos][i]]%val==0)pos=fa[pos][i];
		awa=(awa+(depth[qwq]-depth[pos]+1)*val)%mod;
		pos=fa[pos][0];
		val=gcd(val,a[pos]);
	}
	ans=(ans+awa)%mod;
	if (a[now]>0)last=awa;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1,last);
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0,1,0);
	cout<<ans<<endl;
	return 0;
}