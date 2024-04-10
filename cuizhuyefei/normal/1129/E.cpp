#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1005;
int n,fa[N],sz[N],id[N],a[N],len;bool vis[N];
int ask(Vi a, Vi b, int x){
	printf("%d\n",SZ(a));
	rep(i,0,SZ(a)-1)printf("%d ",a[i]);puts("");
	printf("%d\n",SZ(b));
	rep(i,0,SZ(b)-1)printf("%d ",b[i]);puts("");
	printf("%d\n",x);fflush(stdout);
	int u;read(u);return u;
}
bool cmp(int x, int y){return sz[x]<sz[y];}
int query(int l, int r, int u){
	if(l>r)return 0;Vi x,y;x.pb(1);
	rep(i,l,r)y.pb(a[i]);if(!ask(x,y,u))return 0;
	int bg=l;
	while(l<r){
		int mid=(l+r)>>1;
		y.clear();rep(i,bg,mid)y.pb(a[i]);
		if(ask(x,y,u))r=mid;else l=mid+1;
	}
	return l;
}
int main() {
	read(n);
	Vi A,B;A.pb(1);rep(i,2,n)B.pb(i);
	sz[1]=n;rep(i,2,n)sz[i]=ask(A,B,i);
	rep(i,1,n)id[i]=i;
	sort(id+1,id+n+1,cmp);//id[1..n]
	set<int>Set;
	rep(t,1,n){
		int u=id[t];len=0;
		while(!Set.empty())a[++len]=*Set.begin(),Set.erase(a[len]);
		int p=query(1,len,u);memset(vis,0,sizeof(vis));
		while(p){vis[p]=1;fa[a[p]]=u;p=query(p+1,len,u);}
		a[++len]=u;
		rep(i,1,len)if(!vis[i])Set.insert(a[i]);
	}
	puts("ANSWER");
	rep(i,2,n)printf("%d %d\n",fa[i],i);
	fflush(stdout);
	return 0;
}