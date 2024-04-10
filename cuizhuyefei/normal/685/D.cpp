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
const int N = 202000,inf=0x3f3f3f3f;
int n,k;Pii a[N],sta[N];int top,qz[N],buc[100005*303];
ll ans[N];Pii s[N];int len;
int Abs(int x){return x>0?x:-x;}
int sgn(int x){return x>0?1:-1;}
int main() {
	read(n);read(k);
	rep(i,1,n)read(a[i].fi),read(a[i].se),sta[i]=Pii(a[i].se,a[i].se+k-1);
	sort(sta+1,sta+n+1);
	top=0;rep(i,1,n)if(!top||sta[top].se<sta[i].fi)sta[++top]=sta[i];
	else umax(sta[top].se,sta[i].se);
	rep(i,1,top)qz[i]=qz[i-1]+sta[i].se-sta[i].fi+1;
	rep(i,1,n){
		int p=upper_bound(sta+1,sta+top+1,Pii(a[i].se,inf))-sta-1;
		a[i].se=qz[p-1]+a[i].se-sta[p].fi+1;
	}
	rep(i,1,n)s[++len]=Pii(a[i].fi,i),s[++len]=Pii(a[i].fi+k,-i);
	sort(s+1,s+len+1);
	rep(i,1,len){
		int xs=sgn(s[i].se),l=a[Abs(s[i].se)].se,p=s[i].fi;
	//	cerr<<s[i].se<<' '<<l<<endl;
		rep(j,l,l+k-1)ans[buc[j]]-=inf-p,ans[buc[j]+=xs]+=inf-p;
	}
	rep(i,1,n)printf("%lld ",ans[i]);
	return 0;
}