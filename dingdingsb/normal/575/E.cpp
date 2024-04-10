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
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define int long long
#define sq(x) (x)*(x)
const int N=2e6+100,V=1e5;
typedef long double db;
int n,top;
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
	point operator-(point b){return point(x-b.x,y-b.y);}
	ll operator*(point b){return x*b.y-y*b.x;}
	bool operator<(const point b)const{return mp(x,y)<mp(b.x,b.y);}
	bool operator==(const point b)const{return mp(x,y)==mp(b.x,b.y);}
}p[N],s[N];
int cnt;
void add(int x,int y){if(0<=x&&x<=V&&0<=y&&y<=V)p[++cnt]=point(x,y);}
void add(int x1,int y1,int x2,int y2){
	//(x1,y1) - (x2,y2) 
	int k,b;
	k=(x2-x1)/(y2-y1),b=y1-k*x1;
	if(min(x1,x2)<=0&&0<=max(x1,x2))add(0,b);
	if(min(x1,x2)<=V&&V<=max(x1,x2))add(V,V*k+b);
	swap(x1,y1);swap(x2,y2);
	k=(x2-x1)/(y2-y1),b=y1-k*x1;
	if(min(x1,x2)<=0&&0<=max(x1,x2))add(b,0);
	if(min(x1,x2)<=V&&V<=max(x1,x2))add(V*k+b,V);
}
db calc(point A,point B,point C){
	if((A-B)*(C-B)==0)return -114514;
	db x=.5*(A.y*sq(B.x)-sq(A.x)*B.y-sq(A.y)*B.y+A.y*sq(B.y)-A.y*sq(C.x)+B.y*sq(C.x)+sq(A.x)*C.y+sq(A.y)*C.y-sq(B.x)*C.y-sq(B.y)*C.y-A.y*sq(C.y)+B.y*sq(C.y))/
	(A.y*B.x-A.x*B.y-A.y*C.x+B.y*C.x+A.x*C.y-B.x*C.y);
	swap(A.x,A.y);swap(B.x,B.y);swap(C.x,C.y);
	db y=.5*(A.y*sq(B.x)-sq(A.x)*B.y-sq(A.y)*B.y+A.y*sq(B.y)-A.y*sq(C.x)+B.y*sq(C.x)+sq(A.x)*C.y+sq(A.y)*C.y-sq(B.x)*C.y-sq(B.y)*C.y-A.y*sq(C.y)+B.y*sq(C.y))/
	(A.y*B.x-A.x*B.y-A.y*C.x+B.y*C.x+A.x*C.y-B.x*C.y);
	swap(A.x,A.y);
	return sq(A.x-x)+sq(A.y-y);
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++){
		int x,y,v;read(x,y,v);
		add(x-v,y);add(x+v,y);add(x,y-v);add(x,y+v);
		if(v)
		add(x-v,y,x,y-v),
		add(x,y-v,x+v,y),
		add(x+v,y,x,y+v),
		add(x,y+v,x-v,y);
		for(int X=0;X<=V;X+=V)
			for(int Y=0;Y<=V;Y+=V)
				if(abs(X-x)+abs(Y-y)<=v)
					add(X,Y);
	}
	sort(p+1,p+1+cnt);cnt=unique(p+1,p+1+cnt)-p-1;
	for(int i=1;i<=cnt;i++){
		while(top>1&&(p[i]-s[top-1])*(s[top]-s[top-1])<=0)top--;
		s[++top]=p[i];
	}
	int tmp=top;
	for(int i=cnt-1;i;i--){
		while(top>tmp&&(p[i]-s[top-1])*(s[top]-s[top-1])<=0)top--;
		s[++top]=p[i];
	}
	top--;
	tuple<db,point,point,point>res;get<0>(res)=-1e9;
	for(int i=1;i<=top;i++){
		point A=s[i],B=s[i%top+1],C=s[(i+1)%top+1];
		chkmx(res,mt(calc(A,B,C),A,B,C));
	}
	writeln(get<1>(res).x,get<1>(res).y);
	writeln(get<2>(res).x,get<2>(res).y);
	writeln(get<3>(res).x,get<3>(res).y);
}