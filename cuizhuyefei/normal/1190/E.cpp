#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
#define pi acos(-1)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<double,double> Pdd;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
const int N = 266666;const double eps=1e-11;
int n,m,fa[17][N];Pii a[N];Pdd s[N];double b[N];
double getlen(Pii a){return sqrt(1ll*a.fi*a.fi+1ll*a.se*a.se);}
bool cmp(const Pdd &x, const Pdd &y){return x.se<y.se;}
bool ck(double R){
	int len=0;
	rep(i,1,n){
		double ang=atan2(a[i].se,a[i].fi),alpha=acos(R/getlen(a[i]));
		double x=ang-alpha,y=ang+alpha;//x<=y
		if(x<-pi)x+=2*pi;if(y>pi)y-=2*pi;//[-pi,pi]
		if(x>y)swap(x,y);
		if(y-x<=pi)s[++len]=make_pair(x+2*pi,y+2*pi);
		else s[++len]=make_pair(y,x+2*pi);
	}
	sort(s+1,s+len+1,cmp);
	int sz=1;rep(i,2,len)if(s[i].fi>s[sz].fi)s[++sz]=s[i];len=sz;
	for(int i=1,j=1;i<=len;i++){
		while(j<=len&&s[j].fi<=s[i].se)j++;
		fa[0][i]=j;
	}
	fa[0][len+1]=len+1;
//	rep(i,1,len)printf("%lf %lf %d\n",s[i].fi,s[i].se,fa[0][i]);
	rep(i,1,16)rep(j,1,len+1)fa[i][j]=fa[i-1][fa[i-1][j]];
	if(s[len].fi<=pi)return 1;//m=1 is ok
	sz=0;//b[++sz]=s[len].se;
	rep(i,1,len){
	//	if(s[i].se>=s[len].fi)b[++sz]=s[i].se;
		if(s[i].fi<=pi&&s[i].fi+2*pi>=s[len].fi)b[++sz]=s[i].fi+2*pi;//,b[++sz]=s[i].fi+2*pi+eps;
	}
	b[sz+1]=1e10;rep(i,1,sz+1)if(b[i]>s[len].fi){
		per(j,sz,i)b[j+1]=b[j];b[i]=s[len].fi;sz++;
		break;
	}
//	sort(b+1,b+sz+1); b[++sz]=s[len].fi
	for(int i=1,j=1;i<=sz;i++){
		while(j<=len&&s[j].fi<=b[i]-2*pi+eps)j++;
		int u=j;rep(k,0,16)if((m-1)>>k&1)u=fa[k][u];
		if(u>len||s[u].se>=b[i]-eps){
		//	printf("%lf\n",b[i]);
			return 1;
		}
	}
	return 0;
}
int main() {
	read(n);read(m);double d=1e18;
	rep(i,1,n)read(a[i].fi),read(a[i].se),umin(d,getlen(a[i]));
	if(d<1e-7){printf("%.9lf\n",d);return 0;}
//	cout<<ck(5.6)<<endl;
	double L=0,R=d-1e-7;
	while(R-L>=1e-7){
		double mid=(L+R)/2;
	//	printf("%lf %lf %lf\n",L,R,mid);
		if(ck(mid))L=mid;else R=mid;
	}
	printf("%.9lf\n",L);
	return 0;
}