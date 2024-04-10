#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define pi acos(-1)
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
const int N = 1<<18|3, mo1=491,mo2=499,mo=490019;
int n=1e5,m=1e5,c,a[N],b[N];bool vis[N];
int A[2][mo1+2][mo2+2],B[2][mo1+2][mo2+2];
int g1,g2,dy1[mo1+2],dy2[mo2+2],mi1[mo1+2],mi2[mo2+2];
struct E{
	double a,b;//a+bi
	E(double A=0,double B=0){a=A;b=B;}
	double real(){return a;}
	double imag(){return b;}
};
E operator +(const E &x, const E &y){return E(x.a+y.a,x.b+y.b);}
E operator -(const E &x, const E &y){return E(x.a-y.a,x.b-y.b);}
E operator *(const E &x, const E &y){return E(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);}
E f[1<<20|3],g[1<<20|3];int h[1<<20|3],aa[mo+3],bb[mo+3],ans[mo+2];
vector<E>w[21];
void initw(int n){
	for(int j=2,d=1;j<=n;j<<=1,d++)
		rep(i,0,(j>>1)-1)w[d].pb(E(cos(2*pi/j*i),sin(2*pi/j*i)));
}
inline void fft(E *a, int n, int tp){
	for(int i=1,j=0;i<n;i++){
		for(int k=n>>1;!((j^=k)&k);k>>=1);if(i<j)swap(a[i],a[j]);
	}
	for(int j=2,d=1;j<=n;j<<=1,d++){
		for(register int k=0;k<n;k+=j)rep(i,0,(j>>1)-1){
			E x=a[k+i],y=E(w[d][i].a,w[d][i].b*tp)*a[k+i+(j>>1)];
			a[k+i]=x+y;a[k+i+(j>>1)]=x-y;
		}
	}
}
inline void mul(E *a, E *b, int n, int *c){
	fft(a,n,1);fft(b,n,1);rep(i,0,n-1)a[i]=a[i]*b[i];
	fft(a,n,-1);rep(i,0,n-1)h[i]=(ll(a[i].real()/n+0.5))%mo;
}
int getg(int mo){
	rep(g,2,mo-1){
		bool gg=0;
		for(int i=1,j=g;i<=mo-2;i++,j=1LL*j*g%mo)
			if(j==1){gg=1;break;}
		if(!gg)return g;
	}
	return -1;
}
int power(int a, int n, int mo){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
int en(int i, int j){return i*2*mo2+j;}
Pii de(int c){return Pii(c/(2*mo2),c%(2*mo2));}
int rec[2][mo1+2][mo2+2];
int getv(int i, int j, int k){//CRT
	if(rec[i][j][k]>=0)return rec[i][j][k];assert(0);
	/*int p[3]={2,mo1,mo2};int a[3]={i,j,k};int res=0;
	int mo=p[0]*p[1]*p[2];
	rep(i,0,2){
		int v=1;rep(j,0,2)if(i!=j)v=1LL*v*p[j];
		res=(res+1LL*a[i]*v%mo*power(v,p[i]-2,p[i]))%mo;
	}
	return rec[i][j][k]=res;*/
}
void add(int &x, int y){x=(x+y)%mo;}
void sub(int &x, int y){x=(x-y+mo)%mo;}
int main() {
	memset(rec,-1,sizeof(rec));rep(i,0,mo-2)rec[i%2][i%mo1][i%mo2]=i;
	initw(1<<20);read(n);read(m);read(c);
	rep(i,0,n-1)read(a[i]);
	rep(i,0,m-1)read(b[i]);
	rep(i,0,max(n,m)-1)if(1LL*i*i*i%mo1==0||1LL*i*i*i%mo2==0)vis[i]=1;
	g1=getg(mo1);g2=getg(mo2);//cerr<<g1<<' '<<g2;
	rep(i,0,mo1-2)dy1[power(g1,i,mo1)]=i,mi1[i]=power(g1,i,mo1);
	rep(i,0,mo2-2)dy2[power(g2,i,mo2)]=i,mi2[i]=power(g2,i,mo2);
	rep(i,0,n-1)if(!vis[i]){
		add(A[i%2][dy1[1LL*i*i%mo1]][dy2[1LL*i*i%mo2]],a[i]);
	}
	rep(i,0,m-1)if(!vis[i]){
		add(B[i%2][dy1[1LL*i*i*i%mo1]][dy2[1LL*i*i*i%mo2]],b[i]);
	}
	//1
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	rep(i,0,mo1-1)rep(j,0,mo2-1)f[en(i,j)]=A[1][i][j];
	rep(i,0,mo1-1)rep(j,0,mo2-1)g[en(i,j)]=B[1][i][j];
	mul(f,g,1<<20,h);rep(i,0,(1<<20)-1){//aa[en(de(i).fi%mo1,de(i).se%mo2)]+=h[i];//1
		sub(ans[getv(0,mi1[de(i).fi%(mo1-1)],mi2[de(i).se%(mo2-1)])],h[i]);
		add(ans[getv(1,mi1[de(i).fi%(mo1-1)],mi2[de(i).se%(mo2-1)])],h[i]);
	}
	//2
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	rep(i,0,mo1-1)rep(j,0,mo2-1)f[en(i,j)]=A[0][i][j]+A[1][i][j];
	rep(i,0,mo1-1)rep(j,0,mo2-1)g[en(i,j)]=B[0][i][j]+B[1][i][j];
	mul(f,g,1<<20,h);rep(i,0,(1<<20)-1)//bb[en(de(i).fi%mo1,de(i).se%mo2)]+=h[i];//0
		add(ans[getv(0,mi1[de(i).fi%(mo1-1)],mi2[de(i).se%(mo2-1)])],h[i]);
	/*rep(i,0,mo-1)bb[i]=(bb[i]-aa[i])%mo;
	rep(i,0,mo1-1)rep(j,0,mo2-1)ans[getv(0,i,j)]=bb[i],ans[getv(1,i,j)]=aa[i];*/
	
	rep(i,0,n-1)if(vis[i])rep(j,0,m-1)add(ans[1LL*i*i*j%(mo-1)*j%(mo-1)*j%(mo-1)],1LL*a[i]*b[j]%mo);//WA
	rep(j,0,m-1)if(vis[j])rep(i,0,n-1)if(!vis[i])add(ans[1LL*i*i*j%(mo-1)*j%(mo-1)*j%(mo-1)],1LL*a[i]*b[j]%mo);
//	rep(i,0,mo-1)if(ans[i])printf("%d:%d\n",i,ans[i]);
	ll res=0,now=1;
	rep(i,0,mo-1)res=(res+1LL*ans[i]*now)%mo,now=1LL*now*c%mo;
	printf("%lld\n",(res%mo+mo)%mo);
	return 0;
}