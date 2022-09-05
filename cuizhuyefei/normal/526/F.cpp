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
const int N = 366666,inf=0x3f3f3f3f;
int n,p[N];ll res;
int a[N],l1,b[N],l2,buc[N<<1];
inline ll getans(int *a, int *b, int n, int m){
	ll res=0;
	static int qzmn[N],qzmx[N];
	qzmn[0]=inf;rep(i,1,m)qzmn[i]=min(qzmn[i-1],b[i]);
	qzmx[0]=-inf;rep(i,1,m)qzmx[i]=max(qzmx[i-1],b[i]);
	//(1)
	for(int i=1,l=1,r=0,mn=a[1],mx=a[1];i<=n;i++,mn=min(mn,a[i]),mx=max(mx,a[i])){
		while(r+1<=m&&mx>qzmx[r+1])r++,buc[r+qzmn[r]]++;
		while(l<=r&&mn<qzmn[l])buc[l+qzmn[l]]--,l++;
		res+=buc[mx-i+1];
	}
	rep(j,1,m)buc[j+qzmn[j]]=0;
	//(2)
	for(int i=1,mn=a[1],mx=a[1];i<=n;i++,mn=min(mn,a[i]),mx=max(mx,a[i])){
		int j=mx-mn+1-i;if(j>=1&&j<=m&&mx>qzmx[j]&&mn<qzmn[j])res++;
	}
	return res;
}
void solve(int l, int r){
	if(l==r)return;int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	l1=l2=0;rep(i,mid+1,r)b[++l2]=p[i];
	per(i,mid,l)a[++l1]=p[i];
	res+=getans(a,b,l1,l2)+getans(b,a,l2,l1);
}
int main() {
	read(n);rep(i,1,n){
		int x,y;read(x);read(y);p[x]=y;
	}
	solve(1,n);cout<<res+n;
	return 0;
}