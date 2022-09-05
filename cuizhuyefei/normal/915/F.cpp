#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 2020000;
int n,a[N],f[N],size[N];
struct edge {int u,v,d;} e[N];
bool cmp1(edge x, edge y) {return x.d>y.d;}
bool cmp2(edge x, edge y) {return x.d<y.d;}
ll ans1,ans2;
inline int find(int x) {
	return f[x]==x ? x : f[x]=find(f[x]);
}
int main() {
	read(n); rep(i,1,n) read(a[i]);
	rep(i,1,n-1) {read(e[i].u);read(e[i].v);e[i].d=min(a[e[i].u],a[e[i].v]);}
	sort(e+1,e+n,cmp1);
	rep(i,1,n) f[i]=i,size[i]=1;
	rep(i,1,n-1) {int x=find(e[i].u),y=find(e[i].v); ans1+=1LL*size[x]*size[y]*e[i].d; f[x]=y; size[y]+=size[x];}
	
	rep(i,1,n-1) e[i].d=max(a[e[i].u],a[e[i].v]);
	sort(e+1,e+n,cmp2);
	rep(i,1,n) f[i]=i,size[i]=1;
	rep(i,1,n-1) {int x=find(e[i].u),y=find(e[i].v); ans2+=1LL*size[x]*size[y]*e[i].d; f[x]=y; size[y]+=size[x];}
	printf("%lld",ans2-ans1);
	return 0;
}