#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}
typedef long long ll;
const int Mod=998244353;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}

int n,m,h[200010];

int btw,maxw,id[524288];
int A[524288],B[524288];
void ntt(int *w,bool tp)
{
	for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
	for (int midlen=1,len=2;midlen<maxw;midlen=len,len<<=1)
		for (int l=0,Wn=qpow(3,tp?(Mod-1)/len:Mod-1-(Mod-1)/len);l<maxw;l+=len)
			for (int u=l,ww=1;u-l<midlen;u++,ww=1LL*ww*Wn%Mod)
			{
				int x=w[u],y=1LL*ww*w[u+midlen]%Mod;
				w[u]=(x+y)%Mod; w[u+midlen]=(x-y)%Mod;
			}
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) h[i]=read();
	int Atot=0,Btot=0;
	for (int i=1;i<=n;i++) Atot+=(h[i]==h[i%n+1]),Btot+=(h[i]!=h[i%n+1]);
	
	maxw=524288,btw=19;
	for (int i=1;i<maxw;i++)
	{
		id[i]=id[i>>1]>>1;
		if (i&1) id[i]|=(1<<btw-1);
	}
	A[1]=m%Mod,B[0]=B[2]=1,B[1]=(m-2)%Mod;
	ntt(A,1); ntt(B,1);
	for (int i=0;i<maxw;i++) A[i]=1LL*qpow(A[i],Atot)*qpow(B[i],Btot)%Mod;
	ntt(A,0);
	int imaxw=qpow(maxw,Mod-2);
	int ans=0;
	for (int i=n+1;i<maxw;i++)
	{
		ans=(ans+1LL*A[i]*imaxw)%Mod;
	}
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}