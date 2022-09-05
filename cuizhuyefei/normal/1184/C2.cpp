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
const int N = 344444;
int n,d,res;Pii s[N];int a[N],len;
int mx[N<<2],lzy[N<<2];
inline void pushdown(int k, int l, int r){
	if(lzy[k]){
		mx[k<<1]+=lzy[k];lzy[k<<1]+=lzy[k];
		mx[k<<1|1]+=lzy[k];lzy[k<<1|1]+=lzy[k];
		lzy[k]=0;
	}
}
inline void upd(int k){
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
inline void modify(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){
		mx[k]+=x;lzy[k]+=x;return;
	}
	pushdown(k,L,R);int mid=(L+R)>>1;
	if(r<=mid)modify(k<<1,l,r,x,L,mid);
	else if(l>mid)modify(k<<1|1,l,r,x,mid+1,R);
	else modify(k<<1,l,mid,x,L,mid),modify(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
inline void ins(int i, int xs){
	int r=lower_bound(a+1,a+len+1,s[i].se)-a;
	int l=lower_bound(a+1,a+len+1,s[i].se-d)-a;
	modify(1,l,r,xs,1,len);
}
int main() {
	read(n);read(d);d*=2;
	rep(i,1,n){
		int x,y;read(x);read(y);
		s[i]=Pii(y+x,y-x);
	}
	sort(s+1,s+n+1);
	rep(i,1,n)a[i]=s[i].se;sort(a+1,a+n+1);
	len=unique(a+1,a+n+1)-a-1;//a[1..len]
	for(int i=1,j=1;i<=n;i++){
		ins(i,1);
		while(s[i].fi-s[j].fi>d)ins(j,-1),j++;
		umax(res,mx[1]);
	}
	printf("%d\n",res);
	return 0;
}