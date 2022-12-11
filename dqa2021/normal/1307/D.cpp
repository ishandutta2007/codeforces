#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m,k;
int a[200010];
vector<int> e[200010];

int dis1[200010],disn[200010];

bool bfs(int x,int *dis){
	rep(i,1,n) dis[i]=1e9;
	dis[x]=0;
	static int que[200010],hd,tl;
	hd=tl=0; que[++tl]=x;
	while (hd<tl){
		int u=que[++hd];
		for (int v: e[u]){
			if (dis[v]==1e9) dis[v]=dis[u]+1,que[++tl]=v;
		} 
	}
}

struct C{
	int o,x,y;
}c[400010]; int top;
bool operator<(const C &x,const C &y){
	if (x.x^y.x) return x.x>y.x;
	return x.o<y.o;
}
int tri[200010],vrn[200010],tim;
void add(int x){
	for (x++;x;x-=x&-x){
		if (vrn[x]^tim) vrn[x]=tim,tri[x]=1;
		else tri[x]++;
	}
}
int ask(int x){
	int res=0;
	for (x++;x<=n;x+=x&-x)
		if (vrn[x]==tim)
			res+=tri[x];
	return res;
}

bool check(int S){
	top=0; ++tim;
	rep(i,1,k){
		c[++top]=(C){0,dis1[a[i]],disn[a[i]]};
//		printf("test A %d: %d %d\n",a[i],dis1[a[i]],disn[a[i]]);
	}
	rep(i,1,k){
		c[++top]=(C){1,S-1-disn[a[i]],S-1-dis1[a[i]]};
//		printf("test B %d: %d %d\n",a[i],S-1-disn[a[i]],S-1-dis1[a[i]]);
	}
	sort(c+1,c+top+1);
	rep(i,1,top){
		C t=c[i];
		if (t.o==0) add(t.y);
		else{
			if (ask(max(0,t.y))>=2) return 1;
		}
	}
	return 0;
}

void solve(){
	n=read(),m=read(),k=read();
	rep(i,1,k) a[i]=read();
	rep(i,1,m){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	bfs(1,dis1); bfs(n,disn);
//	if (check(4)) printf("true\n");
	int l=0,r=dis1[n],mid;
	while (l<r){
		mid=l+r+1>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}