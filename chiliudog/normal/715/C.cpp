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
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
const int maxn=100005;
int inp[maxn],pw[maxn],p,phip,n,m,num;
int head[maxn],t[maxn<<1],ne[maxn<<1],v[maxn<<1];
inline int powmod(int a,int b,int mod){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
inline int phi(int p){
	int res=1,v=p,x=sqrt(p);
	rep(i,2,x){
		while(v%i==0){
			v/=i;res*=(i-1);
			while(v%i==0)v/=i,res*=i;
		}
	}
	if(v!=1)res*=(v-1);
	return res;
}
inline void prprpr(){
	phip=phi(p);pw[0]=1;inp[0]=1;
	rep(i,1,n){
		pw[i]=1ll*pw[i-1]*10%p;
		inp[i]=powmod(pw[i],phip-1,p);
//		assert(1ll*pw[i]*inp[i]%p==1);
	}
}
inline void addedge(int x,int y,int z){
	ne[++num]=head[x];head[x]=num;t[num]=y;v[num]=z;
	ne[++num]=head[y];head[y]=num;t[num]=x;v[num]=z;
}bool vis[maxn];
int size[maxn],son[maxn];
int maxi=0,tot=0;const int inf=1<<29;int root;
vector<int> tmp;
map<int,int> cnt;
i64 ans=0;
inline void dfs_size(int x,int fa){
	son[x]=0;size[x]=1;
	forE(i,x)if(t[i]!=fa&&!vis[t[i]])dfs_size(t[i],x),size[x]+=size[t[i]],son[x]=max(son[x],size[t[i]]);
}
inline void dfs_root(int x,int fa){
	if(max(son[x],tot-size[x])<maxi){
		maxi=max(son[x],tot-size[x]);root=x;
	}forE(i,x)if(t[i]!=fa&&!vis[t[i]])dfs_root(t[i],x);
}
inline void dfs_ans(int x,int fa,int v1,int v2,int len){
	v1%=p;v2%=p;
	ans+=cnt[(p-v1)%p];tmp.pb(1ll*v2*inp[len]%p);
	forE(i,x)if(t[i]!=fa&&!vis[t[i]]){
		dfs_ans(t[i],x,(v1+1ll*pw[len]*v[i])%p,(v2*10ll+v[i])%p,len+1);
	}
}vector<int> sonx;
inline void Point_Divide(int x){
	dfs_size(x,-1);tot=size[x];maxi=inf;dfs_root(x,-1);cnt.clear();tmp.clear();cnt[0]=1;
	vis[root]=1;sonx.clear();
	forE(i,root)if(!vis[t[i]]){
		sonx.pb(i);
		dfs_ans(t[i],-1,v[i],v[i],1);
		for(int v:tmp)cnt[v]++;tmp.clear();
	}cnt.clear();
	per(j,int(sonx.size())-1,0){
		int i=sonx[j];
		dfs_ans(t[i],-1,v[i],v[i],1);
		for(int v:tmp)cnt[v]++;tmp.clear();
	}ans+=cnt[0];
	forE(i,root)if(!vis[t[i]]){
		Point_Divide(t[i]);
	}
}
int main(){
//	judge();
	read(n);read(p);prprpr();rep(i,1,n)head[i]=-1;
	rep(i,1,n-1){
		int x,y,z;read(x);read(y);read(z);x++;y++;z%=p;
		addedge(x,y,z);
	}
	Point_Divide(1);
	cout<<ans;
	return 0;
}