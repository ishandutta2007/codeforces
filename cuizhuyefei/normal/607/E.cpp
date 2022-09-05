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
const int N = 100500;const double eps=1e-7;
int n,m,v[N];
inline void add(int p){while(p<=n*2)v[p]++,p+=p&-p;}
inline int qry(int p){int r=0;while(p)r+=v[p],p-=p&-p;return r;}
struct dot{
	double x,y;
	dot(double X=0,double Y=0){
		x=X;y=Y;
	}
}s[N],O;pair<double,int>c[N];
inline dot operator -(const dot &a,const dot &b){return dot(a.x-b.x,a.y-b.y);}
inline dot operator +(const dot &a,const dot &b){return dot(a.x+b.x,a.y+b.y);}
inline double Cross(const dot &a,const dot &b){return a.x*b.y-a.y*b.x;}
inline double getlen(const dot &a){return sqrt(a.x*a.x+a.y*a.y);}
inline double Abs(double x){return x>0?x:-x;}
inline bool Online(const dot &p,const dot &a,const dot &b){
	return Abs(Cross(p-a,p-b))<=eps;
}
inline double getdis(const dot &p,const dot &a,const dot &b){
	return Abs(Cross(b-p,a-p))/getlen(b-a);
}
inline dot setlen(const dot &a, double l){
	double t=l/getlen(a);return dot(a.x*t,a.y*t);
}
bool cmp(const pair<double,int> &a,const pair<double,int> &b){
	return a.fi<b.fi;
//	return atan2(a.fi.y-O.y,a.fi.x-O.x)<atan2(b.fi.y-O.y,b.fi.x-O.x);
}
inline int ini(double r){
	int len=0;
	rep(i,1,n){
		dot a=dot(0,s[i].y),b=dot(1,s[i].x+s[i].y);
		double dis=getdis(O,a,b);
		if(dis>r)continue;
		dot f=b-a;f=setlen(dot(-f.y,f.x),dis);
		dot p=Online(O+f,a,b)?O+f:O-f;
		len++;dot t=p+setlen(b-a,sqrt(r*r-dis*dis));c[len*2-1]=pair<double,int>(atan2(t.y-O.y,t.x-O.x),i);
		t=p-setlen(b-a,sqrt(r*r-dis*dis));c[len*2]=pair<double,int>(atan2(t.y-O.y,t.x-O.x),i);
	//	cerr<<i<<endl;
	}
	sort(c+1,c+len*2+1,cmp);
//	rep(i,1,len*2)cerr<<c[i].se<<' ';cerr<<endl;
	return len;
}
ll calc(double r){
	int len=ini(r);rep(i,1,n*2)v[i]=0;
	static int bg[N],ed[N];
	rep(i,1,len*2)ed[c[i].se]=i;
	per(i,len*2,1)bg[c[i].se]=i;
	ll res=0;
	rep(i,1,len*2)
		if(bg[c[i].se]==i){
		//	cerr<<bg[c[i].se]<<' '<<ed[c[i].se]<<' '<<qry(bg[c[i].se])<<' '<<qry(ed[c[i].se])<<endl;
			res+=qry(ed[c[i].se])-qry(bg[c[i].se]);add(ed[c[i].se]);
		}
	return res;
}
inline dot getinter(int i, int j){
	return dot((s[j].y-s[i].y)/(s[i].x-s[j].x),(s[i].x*s[j].y-s[j].x*s[i].y)/(s[i].x-s[j].x));
}
double getans(double r){
	int len=ini(r);rep(i,1,n*2)v[i]=0;
	static int bg[N],ed[N];
	rep(i,1,len*2)ed[c[i].se]=i;
	per(i,len*2,1)bg[c[i].se]=i;
	double res=r*m;
	set<int>Set;
	rep(i,1,len*2)
		if(bg[c[i].se]==i){
			set<int>::iterator it=Set.lower_bound(i);
			while(it!=Set.end()&&(*it)<=ed[c[i].se]){
				res+=getlen(getinter(c[i].se,c[*it].se)-O)-r;it++;
			//	if(n==2000)cout<<getlen(getinter(c[i].se,c[*it].se)-O)<<endl;
			}
			Set.insert(ed[c[i].se]);
		}
	return res;
}
int main() {
	read(n);
	int _;read(_);O.x=_/1000.0;
	read(_);O.y=_/1000.0;
	read(m);
	rep(i,1,n){
		read(_);s[i].x=_/1000.0;
		read(_);s[i].y=_/1000.0;
	}
//	printf("%lld\n",calc(sqrt(2)+eps));return 0;
//	printf("%lld\n",calc(4*sqrt(2)+eps));
//	printf("%lld\n",calc(6));
	double l=0,r=1e10;
	rep(t,1,65){
		double mid=(l+r)/2;
	//	printf("%.9lf %.9lf\n",l,r);
		if(calc(mid)>m)r=mid;else l=mid;
	}
//	if(n==2000)cout<<l<<endl;
//	printf("%.9lf %.9lf\n",l,r);
	printf("%.9lf\n",getans(l));
	return 0;
}