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
const int N = 666666;
struct Pii{
	int fi,se,idx;
};
int n,m;Pii a[N];int b[N];
bool cmp(Pii a, Pii b){return a.se>b.se;}
void solve(int n){//a[1..n]
	sort(a+1,a+n+1,cmp);
	/*for(int i=1,j=1;i<=n;i++){
		while(j+1<=n&&a[j+1].se>a[i].fi)j++;
		b[i]=j;
	}*/
	rep(i,1,n){
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].se>a[i].fi)b[i]=mid,l=mid+1;
			else r=mid-1;
		}
	}
	static int s[N],sta[N];int len=0,top=0;
	rep(i,1,n)if(b[i]==i)sta[++top]=i;
	if(!top){
		rep(i,1,n)s[++len]=a[i].idx;
	}
	else{
		rep(i,sta[top]+1,n)s[++len]=a[i].idx;
		while(top){
			rep(i,sta[top-1]+1,sta[top])s[++len]=a[i].idx;
			top--;
		}
	}
	
	printf("%d\n",len);
	per(i,len,1)printf("%d ",s[i]);
	exit(0);
}
int main() {
	read(n);rep(i,1,n)read(a[i].fi),read(a[i].se),a[i].idx=i;
	int cnt=0;rep(i,1,n)cnt+=a[i].fi<a[i].se;
	if(cnt*2>=n){
		rep(i,1,n)if(a[i].fi<a[i].se)
			a[++m]=a[i];
		solve(m);
	}
	else{
		rep(i,1,n)if(a[i].fi>a[i].se)
			a[++m]=a[i],a[m].fi=-a[m].fi,a[m].se=-a[m].se;
		solve(m);
	}
	return 0;
}