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
const int N = 366666,mo1=1e9+9,mo2=1e9+7,b1=10007,b2=19260817;
int n,a[N],sta[N],top;Pii cur,s[N],t[N];Pii val[N];
void ins(int x){
	if(!top||sta[top]!=x)
		sta[++top]=x,cur=Pii((cur.fi+1LL*val[top].fi*x)%mo1,(cur.se+1LL*val[top].se*x)%mo2);
	else cur=Pii((cur.fi+1LL*val[top].fi*(mo1-x))%mo1,(cur.se+1LL*val[top].se*(mo2-x))%mo2),top--;
}
ll solve(int l, int r){
	if(l==r)return 0;
	ll res=0;int mid=(l+r)>>1;
	//(1)
	top=0;cur=Pii(0,0);int len1=0;
	per(i,mid,l)ins(a[i]),s[++len1]=cur;
	//(2)
	top=0;cur=Pii(0,0);int len2=0;
	rep(i,mid+1,r)ins(a[i]),t[++len2]=cur;
	sort(s+1,s+len1+1);//sort(s+1,s+len1+1);
	rep(i,1,len2)res+=upper_bound(s+1,s+len1+1,t[i])-lower_bound(s+1,s+len1+1,t[i]);
	return res+solve(l,mid)+solve(mid+1,r);
}
int main() {
	val[0]=Pii(1,1);
	rep(i,1,N-1)val[i]=Pii(1LL*val[i-1].fi*b1%mo1,1LL*val[i-1].se*b2%mo2);
	int T;read(T);while(T--){
		read(n);rep(i,1,n)read(a[i]);
		printf("%lld\n",solve(1,n));
	}
	return 0;
}