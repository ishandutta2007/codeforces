#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define lc (x<<1)
#define rc (x<<1|1)
typedef double db;
const db eps=1e-8;
const int N=2e3+10;
struct point{
	db x,y;
	point(db x=0,db y=0):x(x),y(y){}
	point operator+(point rhs){return point(x+rhs.x,y+rhs.y);}
	point operator-(point rhs){return point(x-rhs.x,y-rhs.y);}
	point operator*(db rhs){return point(x*rhs,y*rhs);}
	point operator/(db rhs){return point(x/rhs,y/rhs);}
	db dis(){return sqrt(x*x+y*y);}
};
db dot(point a,point b){return a.x*b.x+a.y*b.y;}
db cross(point a,point b){return a.x*b.y-a.y*b.x;}
struct line{
	point p,way;db ang;
	line(){}
	line(point a,point b){p=a,way=b,ang=atan2(b.y,b.x);}
	bool operator<(line rhs){return ang<rhs.ang;}
	void out(){
		printf("(%lf x)+(%lf y)+(%lf)>=0\n",-way.y,way.x,cross(p,way));
	}
};
bool onright(line a,point b){return cross(a.way,b-a.p)<=-eps;}
point intersect(line a,line b){
	db x=cross(b.way,a.p-b.p)/cross(a.way,b.way);
	return a.p+a.way*x;
}
line que[N];int head,tail;
bool halfplane(int n,line*a,point*p){
	//for(int i=1;i<=n;i++)a[i].out();
	head=tail=0;que[head]=a[1];
	for(int i=2;i<=n;i++){
		while(head<tail&&onright(a[i],p[tail]))tail--;
		while(head<tail&&onright(a[i],p[head+1]))head++;
		que[++tail]=a[i];
		if(abs(cross(que[tail].way,que[tail-1].way))<=eps){
			if(onright(que[tail],que[tail-1].p)&&dot(que[tail].way,que[tail-1].way)<=-eps)return 0;
			tail--;
			if(!onright(que[tail],a[i].p))que[tail]=a[i];
		}
		if(head<tail)p[tail]=intersect(que[tail],que[tail-1]);
	}
	while(head<tail&&onright(que[head],p[tail]))tail--;
	if(tail-head<=1)return 0;
	p[head]=intersect(que[tail],que[head]);
	return 1;
}
int n;
struct myline{
	line l;int id;point delta;
	//l.p += delta * mid
	bool operator<(myline rhs){return l<rhs.l;}
}a[N];
point p[N];
point t[N];line ls[N];
int ed[N];
bool pd(int l,int r,db mid){
	int o=0;
	for(int i=1;i<=3*n;i++)if((l<=a[i].id&&a[i].id<=r)||!a[i].id)
		ls[++o]=a[i].l,ls[o].p=ls[o].p+a[i].delta*mid;
	return halfplane(o,ls,t);
}
bool chk(db mid){
	for(int i=1,j=1;i<=2*n;i++){
		while(j<2*n&&j+1<i+n&&pd(i,j+1,mid))j++;
		ed[i]=j;
	}
	for(int i=1;i<=n;i++)
		if(ed[ed[i]+1]>=i+n-1)
			return 1;
	return 0;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(p[i].x,p[i].y);
	for(int i=1;i<=n;i++){
		a[3*i-2].l=line(p[i],p[i%n+1]-p[i]);a[3*i-2].id=0;
		a[3*i-1].l=line(p[i],p[i]-p[i%n+1]);a[3*i-1].id=i;
		a[3*i  ].l=line(p[i],p[i]-p[i%n+1]);a[3*i  ].id=i+n;
	}
	for(int i=1;i<=4*n;i++)if(i%3!=1)
		a[i].delta=point(a[i].l.way.y,-a[i].l.way.x),
		a[i].delta=a[i].delta/a[i].delta.dis();
	sort(a+1,a+1+3*n);
	db l=0,r=1e4;
		for(int SJYAK=1;SJYAK<=50;SJYAK++){
		db mid=(l+r)/2;
		if(chk(mid))r=mid;
		else l=mid;
	}
	printf("%.8lf\n",l+eps);
	chk(l+eps);
	for(int i=1;i<=n;i++)if(ed[ed[i]+1]>=n+i-1){
		pd(i,ed[i],l+eps);
		printf("%.8lf %.8lf\n",t[head].x,t[head].y);
		pd(ed[i]+1,n+i-1,l+eps);
		printf("%.8lf %.8lf\n",t[head].x,t[head].y);
		return 0;
	}
	return 0;
	cerr<<"";
}