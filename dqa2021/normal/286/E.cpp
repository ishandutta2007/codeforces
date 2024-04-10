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
void print(int x)
{
	if (x>9) print(x/10); putchar(x%10+48);
}
const int Mod=998244353;
typedef long long ll;

int n,m;
bool c[1000010];
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=(ll)x*x%Mod)
		if (y&1) res=(ll)res*x%Mod;
	return res;
}
int w[2100010];
int id[2100010],maxw=1,btw;
void NTT(int tp)
{
	for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
	for (int midlen=1;midlen<maxw;midlen<<=1)
	{
		int len=midlen<<1;
		int Wn=(tp==1?qpow(3,(Mod-1)/len):qpow(3,Mod-1-(Mod-1)/len));
		for (int l=0;l<maxw;l+=len)
		{
			int ww=1;
			for (int u=l;u-l<midlen;u++,ww=(ll)ww*Wn%Mod)
			{
				int tmp1=w[u],tmp2=(ll)ww*w[u+midlen]%Mod;
				w[u]=(tmp1+tmp2)%Mod; w[u+midlen]=(tmp1-tmp2)%Mod;  //negative
			}
		}
	}
}
int ans[1000010];
int main()
{
	n=read();m=read(); w[0]=1;
	for (int i=1,x;i<=n;i++)
	{
		x=read(); c[x]=true; w[x]=1;
	}
	while (maxw<=(m<<1)) maxw<<=1,btw++;
	for (int i=1;i<maxw;i++)
	{
		id[i]=id[i>>1]>>1;
		if (i&1) id[i]|=(1<<btw-1);
	}
	NTT(1);
	for (int i=0;i<maxw;i++) w[i]=(ll)w[i]*w[i]%Mod;
	NTT(-1);
	int tmp=qpow(maxw,Mod-2);
	for (int i=1;i<=m;i++)
	{
		if (w[i]<0) w[i]+=Mod;
		w[i]=(ll)w[i]*tmp%Mod;
		if (!c[i]&&w[i]) return puts("NO"),0;
		if (w[i]==2) ans[++*ans]=i;
	}
	printf("YES\n%d\n",(*ans));
	for (int i=1;i<=(*ans);i++) print(ans[i]),putchar(' '); putchar('\n');
	return 0;
}