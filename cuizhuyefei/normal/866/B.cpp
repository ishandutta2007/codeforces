#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;
int n,s;Pii a[N];ll res;
int main() {
	read(n);read(s);ll tot=0;
	rep(i,1,n){
		int x,y;
		read(a[i].fi),read(x),read(y);tot+=a[i].fi;
		res+=1ll*a[i].fi*x;a[i].se=y-x;
		swap(a[i].fi,a[i].se);
	}
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	tot=(tot+s-1)/s*s;
	rep(i,1,n)tot-=a[i].se;ll cur=res;
	ll tmp=0;rep(i,1,n)tmp+=(a[i].fi>=0)*a[i].se;
	tmp=tmp/s*s;int p=1;assert(tot>=0);
	while(tmp){
		if(tmp>=a[p].se){
			tmp-=a[p].se;cur+=1ll*a[p].se*a[p].fi;a[p].se=0;p++;
			continue;
		}
		cur+=1ll*a[p].fi*tmp;a[p].se-=tmp;tmp=0;
	}
	//tot,tmp
	umax(res,cur);
	tot-=s;tmp+=s;
//	printf("%lld %lld %lld\n",tot,tmp,cur);
//	rep(i,p,n)printf("%d\n",a[i].se);
	while(p<=n){
		if(!a[p].se){p++;continue;}
		if(!tmp)break;
		if(tot<0||a[p].fi>=0){
			cur+=a[p].fi;a[p].se--;tot++;tmp--;
		}
		else break;
	}
	if(tot>=0&&tmp>=0)umax(res,cur);
	cout<<res;
	return 0;
}