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
mt19937 rnd(random_device{}());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
	mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define sq(x) ((x)*(x))
const int N=2e5+10,M=19;
typedef double db;
const db pi=acos(-1);
int n,m;
db x[N],y[N];
struct seg{
	db l,r;
	seg(db L=0,db R=0){
		l=L,r=R;
		if(l<0)l+=2*pi,r+=2*pi;
	}
	bool operator<(const seg rhs)const{return l<rhs.l;}
}s[N];
db dis(db x,db y){return sqrt(sq(x)+sq(y));}
int f[N][M];
int jump(int u,int x){
	int now=0;
	while(x){
		if(x&1)u=f[u][now];
		now++;x>>=1;
	}
	return u;
}
bool chk(db d){
	for(int i=1;i<=n;i++){
		db ang=atan2(y[i],x[i]);
		db delta=acos(d/dis(x[i],y[i]));
		s[i]=seg(ang-delta,ang+delta);
		s[i+n]=seg(s[i].l+2*pi,s[i].r+2*pi);
	}
	sort(s+1,s+1+2*n);
	f[2*n+1][0]=2*n+1;
	for(int i=2*n,cur=2*n;i;i--){
		while(s[cur].l>s[i].r)cur--;
		f[i][0]=cur+1;
	}
	for(int i=1;i<M;i++)
		for(int j=1;j<=2*n+1;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1;i<=n;i++)
		if(jump(i,m)>=i+n)
			return true;
	return false;
}
signed main(){
	read(n,m);
	db L=0,R=1e9;
	for(int i=1;i<=n;i++)read(x[i],y[i]),chkmn(R,dis(x[i],y[i]));
	if(R<1e-6)return writeln(0),0;
	for(int SJYAK=0;SJYAK<=50;SJYAK++){
		db Mid=(L+R)/2;
		if(chk(Mid))L=Mid;
		else R=Mid;
	}
	printf("%.10lf",L);
	cerr<<"";
}