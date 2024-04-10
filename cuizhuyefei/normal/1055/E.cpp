#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 3030,inf=0x3f3f3f3f;
int n,s,m,k,a[N];
struct seg{int l,r;}b[N];
bool cmp(seg a, seg b){
	if(a.l!=b.l)return a.l<b.l;return a.r>b.r;
}
int c[N],f[1505][1505],g[1505];
bool ck(int q){
	rep(i,1,n)c[i]=c[i-1]+(a[i]<=q);m=min(m,s);
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	int p=0;rep(i,1,s){
		while(p+1<=s&&b[p+1].r<b[i].l){
			p++;rep(j,0,m)g[j]=max(g[j],f[p][j]);
		}
		rep(j,1,m){
			f[i][j]=g[j-1]+c[b[i].r]-c[b[i].l-1];
			if(p+1<i)f[i][j]=max(f[i][j],f[p+1][j-1]+c[b[i].r]-c[b[p+1].r]);
			if(f[i][j]>=k)return 1;
		}
	}
	return 0;
}
int main() {
	read(n);read(s);read(m);read(k);
	rep(i,1,n)read(a[i]);rep(i,1,s)read(b[i].l),read(b[i].r);
	sort(b+1,b+s+1,cmp);
	rep(i,1,s){
		bool gg=0;rep(j,1,i-1)gg|=(b[j].l<=b[i].l&&b[j].r>=b[i].r);
		if(gg){rep(j,i,s-1)b[j]=b[j+1];s--;}
	}
	static int val[N];int len=0;rep(i,1,n)val[++len]=a[i];
	sort(val+1,val+len+1);len=unique(val+1,val+len+1)-val-1;
	int l=1,r=len,res=inf;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ck(val[mid]))res=val[mid],r=mid-1;else l=mid+1;
	}
	printf("%d",res==inf?-1:res);
	return 0;
}