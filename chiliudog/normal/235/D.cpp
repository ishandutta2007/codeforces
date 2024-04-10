#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b);
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=3005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int head[maxn],ne[maxn<<1],t[maxn<<1],S[maxn],top,cycle,num,n,belong[maxn],dis[maxn];
bool ins[maxn],ok,oncy[maxn];
double ans=0;
inline void addedge(int x,int y){ne[++num]=head[x];head[x]=num;t[num]=y;}
inline void findcycle(int u,int fa){
	S[++top]=u;ins[u]=1;
	for(int i=head[u];i!=-1;i=ne[i])if(t[i]!=fa){
		if(ok)return;
		if(ins[t[i]]){
			while(S[top]!=t[i])oncy[S[top--]]=1,cycle++;cycle++;oncy[t[i]]=1;ok=1;
			return;
		}
		findcycle(t[i],u);
	}top--;
}
inline void dfs_find(int u,int fa,int rt,int d){
	belong[u]=rt;dis[u]=d;
	for(int i=head[u];i!=-1;i=ne[i])if(t[i]!=fa&&!oncy[t[i]])
		dfs_find(t[i],u,rt,d+1);
}int p,first;
inline void dfs_ans(int u,int fa,int d){
	if(u==belong[p]){
		if(first)return;first+=1;
	}
	ans+=1.0/(d+1);
	for(int i=head[u];i!=-1;i=ne[i])if(t[i]!=fa){
		 dfs_ans(t[i],u,d+1);
	}
}
int main(){
	read(n);
	rep(i,1,n)head[i]=-1;
	rep(i,1,n){int a,b;read(a);read(b);a++;b++;addedge(a,b);addedge(b,a);}
	findcycle(1,-1);
	rep(i,1,n)if(oncy[i])dfs_find(i,-1,i,0);
	rep(i,1,n)
		p=i,first=0,dfs_ans(i,-1,0);
	rep(i,1,n)rep(j,1,n)if(belong[i]!=belong[j])ans-=1.0/(dis[i]+dis[j]+cycle);
	printf("%.23lf\n",ans);
	return 0;
}