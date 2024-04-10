#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;
typedef double ld;
const ld Pi=3.14159265358979323846;
const int Mod=490019,Mod2=491,Mod3=499,G2=2,G3=7;

int n,m,c,a[100010],b[100010];
int log491[550],log499[550];
inline void add(int &x,ll y){
	x=(x+y)%Mod;
}
namespace FFT{
	struct Complex{
		ld x,y;
	};
	Complex operator+(Complex x,Complex y){return (Complex){x.x+y.x,x.y+y.y};}
	Complex operator-(Complex x,Complex y){return (Complex){x.x-y.x,x.y-y.y};}
	Complex operator*(Complex x,Complex y){return (Complex){x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x};}
	Complex operator/(Complex x,int y){return (Complex){x.x/y,x.y/y};}
	Complex Wn[1025];
	int maxw=1024,btw=10,id[1024];
	Complex A[1024][1024],B[1024][1024],C[1024][1024],D[1024][1024];  //96MB
	void prepare(){
		Wn[0]=Wn[maxw]=(Complex){1,0};
		for (int i=1;i<maxw;i++)
			Wn[i]=(Complex){cos(2*Pi*i/maxw),sin(2*Pi*i/maxw)},
			id[i]=(id[i>>1]>>1)|((i&1)<<btw-1);
	}
	void fft(Complex w[1024],int tp)
	{
		static Complex x,y;
		for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
		for (int midlen=1,len=2;midlen<maxw;midlen=len,len<<=1)
			for (int l=0,stp=maxw/len;l<maxw;l+=len)
				for (int u=l,cur=(tp==1?0:maxw);u-l<midlen;u++,cur+=stp*tp){
					x=w[u],y=w[u+midlen]*Wn[cur];
					w[u]=x+y; w[u+midlen]=x-y;
				}
		if (tp==-1) for (int i=0;i<maxw;i++) w[i]=w[i]/maxw;
	}
	void dbfft(Complex w[1024][1024],int tp)
	{
		static Complex bin[1024];
		for (int i=0;i<maxw;i++) fft(w[i],tp);
		for (int i=0;i<maxw;i++){
			for (int j=0;j<maxw;j++) bin[j]=w[j][i];
			fft(bin,tp);
			for (int j=0;j<maxw;j++) w[j][i]=bin[j];
		}
	}
}
using namespace FFT;
int sum[500000];
int stk[100010],stktop;
int main()
{
	for (int i=0,t=1;i<=Mod2-2;i++,t=t*G2%Mod2) log491[t]=i;
	for (int i=0,t=1;i<=Mod3-2;i++,t=t*G3%Mod3) log499[t]=i;
	
	n=read()-1,m=read()-1,c=read();
	for (int i=0;i<=n;i++) a[i]=read();
	for (int i=0;i<=m;i++) b[i]=read();
	
	for (int i=0;i<=n;i++){
		if (i%491==0||i%499==0) continue;
		A[log491[1LL*i*i%491]][log499[1LL*i*i%499]].x+=a[i];
		if (i&1) C[log491[1LL*i*i%491]][log499[1LL*i*i%499]].x+=a[i];
	}
	for (int i=0;i<=m;i++){
		if (i%491==0||i%499==0) continue;
		B[log491[1LL*i*i*i%491]][log499[1LL*i*i*i%499]].x+=b[i];
		if (i&1) D[log491[1LL*i*i*i%491]][log499[1LL*i*i*i%499]].x+=b[i];
	}
	prepare(); dbfft(A,1); dbfft(B,1); dbfft(C,1); dbfft(D,1);
	for (int i=0;i<maxw;i++) for (int j=0;j<maxw;j++) A[i][j]=A[i][j]*B[i][j],C[i][j]=C[i][j]*D[i][j];
	dbfft(A,-1); dbfft(C,-1);
	for (int i=0;i<maxw;i++)
		for (int j=0;j<maxw;j++)
		{
			if (i<=Mod2-2&&j<=Mod3-2) continue;
			A[i%(Mod2-1)][j%(Mod3-1)].x+=A[i][j].x;
			C[i%(Mod2-1)][j%(Mod3-1)].x+=C[i][j].x;
		}
	
	for (int i=0;i<=Mod-2;i++){
		if (i%491==0||i%499==0) continue;
		if (i&1) add(sum[i],(ll)(C[log491[i%491]][log499[i%499]].x+0.5));
		else add(sum[i],(ll)(A[log491[i%491]][log499[i%499]].x-C[log491[i%491]][log499[i%499]].x+0.5));
	}
	
	for (int i=0;i<=m;i++) if (i%491==0||i%499==0) stk[++stktop]=i;
	for (int i=0;i<=n;i++)
		if (i%491==0||i%499==0)
			for (int j=0;j<=m;j++)
				add(sum[1LL*j*j*j%(Mod-1)*i*i%(Mod-1)],a[i]*b[j]);
		else for (int j=1;j<=stktop;j++) add(sum[1LL*stk[j]*stk[j]*stk[j]%(Mod-1)*i*i%(Mod-1)],a[i]*b[stk[j]]);
	
	int ans=0;
	for (int i=0,t=1;i<=Mod-2;i++,t=1LL*t*c%Mod) add(ans,1LL*t*sum[i]);
	printf("%d\n",ans);
	return 0;
}