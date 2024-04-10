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
const int maxn=300005;
int num,n,head[maxn],t[maxn<<1],ne[maxn<<1],tr[maxn],cnt=0;
int size[maxn],c[maxn],son[maxn][26],v[maxn],ans;
char s[maxn];
inline void update(int x){
	assert(x);
	size[x]=1;
	rep(i,0,25)size[x]+=size[son[x][i]];
}
inline void merge(int &x,int y){
	if(!x){x=y;return;}
	if(!y)return;
	rep(i,0,25)merge(son[x][i],son[y][i]);
	update(x);
}
inline void dfs(int x,int fa){
	forE(i,x)if(t[i]!=fa){
		dfs(t[i],x);
		merge(son[x][s[t[i]]-'a'],t[i]);
	}update(x);
	if(ans<size[x]+c[x]){
		ans=size[x]+c[x];cnt=0;
	}
	if(ans==size[x]+c[x]){
		cnt++;
	}
}
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
int main(){
	read(n);
	rep(i,1,n)read(c[i]),head[i]=-1;scanf("%s",s+1);
	rep(i,1,n-1){
		int x,y;read(x);read(y);addedge(x,y);
	}
	dfs(1,-1);
	cout<<ans<<endl<<cnt;
	return 0;
}