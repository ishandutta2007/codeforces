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
const int maxn=1005,maxm=100005;
int k,num,n,m,head[maxn],t[maxm<<1],ne[maxm<<1];
bool flag[maxn],vis[maxn],term;
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
inline pin dfs(int x){
	vis[x]=1;term|=flag[x];int res=1,e=0;
	forE(i,x)if(!vis[t[i]]){
		pin tmp=dfs(t[i]);
		res+=tmp.w1;
		e+=tmp.w2+1;
	}else e++;return mk(res,e);
}vector<int> emp;
int main(){
//    judge();
	read(n);read(m);read(k);
	rep(i,1,k){
		int x;read(x);flag[x]=1;
	}rep(i,1,n)head[i]=-1;
	rep(i,1,m){
		int x,y;read(x);read(y);addedge(x,y);
	}int maxi=0,ans=0;
	rep(i,1,n){
		if(vis[i])continue;term=0;
		pin tmp=dfs(i);tmp.w2/=2;
		if(term)
			maxi=max(maxi,tmp.w1);
		else
			emp.pb(tmp.w1);
		ans+=tmp.w1*(tmp.w1-1)/2-tmp.w2;
	}
	for(int x:emp){
		ans+=x*maxi;maxi+=x;
	}cout<<ans;
    return 0;
}