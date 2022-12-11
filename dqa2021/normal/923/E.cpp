#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
void print(int x){
	if (x>9) print(x/10); putchar((x%10)^48);
}
#undef G
typedef long long ll;
const int Mod=998244353,G=3,inv2=Mod+1>>1;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
int upd(int x){return x+(x>>31&Mod);}
int fac[100010],ifac[100010];

int n,w[100010]; ll m;
namespace NTT{
	const int MAXX=262144;
	int imaxw[40],Wn[MAXX|1];
	int maxw,btw,id[MAXX];
	int A[MAXX],B[MAXX];
	void prepare(int len)
	{
		imaxw[0]=1; for (int i=1;i<40;i++) imaxw[i]=1LL*imaxw[i-1]*inv2%Mod;
		for (maxw=1,btw=0;maxw<=len;maxw<<=1,btw++);
		Wn[0]=Wn[maxw]=1;
		for (int i=1,t=qpow(G,(Mod-1)/maxw);i<maxw;i++)
			Wn[i]=1LL*Wn[i-1]*t%Mod,
			id[i]=(id[i>>1]>>1)|((i&1)<<btw-1);
	}
	void ntt(int *w,int tp)
	{
		for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
		for (int midlen=1,len=2;midlen<maxw;midlen=len,len<<=1)
			for (int l=0,stp=maxw/len;l<maxw;l+=len)
				for (int u=l,cur=(tp==1?0:maxw),x,y;u-l<midlen;u++,cur+=stp*tp)
				{
					x=w[u],y=1LL*Wn[cur]*w[u+midlen]%Mod;
					w[u]=upd(x+y-Mod); w[u+midlen]=upd(x-y);
				}
	}
}
using namespace NTT;
int main()
{
	n=read(); scanf("%I64d",&m); for (int i=0;i<=n;i++) w[i]=read();
	
	prepare(n<<1);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%Mod;
	ifac[n]=qpow(fac[n],Mod-2); for (int i=n;i;i--) ifac[i-1]=1LL*ifac[i]*i%Mod;
	
	for (int i=0;i<=n;i++){
		A[n-i]=1LL*w[i]*fac[i]%Mod;
		B[i]=ifac[i];
	}
	//for (int i=n+1;i<maxw;i++) A[i]=B[i]=0;
	ntt(A,1); ntt(B,1); for (int i=0;i<maxw;i++) A[i]=1LL*A[i]*B[i]%Mod; ntt(A,-1);
	for (int i=0;i<=n;i++) w[i]=1LL*ifac[i]*A[n-i]%Mod*imaxw[btw]%Mod*qpow(i+1,Mod-1-m%(Mod-1))%Mod;
	
	for (int i=0,k=1;i<=n;i++,k=-k){
		A[n-i]=1LL*w[i]*fac[i]%Mod;
		B[i]=upd(k*ifac[i]);
	}
	for (int i=n+1;i<maxw;i++) A[i]=B[i]=0;
	ntt(A,1); ntt(B,1); for (int i=0;i<maxw;i++) A[i]=1LL*A[i]*B[i]%Mod; ntt(A,-1);
	for (int i=0;i<=n;i++) w[i]=1LL*ifac[i]*A[n-i]%Mod*imaxw[btw]%Mod;
	
	for (int i=0;i<=n;i++) print(w[i]),putchar(' '); putchar('\n');
	return 0;
}