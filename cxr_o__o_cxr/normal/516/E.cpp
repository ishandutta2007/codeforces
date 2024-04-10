//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,m,d,kk,ans,b[N],g[N],tb[N],tg[N],t[N<<1];
inline bool comp(int x,int y){
	return (x%d<y%d)||(x%d==y%d&&x<y);
}
int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return a;}
	int g=exgcd(b,a%b,x,y);
	int t=y;y=x-a/b*y;x=t;
	return g;
}
inline int calc(){
	bool fl=(n<=tb[0]+tg[0]);
	int ret=-1;
	if(fl){
		for(int i=0,j=1,k=1;i<n;i++){
			if((j>tb[0]||tb[j]!=i)&&(k>tg[0]||tg[k]!=i)){fl=0;break;}
			if(i<m&&(j>tb[0]||tb[j]!=i||k>tg[0]||tg[k]!=i))ret=i;
			if(j<=tb[0]&&tb[j]==i)j++;
			if(k<=tg[0]&&tg[k]==i)k++;
		}
		if(fl)return ret;
		ret=0;
	}
	t[0]=0;
	for(int i=1;i<=tb[0];i++)t[++t[0]]=tb[i]*kk%n;
	for(int i=1;i<=tg[0];i++)t[++t[0]]=tg[i]*kk%n;
	sort(t+1,t+t[0]+1);
	if(t[1]==t[t[0]])return t[1]*m%n+(n-1)*m;
	ret=t[t[0]]*m%n+((t[1]-t[t[0]]+kk*n)%n-1)*m;
	for(int i=1;i<t[0];i++)
		if(t[i]!=t[i+1])ret=max(ret,t[i]*m%n+((t[i+1]-t[i])%n-1)*m);
	return ret;
}
signed main(){
	n=read();m=read();
	d=exgcd(n,m,b[0],g[0]);
	n/=d;m/=d;
	kk=(n>m)?((g[0]%n+n)%n):((b[0]%m+m)%m);
	b[0]=read();
	for(int i=1;i<=b[0];i++)b[i]=read();
	g[0]=read();
	for(int i=1;i<=g[0];i++)g[i]=read();
	if(d>b[0]+g[0]){puts("-1");return (0-0);}
	sort(b+1,b+b[0]+1,comp);
	sort(g+1,g+g[0]+1,comp);
	if(n<m)swap(n,m);
	for(int i=0,j=1,k=1;i<d;i++){
		tb[0]=tg[0]=0;
		while(j<=b[0]&&b[j]%d==i)tb[++tb[0]]=b[j++]/d;
		while(k<=g[0]&&g[k]%d==i)tg[++tg[0]]=g[k++]/d;
		if(!tb[0]&&!tg[0]){puts("-1");return (0-0);}
		ans=max(ans,calc()*d+i);
	}
	cout<<ans;
	return (0-0);
}