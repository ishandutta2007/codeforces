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
const int maxn=100005;
vector<int> son[maxn],ans;
bool vis[maxn];
int v[maxn],n,m;
inline void dfs(int x,int p){
	ans.pb(x);v[x]^=1;vis[x]=1;
	for(int jls:son[x])if(!vis[jls]){
		dfs(jls,x);
		ans.pb(x);v[x]^=1;
	}
	if(v[x]&&p){
		ans.pb(p);ans.pb(x);
		v[x]^=1;v[p]^=1;
	}
}
int main(){
    read(n);read(m);
    rep(i,1,m){
    	int x,y;read(x);read(y);son[x].pb(y);son[y].pb(x);
    }rep(i,1,n)read(v[i]);
    int s=1;
    rep(i,1,n)if(v[i])s=i;
    dfs(s,0);
    if(v[s])ans.pop_back(),v[s]^=1;
    rep(i,1,n)if(v[i]){
    	puts("-1");return 0;
    }
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x);
    return 0;
}