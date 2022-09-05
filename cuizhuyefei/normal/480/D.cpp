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
const int N = 1020,inf=0x3f3f3f3f;
int n,f[N][N],g[N][N];
struct node{
	int l,r,w,s,v;
}s[N];
bool cmp(node x, node y){return x.l!=y.l?x.l<y.l:(x.r>y.r);}
int main() {
	read(n);int tmp;read(tmp);
	rep(i,1,n)read(s[i].l),read(s[i].r),read(s[i].w),read(s[i].s),read(s[i].v);
	s[n+1].l=0;s[n+1].r=2*n;s[n+1].s=tmp;n++;
	sort(s+1,s+n+1,cmp);
	per(i,n,1){
		int r=n;while(s[r].l>s[i].r)r--;
		//i+1..r && s[j].r<=s[i].r
		int pos=s[i].r+1;//g[pos..s[i].r][]
		rep(j,s[i].l,s[i].r+1)rep(k,0,s[i].s)g[j][k]=0;
		per(j,r,i+1)if(s[j].r<=s[i].r){
			while(pos>s[j].r){
				pos--;rep(k,0,s[i].s)umax(g[pos][k],g[pos+1][k]);
			}
			rep(k,0,s[i].s)if(min(k-s[j].w,s[j].s)>=0)
				umax(g[s[j].l][k],f[j][min(k-s[j].w,s[j].s)]+g[s[j].r][k]);
		}
		while(pos>s[i].l){pos--;rep(k,0,s[i].s)umax(g[pos][k],g[pos+1][k]);}
		rep(j,0,s[i].s)f[i][j]=max(g[s[i].l][j],0)+s[i].v;
		rep(j,s[i].s+1,1000)f[i][j]=f[i][j-1];
	}
	cout<<f[1][tmp];
	return 0;
}