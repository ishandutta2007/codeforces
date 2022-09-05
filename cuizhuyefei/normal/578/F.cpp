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
const int N = 233;
int n,m,mo;char s[N][N];
int fa[16666],bh[N][N],tot,a[N][N];bool gg;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x, int y){
	x=find(x);y=find(y);
	if(x==y)gg=1;else fa[x]=y;
}
void addedge(int x, int y){
	a[x][x]++;a[y][y]++;a[x][y]--;a[y][x]--;
}
int solve(int a[N][N], int n){
	int res=1;
	rep(i,1,n)rep(j,1,n)a[i][j]%=mo;
	rep(i,1,n){
		if(!a[i][i]){
			rep(j,i+1,n)if(a[j][i]){
				res=-res;rep(k,i,n)swap(a[i][k],a[j][k]);
				break;
			}
		}
		res=1LL*res*a[i][i]%mo;
		rep(j,i+1,n)if(a[j][i]){
			int xs=1LL*a[j][i]*power(a[i][i],mo-2)%mo;
			rep(k,i,n)a[j][k]=(a[j][k]-1LL*xs*a[i][k])%mo;
		}
	}
	return (res+mo)%mo;
}
int solve(int tp){
	tot=0;gg=0;
	rep(i,1,n+1)rep(j,1,m+1)if((i+j)%2==tp)
		bh[i][j]=++tot,fa[tot]=tot;
	rep(i,1,n)rep(j,1,m)
		if(s[i][j]=='/'&&(i+j+1)%2==tp)merge(bh[i][j+1],bh[i+1][j]);
		else if(s[i][j]=='\\'&&(i+j)%2==tp)merge(bh[i][j],bh[i+1][j+1]);
	if(gg)return 0;
	int cnt=0;static int bel[16666];
	rep(i,1,tot)if(find(i)==i)bel[i]=++cnt;
	if(cnt>210)return 0;memset(a,0,sizeof(a));
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='*')
		if((i+j+1)%2==tp)addedge(bel[find(bh[i][j+1])],bel[find(bh[i+1][j])]);
		else addedge(bel[find(bh[i][j])],bel[find(bh[i+1][j+1])]);
	return solve(a,cnt-1);
}
int main() {
	read(n);read(m);read(mo);
	rep(i,1,n)scanf("%s",s[i]+1);
	cout<<(solve(0)+solve(1))%mo;
	return 0;
}