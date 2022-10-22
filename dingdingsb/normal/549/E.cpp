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
using ld=long double;
const ld eps=1e-10;
struct point{
	int x,y;
	point(ld x=0,ld y=0):x(x),y(y){}
	point operator+(point rhs){return point(x+rhs.x,y+rhs.y);}
	point operator-(point rhs){return point(x-rhs.x,y-rhs.y);}
	bool operator<(const point rhs){return mp(x,y)<mp(rhs.x,rhs.y);}
};
int dot(point a,point b){return a.x*b.x+a.y*b.y;}
int cross(point a,point b){return a.x*b.y-a.y*b.x;}
const int N=1e4+100;
int n,m;point a[N],b[N],s[2*N];int top;
void chk(point x,point y){
	//xy
	ld l=-1e100,r=1e100;
	for(int i=1;i<=n;i++){
		if(!cross(x-a[i],y-a[i]))continue;
		if(cross(a[i]-x,y-x)<0)chkmx(l,(ld)dot(x-a[i],y-a[i])/cross(x-a[i],y-a[i]));
		else chkmn(r,(ld)dot(x-a[i],y-a[i])/cross(x-a[i],y-a[i]));
	}
	for(int i=1;i<=m;i++){
		if(!cross(x-b[i],y-b[i])){
			if(min(x.x,y.x)<=b[i].x&&b[i].x<=max(x.x,y.x)&&min(x.y,y.y)<=b[i].y&&b[i].y<=max(x.y,y.y))return;
			continue;
		}
		if(cross(b[i]-x,y-x)>=0)chkmx(l,(ld)dot(x-b[i],y-b[i])/cross(x-b[i],y-b[i]));
		else chkmn(r,(ld)dot(x-b[i],y-b[i])/cross(x-b[i],y-b[i]));
	}
	if(l+eps<r)puts("YES"),exit(0);
}
void dfs(int l,int r){
	if(abs(r-l)<=1)return;
	pair<ld,int>mn=mp(1e100,0);
	for(int i=l+1;i<r;i++)
		chkmn(mn,mp((ld)dot(s[i]-s[l],s[i]-s[r])/cross(s[i]-s[l],s[i]-s[r]),i));
	chk(s[l],s[mn.se]);chk(s[r],s[mn.se]);
	dfs(l,mn.se);dfs(mn.se,r);
}
void solve(){
	top=0;
	for(int i=1;i<=n;i++){
		while(top>1&&cross(s[top]-s[top-1],a[i]-s[top-1])<=0)top--;
		s[++top]=a[i];
	}
	int tmp=top;
	for(int i=n-1;i;i--){
		while(top>tmp&&cross(s[top]-s[top-1],a[i]-s[top-1])<=0)top--;
		s[++top]=a[i];
	}
	top--;
	chk(s[1],s[top]);
	dfs(1,top);
}
signed main(){
	read(n,m);
	if(min(n,m)<=1)return puts("YES"),0;
	for(int i=1;i<=n;i++)read(a[i].x,a[i].y);
	for(int i=1;i<=m;i++)read(b[i].x,b[i].y);
	sort(a+1,a+1+n);sort(b+1,b+1+m);
	solve();
	swap(n,m);swap(a,b);
	solve();
	puts("NO");
}