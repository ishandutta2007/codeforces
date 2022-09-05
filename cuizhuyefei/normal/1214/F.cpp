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
typedef pair<ll,int> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
const int N = 600500;
int n,m;Pll a[N],b[N];ll ans[N];
inline void upd(int l, int r, ll x){
	umax(l,1);umin(r,2*n+1);if(l<=r)ans[l]+=x,ans[r+1]-=x;
}
int main() {//freopen("1.in","r",stdin);
	
		read(m);read(n);
		rep(i,1,n)read(a[i].fi),a[i].se=i;//,a[i]+=m;
		rep(i,1,n)read(b[i].fi),b[i].se=i;//,b[n+i]=b[i]+m,b[n+n+i]=b[n+i]+m;
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		rep(i,1,n)a[i].fi+=m;
		rep(i,1,n)b[n+i]=b[n+n+i]=b[i],b[n+i].fi+=m,b[n+n+i].fi+=2*m;
		rep(i,0,3*n)ans[i]=0;
		for(int i=1,j=0;i<=n;i++){
			while(j+1<=3*n&&a[i].fi>=b[j+1].fi)j++;
			upd(1-i+1,j-i+1,a[i].fi);upd(j+1-i+1,3*n-i+1,-a[i].fi);
		}
		for(int j=1,i=0;j<=3*n;j++){
			while(i+1<=n&&a[i+1].fi<b[j].fi)i++;
			upd(j+1-i,j+1-1,b[j].fi);upd(j+1-n,j+1-(i+1),-b[j].fi);
		}
		int p=0;ll res=1e18;rep(i,1,2*n+1){
			ans[i]+=ans[i-1];
			if(ans[i]<res)res=ans[i],p=i;
		}
		static int ans[N];
		rep(i,1,n)ans[a[i].se]=b[p+i-1].se;
		printf("%lld\n",res);
		rep(i,1,n)printf("%d ",ans[i]);
	
	return 0;
}