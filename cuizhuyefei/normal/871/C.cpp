#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 100020, mo = 1e9+7;
int n,se[N],x,y,cnt,dfn[N],vis[N];
int dot[N],size;
int l[N],r[N];
ll ans=1;
set<Pii> L[N],R[N];

struct Dot {
	int x,y;
} s[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int LS() {
	sort(se+1,se+n+1);
	int l=0; rep(i,1,n) if (i==1||se[i]!=se[i-1]) se[++l]=se[i];
	return l;
}
inline void dfs(int u) {
//	printf("[%d]",u);
	if (u>n||u<1) return; vis[u]=cnt; dot[++size]=u;
	set<Pii> ::iterator it=L[s[u].x].find(Pii(s[u].y,u));
	it++; if (!vis[(*it).se]) dfs((*it).se);
	it--; it--; if (!vis[(*it).se]) dfs((*it).se);
	it=R[s[u].y].find(Pii(s[u].x,u));
	it++; if (!vis[(*it).se]) dfs((*it).se);
	it--; it--; if (!vis[(*it).se]) dfs((*it).se);
}
inline int power(ll a, int n) {
	ll ans=1;
	while (n) {
		if (n&1) ans=(ans*a%mo);
		a=(a*a%mo);
		n>>=1;
	}
	return ans;
}
int main() {
	read(n);
	rep(i,1,n) read(s[i].x),read(s[i].y);
	rep(i,1,n) se[i]=s[i].x; int X=LS();
	rep(i,1,n) s[i].x=lower_bound(se+1,se+X+1,s[i].x)-se;
	rep(i,1,n) se[i]=s[i].y; int Y=LS();
	rep(i,1,n) s[i].y=lower_bound(se+1,se+Y+1,s[i].y)-se; vis[n+1]=1e9;
	rep(i,1,n) L[i].insert(Pii(0,n+1)),L[i].insert(Pii(n+1,n+1));
	rep(i,1,n) R[i].insert(Pii(0,n+1)),R[i].insert(Pii(n+1,n+1));
	rep(i,1,n) {L[s[i].x].insert(Pii(s[i].y,i));R[s[i].y].insert(Pii(s[i].x,i));}
//	rep(i,1,n) printf("(%d %d)\n",s[i].x,s[i].y);
	rep(i,1,n) if (!vis[i]) {
		size=0; cnt++; dfs(i);
		int num=0; bool flag=0;
		rep(j,1,size) {
			if (l[s[dot[j]].x]||r[s[dot[j]].y]) flag=1;
			num+=(!l[s[dot[j]].x])+(!r[s[dot[j]].y]);
			l[s[dot[j]].x]=1; r[s[dot[j]].y]=1;
		}
	//	printf("%d %d %d\n",size,num,flag);
		int x=power(2,num); if (size<num) x--;//if (!flag) x--;
		if (x<0) x+=mo;
		ans=ans*x%mo;
	}
	printf("%lld",ans);
	return 0;
}