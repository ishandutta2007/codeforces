#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
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
/*******************************head*******************************/
map<int,int> app;
const int maxn=10005;
vector<pin> rec[maxn];
int tot=0;
int n,m;
inline void divide(int v,int o){
	int x=sqrt(v)+1;
	rep(i,2,x){
		if(v%i==0){
			int nd=0;
			if(app.count(i))
				nd=app[i];
			else
				nd=app[i]=++tot;
			int cnt=0;
			while(v%i==0)v/=i,cnt++;
			rec[nd].pb(mk(o,cnt));
		}
	}
	if(v!=1){
		int nd=0;
		if(app.count(v))
			nd=app[v];
		else
			nd=app[v]=++tot;
		rec[nd].pb(mk(o,1));
	}
}
int x[maxn],y[maxn],num[maxn];
const int inf=1<<29;
namespace solve{
	const int maxnd=205;
	const int maxm=505;
	int head[maxnd],num,t[maxm<<1],ne[maxm<<1],sap[maxm<<1];
	int jl,S,T,cur[maxnd],his[maxnd],edge[maxnd],pre[maxnd],d[maxnd],cnt[maxnd];
	inline void addedge(int x,int y,int z){
		ne[++num]=head[x];head[x]=num;t[num]=y;sap[num]=z;
		ne[++num]=head[y];head[y]=num;t[num]=x;sap[num]=0;
	}
	inline void clear(){
		S=n+1;T=n+2;num=1;
		rep(i,1,T)head[i]=-1;
		memset(cnt,0,sizeof(cnt));
		memset(d,0,sizeof(d));
	}
	inline int isap(){
		rep(i,1,T)cur[i]=head[i];cnt[0]=T;int i=S,aug=inf,mini,jl,ans=0;
		while(d[S]<T){
			his[i]=aug;bool flag=0;for(int j=cur[i];j!=-1;j=ne[j])if(sap[j]&&(d[t[j]]+1==d[i])){
				flag=1;aug=min(aug,sap[j]);cur[i]=j;edge[i]=j;pre[t[j]]=i;i=t[j];
				if(i==T){
					ans+=aug;while(i!=S){i=pre[i];sap[edge[i]]-=aug;sap[edge[i]^1]+=aug;}aug=inf;
				}break;
			}if(flag)continue;mini=T;forE(j,i)if(sap[j]&&mini>d[t[j]])mini=d[t[j]],jl=j;
			if(--cnt[d[i]]==0)return ans;cnt[d[i]=mini+1]++;cur[i]=jl;
			if(i!=S){i=pre[i];aug=his[i];}
		}return ans;
	}
}
int main(){
	read(n);read(m);
	rep(i,1,n){
		int x;read(x);
		divide(x,i);
	}
	rep(i,1,m){
		read(x[i]);read(y[i]);
		if(!(x[i]&1))swap(x[i],y[i]);
	}int ans=0;
	for(pin xx:app){
		solve::clear();memset(num,0,sizeof(num));
		for(pin w:rec[xx.w2])num[w.w1]=w.w2;
		rep(i,1,n)if(i&1)solve::addedge(solve::S,i,num[i]);
		else solve::addedge(i,solve::T,num[i]);
		rep(i,1,m)solve::addedge(x[i],y[i],inf);
		ans+=solve::isap();
	}cout<<ans;
    return 0;
}