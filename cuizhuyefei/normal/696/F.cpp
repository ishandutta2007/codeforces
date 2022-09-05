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
const int N = 1363;const double inf = 2e5,eps=1e-7;
int n,b[N];
struct dot{
	double x,y;
	dot(double X=0,double Y=0){x=X;y=Y;}
}a[N],ans1,ans2,pos[N],q[N],s[N];
struct Line{
	dot a,b;double ang;
}L[N],p[N];
double Abs(double x){return x>0?x:-x;}
dot operator - (const dot &a,const dot &b){return dot(a.x-b.x,a.y-b.y);}
dot operator + (const dot &a,const dot &b){return dot(a.x+b.x,a.y+b.y);}
bool operator == (const dot &a,const dot &b){return Abs(a.x-b.x)<=eps&&Abs(a.y-b.y)<=eps;}
inline int dcmp(double x){return x<=eps&&x>=-eps?0:(x>0?1:-1);}
double operator * (const dot &a,const dot &b){return a.x*b.y-a.y*b.x;}
dot operator * (const dot &a, double k){return dot(a.x*k,a.y*k);}
inline double getlen(const dot &a){return sqrt(a.x*a.x+a.y*a.y);}
double Cross(const dot &a,const dot &b){return a.x*b.y-a.y*b.x;}
bool cmp(const Line &a,const Line &b){return a.ang<b.ang;}
inline dot getinter(dot a, dot b, dot x, dot y){
	dot u=b-a,v=y-x;
	double k=((x-a)*v)/(u*v);
	return a+u*k;
}
bool onleft(dot p, dot a, dot b){
	return Cross(b-a,p-a)>0;
}
bool is_parallel(Line x, Line y){return Abs(Cross(x.b-x.a,y.b-y.a))<=eps;}
struct Halfplane{
	int f,r,len;
	bool solve(Line *p){
		f=1;r=0;
		rep(i,1,len-1)assert(p[i].ang<=p[i+1].ang);
		rep(l,1,len){//if(j==1||p[j].ang-p[j-1].ang>eps)
			int j=l,ri=l;
			while(ri+1<=len&&p[ri+1].ang==p[l].ang){
				ri++;if(onleft(p[ri].a,p[j].a,p[j].b))j=ri;
			}
		//	if(f<r&&(is_parallel(L[f],L[f+1])||is_parallel(L[r],L[r-1])))return 0;
			while(f<r&&!onleft(q[r-1],p[j].a,p[j].b))r--;
			while(f<r&&!onleft(q[f],p[j].a,p[j].b))f++;
			L[++r]=p[j];
			if(f<r)q[r-1]=getinter(L[r].a,L[r].b,L[r-1].a,L[r-1].b);
			l=ri;
		}
		while(f<r&&!onleft(q[r-1],L[f].a,L[f].b))r--;
		while(f<r&&!onleft(q[f],L[r].a,L[r].b))f++;
		
		if(r-f<=1)return 0;
		q[r]=getinter(L[r].a,L[r].b,L[f].a,L[f].b);
	//	cerr<<len<<' '<<f<<' '<<r<<' '<<q[r].x<<' '<<q[r].y<<endl;
	//	rep(j,f,r)cerr<<L[j].a.x<<' '<<L[j].a.y<<' '<<L[j].b.x<<' '<<L[j].b.y<<' '<<L[j].ang<<endl;
	//	rep(j,1,len)cerr<<p[j].a.x<<' '<<p[j].a.y<<' '<<p[j].b.x<<' '<<p[j].b.y<<' '<<p[j].ang<<endl;
	//	rep(i,f,r)assert(onleft(q[r],L[i].a,L[i].b)||Abs(Cross(q[r]-L[i].a,q[r]-L[i].b))<=eps);
	//	rep(i,1,len)assert(onleft(q[r],p[i].a,p[i].b)||Abs(Cross(q[r]-p[i].a,q[r]-p[i].b))<=eps);
		return 1;
	}
	dot getdot(){return getinter(L[f].a,L[f].b,L[f+1].a,L[f+1].b);}
}yzr;

dot Turn90(dot a){return dot(a.y,-a.x);}
dot setlen(dot a, double l){double t=l/getlen(a);return dot(a.x*t,a.y*t);}
/*bool ck(int l, int r, double d){
	int len=0;
	rep(i,1,n)p[++len].a=a[i],p[len].b=a[i+1];
	rep(i,l,r){
		dot x=a[i+1],y=a[i],c=setlen(Turn90(y-x),d);
		p[++len].a=x+c,p[len].b=y+c;
	}
	rep(i,1,4)p[++len].a=bk[i],p[len].b=bk[i+1<=4?i+1:1];
	rep(i,1,len)p[i].ang=atan2(p[i].b.y-p[i].a.y,p[i].b.x-p[i].a.x);
	yzr::init();rep(i,1,len)addline(p[i].a,p[i].b);
	return yzr::solve();
}*/
int len;
Line getLine(int i, double d){
	dot x=a[i+1],y=a[i],c=setlen(Turn90(y-x),d);
	Line p;p.a=x+c,p.b=y+c;p.ang=atan2(p.b.y-p.a.y,p.b.x-p.a.x);
	return p;
}
bool getok(){
//	cerr<<len<<endl;
	yzr.len=len;
	return yzr.solve(p);
}
void erase(Line a){
	rep(i,1,len)if(a.a==p[i].a&&a.b==p[i].b){
		rep(j,i+1,len)p[j-1]=p[j];len--;break;
	}
}
void insert(Line a){
	p[len+1].ang=1e10;
	rep(i,1,len+1)if(a.ang<=p[i].ang){
		per(j,len,i)p[j+1]=p[j];p[i]=a;len++;break;
	}
}
bool ck(double mid){
	len=0;rep(i,1,n)p[++len].a=a[i],p[len].b=a[i+1],p[i].ang=atan2(p[i].b.y-p[i].a.y,p[i].b.x-p[i].a.x);
	sort(p+1,p+len+1,cmp);
	for(int l=1,r=0;l<=n;l++){
		while(r-l<=n&&r+1<2*n){
			r++;insert(getLine(r,mid));
			if(!getok()){erase(getLine(r,mid));r--;break;}
		}
		b[l]=r;getok();pos[l].x=q[yzr.r].x;pos[l].y=q[yzr.r].y;//yzr::m
		erase(getLine(l,mid));
	//	assert(yzr::m);
	//	cerr<<"qaq "<<s[1].x<<' '<<s[1].y<<endl;
	//	cerr<<yzr::m<<endl;
	}
//	rep(i,1,n)cerr<<pos[i].x<<' '<<pos[i].y<<"  ";cerr<<endl;
//	rep(i,1,n)cerr<<b[i]<<' ';cerr<<endl;
	rep(i,1,n)b[i+n]=b[i]+n,pos[i+n]=pos[i];
	rep(l,1,n)if(b[b[l]+1]-l+1>=n){
		ans1=pos[l];ans2=pos[b[l]+1];
		return 1;
	}
	return 0;
}
int main() {
//	bk[1]=dot(-inf,-inf);bk[2]=dot(inf,-inf);bk[3]=dot(inf,inf);bk[4]=dot(-inf,inf);
	read(n);rep(i,1,n){
		int x,y;read(x);read(y);a[i].x=x;a[i].y=y;
	}
	rep(i,1,n)a[i+n]=a[i];
//	cerr<<ck(1,4,2)<<endl;
//	ck(2);
	/*cerr<<ck(1,2,1e-3)<<endl;
	cerr<<ck(2,3,1e-3)<<endl;
	cerr<<ck(3,4,1e-3)<<endl;
	cerr<<ck(3,3,100)<<endl;
	cerr<<ck(3,3,100)<<endl;
	cerr<<ck(3,3,100)<<endl;
	ck(1000);*/
//	cerr<<ck(2.6)<<endl;
	double L=0,R=2e4;
	while(R-L>1e-7){
		double mid=(L+R)/2;
		if(ck(mid))R=mid;else L=mid;
	}
	printf("%.9lf\n",L);
	printf("%.9lf %.9lf\n",ans1.x,ans1.y);
	printf("%.9lf %.9lf\n",ans2.x,ans2.y);
	return 0;
}