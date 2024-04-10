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
const int maxn=3005,maxm=5005;
const int inf=1<<28;
int num,head[maxn],t[maxm],ne[maxm];
int Queue[maxn],dis[maxn][maxn];
bool vis[maxn];
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
}
struct info{
	pin v[4];
	info(){rep(i,1,3)v[i]=mk(-inf,0);}
};
inline void update(info &a,pin b){
	if(b>a.v[1]){
		a.v[3]=a.v[2];a.v[2]=a.v[1];a.v[1]=b;
	}else if(b>a.v[2]){
		a.v[3]=a.v[2];a.v[2]=b;
	}else if (b>a.v[3]){
		a.v[3]=b;
	}
}
info maxi1[maxn],maxi2[maxn];int n,m;
inline void BFS(int f){
	memset(vis,0,sizeof(vis));
	rep(i,1,n)dis[f][i]=-inf;
	int front=0,finish=0;Queue[++finish]=f;vis[f]=1;dis[f][f]=0;
	while(front!=finish){
		int x=Queue[++front];forE(i,x)if(!vis[t[i]]){
			dis[f][t[i]]=dis[f][x]+1;vis[t[i]]=1;Queue[++finish]=t[i];
		}
	}
}
pair<int,pair<pin,pin> > ans;
int main(){
	read(n);read(m);rep(i,1,n)head[i]=-1;
	rep(i,1,m){
		int x,y;read(x);read(y);addedge(x,y);
	}rep(i,1,n)BFS(i);
	rep(i,1,n){
		rep(j,1,n)update(maxi1[i],mk(dis[j][i],j));
		rep(j,1,n)update(maxi2[i],mk(dis[i][j],j));
	}ans=mk(-inf,mk(mk(0,0),mk(0,0)));
	rep(i,1,n)rep(j,1,n){
		rep(x1,1,3)rep(y1,1,3){
			static int a[5];a[1]=i;a[2]=j;a[3]=maxi1[i].v[x1].w2;a[4]=maxi2[j].v[y1].w2;bool flag=0;
			sort(a+1,a+1+4);rep(i,1,3)if(a[i]==a[i+1])flag=1;if(flag)continue;
			ans=max(ans,mk(maxi1[i].v[x1].w1+dis[i][j]+maxi2[j].v[y1].w1,mk(mk(maxi1[i].v[x1].w2,i),mk(j,maxi2[j].v[y1].w2))));
		}
	}
	printf("%d %d %d %d",ans.w2.w1.w1,ans.w2.w1.w2,ans.w2.w2.w1,ans.w2.w2.w2);
	cerr<<ans.w1;
	return 0;
}