#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int n,k,u[200005],v[200005],w[200005],first[200005],nxt[200005],book[200005],ans;
inline int read(){
	register int x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
inline int qpow(int a,int p){
	if (p==0)return 1;
	int t=qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int dfs(int now){
	if (book[now]==1)return 0;
	book[now]=1;
	int s=1;
	for (int i=first[now];i;i=nxt[i])
		if (w[i]==0)s+=dfs(v[i]);
	return s;
}
signed main(){
	cin>>n>>k;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read(),w[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i],w[i+n]=w[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	ans=qpow(n,k);
	for (int i=1;i<=n;i++)
		if (book[i]==0)ans-=qpow(dfs(i),k),ans%=mod;
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}