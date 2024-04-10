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
const int maxn=40005;
int head[maxn],t[maxn<<3],ne[maxn<<3],sap[maxn<<3],num;
const int inf=1<<30;
inline void addedge(int x,int y,int z){
	ne[++num]=head[x];head[x]=num;t[num]=y;sap[num]=z;
	ne[++num]=head[y];head[y]=num;t[num]=x;sap[num]=0;
}
int cnt[maxn],cur[maxn],his[maxn],in[maxn],out[maxn],S,T,SS,TT,edge[maxn],pre[maxn],d[maxn];
inline int isap(){
	rep(i,1,T)cur[i]=head[i],d[i]=0,cnt[i]=0;cnt[0]=T;int i=S,aug=inf,ans=0,jl,minnum;
	while(d[S]<T){
		his[i]=aug;bool flag=0;for(int j=cur[i];j!=-1;j=ne[j])if(sap[j]&&d[t[j]]+1==d[i]){
			flag=1;aug=min(aug,sap[j]);pre[t[j]]=i;edge[i]=j;cur[i]=j;i=t[j];
			if(i==T){ans+=aug;
				while(i!=S){i=pre[i];sap[edge[i]]-=aug;sap[edge[i]^1]+=aug;}aug=inf;
			}break;
		}if(flag)continue;minnum=T;forE(j,i)if(sap[j]&&d[t[j]]<minnum)minnum=d[t[j]],jl=j;
		if(--cnt[d[i]]==0)return ans;cnt[d[i]=minnum+1]++;cur[i]=jl;
		if(i!=S){i=pre[i];aug=his[i];}
	}return ans;
}
int v[maxn],sex[maxn],n,m,g,nd[maxn];
int main(){
//	judge();
	read(n);read(m);read(g);num=1;
	rep(i,1,n)read(sex[i]);
	rep(i,1,n)read(v[i]);
	S=n+m+1;T=n+m+2;
	rep(i,1,T)head[i]=-1;
	rep(i,1,n)
		if(sex[i])
			addedge(i,T,v[i]);
		else
			addedge(S,i,v[i]);
	int res=0;
	rep(i,1,m){
		int w,c,k;
		read(c);read(w);read(k);res+=w;
		rep(i,1,k)read(nd[i]);
		int v;read(v);v*=g;
		if(c)
			addedge(i+n,T,v+w);
		else
			addedge(S,i+n,v+w);
		rep(j,1,k)
			if(!c)
				addedge(i+n,nd[j],inf);
			else
				addedge(nd[j],i+n,inf);
	}res-=isap();
	cout<<res;
	return 0;
}