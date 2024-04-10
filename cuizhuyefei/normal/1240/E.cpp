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
const int N = 605000;
int n,a[N],mx,buc[N],lim=500000,qz[N];ll cnt[N],res;
inline void ck(int x, int y){
	if(1LL*x*y<=res||x>mx||x<=1||y<=1)return;
//	if(x==10&&y==9)cerr<<"QWQ "<<a[n-1]<<endl;
if(a[n-1]>=x){
	int res1=0,r=x%y,L=x;
	per(i,lim/y,0)if(max(i*y+r,L)<=min(i*y+y-1,lim)){
		res1+=qz[min(i*y+y-1,lim)]-(max(i*y+r,L)-1>=0?qz[max(i*y+r,L)-1]:0);
	}
	umin(res1,2);
	if(cnt[y]-2*(x/y)-(2-res1)>=x){res=1LL*x*y;return;}
}
if(a[n]>=2*x){
	int res1=0,r=2*x%y,L=2*x;
	per(i,lim/y,0)if(max(i*y+r,L)<=min(i*y+y-1,lim)){
		res1+=qz[min(i*y+y-1,lim)]-(max(i*y+r,L)-1>=0?qz[max(i*y+r,L)-1]:0);
	}
	if(cnt[y]-(2*x/y)-(!res1)>=x){res=1LL*x*y;return;}
}
}
int main() {
	read(n);rep(i,1,n)read(a[i]),buc[a[i]]++;
	sort(a+1,a+n+1);mx=max(a[n]/2,a[n-1]);
	rep(i,1,lim)qz[i]=qz[i-1]+buc[i];
	rep(y,1,lim)per(i,lim/y,1)
		cnt[y]+=1LL*i*(qz[min(lim,(i+1)*y-1)]-qz[i*y-1]);
	rep(y,1,lim){
		int L=0,R=mx,ans=-1;
		while(L<=R){
			int x=(L+R)>>1;
			if(cnt[y]-2LL*(x/y+1)>=x)ans=x,L=x+1;else R=x-1;
		}
	//	if(y<=9)cerr<<ans<<' '<<y<<' '<<cnt[y]<<endl;
		if(ans>=2&&y>=2)umax(res,1LL*ans*y);
		ck(ans+1,y);ck(ans+2,y);
	}
	cout<<res;
	return 0;
}