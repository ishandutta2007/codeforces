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
const int maxn=500005;
const int inf=1<<30;
namespace lct{
	int top,son[maxn][2],fa[maxn],v[maxn],S[maxn];
	pin maxi[maxn];bool rev[maxn],tag[maxn],col[maxn];
	inline bool isroot(int x){assert(x);return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;}
	inline void update(int x){assert(x);maxi[x]=max(maxi[son[x][0]],max(maxi[son[x][1]],mk(v[x],x)));}
	inline void pushdown(int x){assert(x);
		if(rev[x]){swap(son[x][0],son[x][1]);rev[son[x][0]]^=1;rev[son[x][1]]^=1;rev[x]=0;}
		if(tag[x]){col[x]^=1;tag[son[x][0]]^=1;tag[son[x][1]]^=1;tag[x]=0;}
	}inline void rotate(int x){int y=fa[x],z=fa[y],d=(son[y][1]==x);if(!isroot(y))son[z][son[z][1]==y]=x;fa[x]=z;fa[y]=x;fa[son[x][!d]]=y;son[y][d]=son[x][!d];son[x][!d]=y;update(y);update(x);
	}inline void splay(int x){S[top=1]=x;for(int i=x;!isroot(i);i=fa[i])S[++top]=fa[i];per(i,top,1)pushdown(S[i]);
		for(int y=fa[x],z=fa[y];!isroot(x);y=fa[x],z=fa[y]){if(!isroot(y))((son[z][1]==y)^(son[y][1]==x))?rotate(x):rotate(y);rotate(x);}
	}inline void access(int x){int t=0;while(x){splay(x);son[x][1]=t;update(x);t=x;x=fa[x];}}
	inline void makeroot(int x){access(x);splay(x);rev[x]^=1;}
	inline pin qmax(int x,int y){makeroot(x);access(y);splay(y);return maxi[y];}
	inline void cl(int x,int y){makeroot(x);access(y);splay(x);tag[x]^=1;}
	inline void link(int x,int y){makeroot(y);fa[y]=x;}
	inline void cut(int x,int y){makeroot(x);access(y);splay(y);son[y][0]=fa[x]=0;}
	inline bool query(int x){access(x);splay(x);return col[x];}
}
int n,m,s[maxn],t[maxn],tot;
set<pin> ans;
set<pin>::iterator it;
inline void maintain(){
	for(;;){
		if(lct::query(it->w2+n))break;
		else it--;
	}
}
int main(){
	read(n);read(m);
	if(n&1){
		rep(i,1,m)puts("-1");
		return 0;
	}
	rep(i,1,n-1)lct::col[i+n]=1,lct::v[i+n]=inf,s[i]=1,t[i]=i+1,lct::link(1,i+n),lct::link(i+n,i+1),ans.insert(mk(inf,i));
	it=ans.end();it--;tot=n-1;
	rep(i,1,m){
		tot++;
		//cerr<<'!'<<lct::query(12)<<endl;
		int x,y,z;read(x);read(y);read(z);s[tot]=x;t[tot]=y;
		ans.insert(mk(z,tot));
		pin tmp=lct::qmax(x,y);lct::v[tot+n]=z;
		if(tmp.w1>z){
			//cerr<<tmp.w2<<','<<lct::query(tmp.w2)<<endl;
			if(lct::query(tmp.w2))lct::cl(x,y),lct::col[tot+n]=1;int nd=tmp.w2-n;
			lct::cut(s[nd],nd+n);lct::cut(t[nd],nd+n);
			lct::link(x,tot+n);lct::link(tot+n,y);
		}
		maintain();
		int res=it->w1;
		if(res==inf)res=-1;
		printf("%d\n",res);
	}
	return 0;
}