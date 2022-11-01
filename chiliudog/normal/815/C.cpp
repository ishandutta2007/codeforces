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
const int maxn=5005;
i64 f[maxn][maxn][2];
int size[maxn],n,fa[maxn],b;
i64 g[maxn][2];
vector<int> son[maxn];
i64 c[maxn],d[maxn];
const i64 inf=1ll<<60;
inline void dfs(int x){
	size[x]=1;f[x][1][0]=c[x];f[x][1][1]=c[x];f[x][0][1]=inf;
	for(int v:son[x]){
		dfs(v);
		rep(i,0,size[x]+size[v])g[i][0]=g[i][1]=inf;
		rep(i,0,size[x])rep(j,0,size[v]){
			g[i+j][1]=min(g[i+j][1],f[x][i][1]+f[v][j][1]-d[v]);
			g[i+j][1]=min(g[i+j][1],f[x][i][1]+f[v][j][0]);
			g[i+j][0]=min(g[i+j][0],f[x][i][0]+f[v][j][0]);
		}size[x]+=size[v];
		rep(i,0,size[x])f[x][i][0]=g[i][0],f[x][i][1]=g[i][1];
	}
}
int main(){
    read(n);read(b);
    rep(i,1,n){
    	cin>>c[i];cin>>d[i];
    	if(i>=2){
    		read(fa[i]);son[fa[i]].pb(i);
    	}
    }c[1]-=d[1];
    dfs(1);int res=0;
    rep(i,1,n){
    	if(b>=f[1][i][0])res=i;
    	if(b>=f[1][i][1])res=i;
    }cout<<res<<endl;
    return 0;
}