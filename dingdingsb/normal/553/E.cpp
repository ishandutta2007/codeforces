#pragma GCC optimize(2)
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
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
using ld=double;
namespace Poly{
	const int N=8e4+100;
	const ld pi=acos(-1);
	struct cp{
		ld x,y;
		cp(ld a){x=a,y=0;}
		cp(ld x=0,ld y=0):x(x),y(y){}
		cp operator+(cp rhs){return cp(x+rhs.x,y+rhs.y);}
		cp operator-(cp rhs){return cp(x-rhs.x,y-rhs.y);}
		cp operator*(cp rhs){return cp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
		cp&operator+=(cp rhs){return x+=rhs.x,y+=rhs.y,*this;}
		cp&operator-=(cp rhs){return x-=rhs.x,y-=rhs.y,*this;}
		cp&operator*=(cp rhs){return *this=(*this*rhs);}
	};
	struct poly{
		vector<cp>a;
		cp&operator[](int x){return a[x];}
		void resize(int x){a.resize(x);}
		int size(){return a.size();}
	};
	int rev[N];
	int ext(int n){int k=0;while((1<<k)<n)k++;return k;}
	void init(int k){int n=1<<k;for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));}
	void fft(poly&f,int n,int op){
		for(int i=0;i<n;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
		for(int M=1;M<n;M*=2){
			cp wn=cp(cos(pi/M),op*sin(pi/M));
			for(int i=0;i<n;i+=M*2){
				cp w=cp(1,0);
				for(int j=0;j<M;j++,w*=wn){
					cp x=f[i+j],y=w*f[i+j+M];
					f[i+j]=x+y,f[i+j+M]=x-y;
				}
			}
		}
		if(op<0)for(int i=0;i<n;i++)f[i].x/=n,f[i].y/=n;
	}
	poly&operator*=(poly&a,poly&b){
		int n=a.size()+b.size()-1;int k=ext(n);init(k);
		a.resize(1<<k);fft(a,1<<k,1);
		b.resize(1<<k);fft(b,1<<k,1);
		for(int i=0;i<(1<<k);i++)a[i]*=b[i];
		fft(a,1<<k,-1);a.resize(n);
		return a;
	}
}
const int N=51,M=201,T=4e4+10;
int n,m,t,x,a[M],b[M],c[M],dis[N][N],p[M][T];
ld f[N][T],g[M][T];
void cdq(int l,int r){
	if(l>=t)return;
	if(l==r){
		for(int i=1;i<n;i++)
			f[i][l]=1e18;
		for(int i=1;i<=m;i++)
			chkmn(f[a[i]][l],g[i][l]);
		return;
	}
	cdq(mid+1,r);
	// [mid+1,r]  [l,mid]
	// a b c p  g[i,j] += f[b,j+x] p[x]/100000 = A[j+x-mid-1] B[r-l-x]
	for(int i=1;i<=m;i++){
		Poly::poly A,B;
		A.resize(r-mid);B.resize(r-l);
		for(int j=mid+1;j<=r;j++)A[j-mid-1].x=f[b[i]][j];
		for(int j=1;j<=r-l;j++)B[r-l-j].x=1.*p[i][j]/100000;
		A*=B;
		for(int j=l;j<=mid;j++)g[i][j]+=A[j-mid-1+r-l].x;
	}
	cdq(l,mid);
}
signed main(){
	memset(dis,0x3f,sizeof dis);
	read(n,m,t,x);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		read(a[i],b[i],c[i]);chkmn(dis[a[i]][b[i]],c[i]);
		for(int j=1;j<=t;j++)read(p[i][j]);
		for(int j=0;j<=t;j++)g[i][j]=c[i];
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmn(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<n;i++)
		for(int j=t;j<=2*t;j++)
			f[i][j]=dis[i][n]+x;
	for(int j=t+1;j<=2*t;j++)f[n][j]=x;
	cdq(0,2*t);
	printf("%10lf",(double)f[1][0]);
	cerr<<"";
}