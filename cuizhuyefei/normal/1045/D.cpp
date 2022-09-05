#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
#define eef(i,x)for(int i=head[x],y=e[i].to;y;i=e[i].next,y=e[i].to)
int read(){char c=getchar();int d=0,f=1;for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());return d*f;}
char Read(){char c=getchar();while(c<'0'||c>'9')c=getchar();return c;}
typedef pair<int,int>PII;
typedef long long LL;
const int N=200001;
int n,q;
int cnt,head[N];struct edge{int to,next;}e[N*2];
void addedge(int x,int y){e[++cnt]=(edge){y,head[x]};head[x]=cnt;}
void Addedge(int x,int y){addedge(x,y);addedge(y,x);}
int p[N],pp[N]; int fa[N];
void dfs(int f,int x){
	eef(i,x)if(y!=f)fa[y]=x,dfs(x,y);
}
int main(){
	n=read();
	ref(i,1,n)p[i]=read()*100,p[i]+=read();
	ref(i,2,n)Addedge(read()+1,read()+1);
	dfs(0,1); p[0]=100; fa[1]=0;
	LL ans=0;
	ref(i,1,n)ans+=p[fa[i]]*(100-p[i]);
	ref(i,1,n)pp[fa[i]]+=100-p[i];
	q=read();
	ref(i,1,q){
		int x=read()+1;int P=read()*100;P+=read();
		/*ans+=pp[x]*(P-p[x]); ans+=(p[x]-P)*p[fa[x]];
		pp[fa[x]]+=P-p[x]; */
		ans+=p[fa[x]]*((1-P)-(1-p[x]))+(P-p[x])*pp[x];
		pp[fa[x]]+=(100-P)-(100-p[x]);
		p[x]=P;printf("%.4lf\n",1.0*ans/10000);
	}
}