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
typedef pair<ll,ll> Pii;
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
const int N = 233333;
int n,l,a[2020000],b[2020000];
void GG(){puts("NO");exit(0);}
struct YZR{
	ll L,R;
	struct node{
		int p;Pii x;//fi+se*x
		bool operator<(const node &a)const{return p<a.p;}
	}s[N];
	inline void add(ll a, ll b){//a+bx<=0
		if(b==0){if(a<=0)return;GG();}
		if(b>0){//bx<=-a
			ll r=-a/b-1;while(b*(r+1)<=-a)r++;umin(R,r);
		}
		else{//-bx>=a
			ll p=a/(-b)+1;while(-b*(p-1)>=a)p--;umax(L,p);
		}
	}
	inline void solve(int *a){
		int len=n;s[len+1].p=0;s[len+1].x=Pii(0,0);
		s[len+2].p=l;s[len+2].x=Pii(0,1);len+=2;
		sort(s+1,s+len+1);
	//	rep(i,1,len)printf("<%d %d %d>\n",s[i].p,s[i].x.fi,s[i].x.se);
		L=-l;R=l;
		rep(i,1,len-1){
			Pii b=Pii(s[i+1].x.fi-s[i].x.fi,s[i+1].x.se-s[i].x.se);
			int d=s[i+1].p-s[i].p;
			add(b.fi-d,b.se);add(-d-b.fi,-b.se);
		}
		if(l-L&1)L++;if(l-R&1)R--;
		if(L>R)GG();//x=L
		rep(i,1,l)a[i]=-1;
		rep(i,1,len-1)if(s[i].p<s[i+1].p){
			int d=s[i+1].p-s[i].p,dif=(s[i+1].x.fi+s[i+1].x.se*L)-(s[i].x.fi+s[i].x.se*L);
			int cnt=(dif+d)/2;assert(cnt*2-d==dif&&cnt>=0&&cnt<=d);
			rep(j,s[i].p+1,s[i].p+cnt)assert(j<=s[i+1].p),a[j]=1;
		}
		static int qz[2020000];rep(i,1,l)qz[i]=qz[i-1]+a[i];assert(qz[l]==L);
		rep(i,1,len)assert(qz[s[i].p]==s[i].x.fi+s[i].x.se*L);
	//	rep(i,1,l)printf("%d ",a[i]);puts("");
	}
}yzr,zzy;
int main() {
	read(n);read(l);
	rep(i,1,n){
		ll t,a,b;read(t);read(a);read(b);
		ll x=a+b,y=b-a;
		yzr.s[i].p=t%l;yzr.s[i].x.fi=x;yzr.s[i].x.se=-(t/l);
		zzy.s[i].p=t%l;zzy.s[i].x.fi=y;zzy.s[i].x.se=-(t/l);
	}
	yzr.solve(a);zzy.solve(b);
	rep(i,1,l){
		if(a[i]==1&&b[i]==1)putchar('U');
		if(a[i]==1&&b[i]==-1)putchar('R');
		if(a[i]==-1&&b[i]==1)putchar('L');
		if(a[i]==-1&&b[i]==-1)putchar('D');
	}
	return 0;
}