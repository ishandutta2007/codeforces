#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 200200;
int n,k,m,x[N],size,len;
Pii v[N],a[N],s[N];
inline void insert(Pii x) {
	if (s[len].fi==x.fi) {(s[len].se+=x.se)%=k;}
	else s[++len]=x; if (!s[len].se) len--;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(k); read(m); rep(i,1,n) read(x[i]);
	rep(i,1,n) {
		if (x[i]==v[size].fi) {v[size].se++; v[size].se%=k;}
		else v[++size]=Pii(x[i],1); if (!v[size].se) size--;
	//	int j=i+1; for (;j<=n; j++) if (x[j]!=x[i]) break;
	//	v[++size]=Pii(x[i],(j-1-i+1)%k); if (!v[size].second) size--;
	//	i=j-1;
	}
	rep(i,1,size) a[i]=v[i];
	int l=1,r=size;
	while (l<r && a[l].fi==a[r].fi && a[l].se+a[r].se>=k) {
		a[l].se=(a[l].se+a[r].se)%k; a[r].se=0;
		r--; if (!a[l].se) l++;
	}
	ll ans1=0,ans2=0;
	rep(i,1,size) ans1+=v[i].se; rep(i,l,r) ans2+=a[i].se;
//	if (l<r && ans1+ans2*(m-1)==822000) {printf("%d %d %d %lld %lld %d %d %d %d\n",size,l,r,ans1,ans2,a[l].fi,a[r].fi,a[l].se,a[r].se); return 0;}
	if (l<r) {printf("%lld",ans1+ans2*(m-1)); return 0;}
	rep(i,1,l-1) insert(v[i]);
	if (l==r) insert(Pii(a[l].fi,1LL*a[l].se*m%k));
	rep(i,r+1,size) insert(v[i]);
	ll ans=0; rep(i,1,len) ans+=s[i].se;
//	rep(i,1,len) printf("%d : %d %d\n",i,s[i].fi,s[i].se);
	printf("%lld",ans);
	return 0;
}