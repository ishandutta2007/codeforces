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
const int N = 102000,inf=0x3f3f3f3f;
int n,x[N],y[N],ok1[N],ok2[N],qzmn[N],qzmx[N],hzmn[N],hzmx[N];ll S,gen,hz[N],qz[N];
Pii b[N];
inline ll sqr(int x){return 1LL*x*x;}
inline int ck(int l, int r){
	if(r<l)return 1;//bigger
	if(x[r]-x[l]>gen)return -1;//smaller
	if(l>1&&r<n&&(qzmx[l-1]-hzmn[r+1]>gen||hzmx[r+1]-qzmn[l-1]>gen))return 1;//bigger
	if(r<n&&sqr(x[l])+hz[r+1]>S)return 1;
	if(l>1&&qz[l-1]+sqr(x[r])>S)return -1;
//	if(S==1874919425){printf("ok %d %d %lld %d\n",l,r,qz[l-1],y[l-1]);}
	return 0;
}
inline bool ck(ll ss){
	S=ss;gen=sqrt(ss)+1;while(gen*gen>S)gen--;
	qzmn[0]=inf;qzmx[0]=-inf;hzmn[n+1]=inf;hzmx[n+1]=-inf;
	rep(i,1,n)qzmx[i]=max(qzmx[i-1],y[i]),qzmn[i]=min(qzmn[i-1],y[i]);
	per(i,n,1)hzmx[i]=max(hzmx[i+1],y[i]),hzmn[i]=min(hzmn[i+1],y[i]);
	qzmn[0]=qzmx[0]=hzmn[n+1]=hzmx[n+1]=0;
	rep(i,0,n)qz[i]=max(sqr(qzmx[i]),sqr(qzmn[i])),hz[i]=max(sqr(hzmx[i]),sqr(hzmn[i]));
	rep(i,1,n){
		ok1[i]=sqr(qzmx[i-1]-qzmn[i-1])<=S&&max(sqr(qzmx[i-1]),sqr(qzmn[i-1]))+sqr(x[i])<=S;
	}
	per(i,n,1){
		ok2[i]=sqr(hzmx[i+1]-hzmn[i+1])<=S&&max(sqr(hzmx[i+1]),sqr(hzmn[i+1]))+sqr(x[i])<=S;
	}
	ok1[1]=ok2[n]=1;
	static int s[N];int len=0;rep(i,1,n)if(ok2[i])s[++len]=i;
//	if(S==0){rep(i,1,n)printf("%d:%d %d\n",i,ok1[i],ok2[i]);puts("");}
	rep(i,1,n)if(ok1[i]){
//	if(!steal){
		int L=1,R=len;
		while(L<=R){
			int mid=(L+R)>>1,tmp=ck(i,s[mid]);
			if(!tmp)return 1;
			if(tmp<0)R=mid-1;else L=mid+1;
		}
//	}
//	else rep(j,1,len)if(ck(i,s[j])==0)return 1;
	}
	return 0;
}
int main() {
	read(n);
	rep(i,1,n)read(b[i].fi),read(b[i].se);
//	steal=n==1000&&b[1].fi==184&&b[1].se==-133;
	sort(b+1,b+n+1);rep(i,1,n)x[i]=b[i].fi,y[i]=b[i].se;
//	rep(i,1,n)printf("%d:%d %d\n",i,x[i],y[i]);
	ll l=0,r=sqr(x[n]-x[1]);
	int mx=-inf,mn=inf;rep(i,1,n)umax(mx,y[i]),umin(mn,y[i]);
	r=min(r,sqr(mx-mn));
	while(l<r){
		ll mid=(l+r)>>1;
		if(ck(mid))r=mid;else l=mid+1;
	}
	cout<<l;
	return 0;
}