#include<bits/stdc++.h>
#define x first
#define y second
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
const int N = 505000,mo=1e9+7;
//no mod:tot,qz[],Cross(),getarea
int n;Pii s[N];ll res,tot,qz[N],qz2[N];
ll qzx[N],qzy[N];
inline ll Cross(Pii a, Pii b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
inline ll getarea(int l, int r){
	return qz[r-1]-qz[l-1]+Cross(s[r],s[l]);
}
inline ll calc(int i, int l, int r){
	return ((qzx[r]-qzx[l-1])%mo*s[i].y-(qzy[r]-qzy[l-1])%mo*s[i].x+1LL*(qz[l-1]-qz[i-1])%mo*(r-l+1)+1LL*(qz[r-1]-qz[l-1])%mo*r-(qz2[r-1]-qz2[l-1]))%mo;
}
int main() {
	read(n);rep(i,1,n)read(s[i].x),read(s[i].y);
	reverse(s+1,s+n+1);
	s[n+1]=s[1];
	rep(i,1,n)tot=tot+Cross(s[i],s[i+1]);
	rep(i,1,n)qz[i]=qz[i-1]+Cross(s[i],s[i+1]),qz2[i]=(qz2[i-1]+1LL*Cross(s[i],s[i+1])%mo*i)%mo;
	rep(i,1,n)qzx[i]=(qzx[i-1]+s[i].x)%mo,qzy[i]=(qzy[i-1]+s[i].y)%mo;
	cerr<<tot<<endl;
	rep(t,1,n){
		int l=t+2,r=n;if(t==1)r--;if(l>r)continue;
		int L=l,R=r,pos=l-1;
		while(L<=R){
			int mid=(L+R)>>1;
			if(getarea(t,mid)<=tot/2)pos=mid,L=mid+1;else R=mid-1;
		}
	//	cerr<<l<<' '<<pos<<' '<<r<<endl;
	//	rep(j,l,pos)assert((getarea(t,j)<tot/2)==(j<=pos));
	//	rep(j,l,r)printf("%d %d:%lld\n",t,j,getarea(t,j));
		//[l,pos] [pos+1,r]
		if(l<=pos){
			ll sum=calc(t,l,pos)%mo;
			res=(res+tot%mo*(pos-l+1)-2*sum)%mo;
		}
		if(pos+1<=r){
			ll sum=calc(t,pos+1,r)%mo;
			res=(res+2*sum-tot%mo*(r-pos))%mo;
		}
	}
	cout<<(res%mo+mo)%mo<<endl;
	return 0;
}