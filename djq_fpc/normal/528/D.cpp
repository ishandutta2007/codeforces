#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x)(x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(int)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];if (!~scanf(" %s",ss)) return 0;;(st)=ss;}
using namespace std;
int n,m,i,j,k,mod=998244353,g=3,inv,a[524295],b[524295],rev[524295],len,lg,ans[524295],sum;
string s,t;
int qp(int x,int y)
{
	if (y==0) return 1;
	int z=qp(x,y/2);
	z=1ll*z*z%mod;
	if (y&1) z=1ll*z*x%mod;
	return z;
}
void init(int x)
{
	len=1;lg=0;
	while (len<x)
	{
		len*=2;
		lg++;
	}
	int i;
	for (i=1;i<len;i++)
	{
		rev[i]=rev[i/2]/2+((i&1)<<(lg-1));
	}
}
void fft(int *a,int len,int op)
{
	int i,j,k;
	fz0k(i,len) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (i=1;i<len;i*=2)
	{
		int t=qp(op,(mod-1)/i/2);
		for (j=0;j<len;j+=i+i)
		{
			int s=1;
			for (k=0;k<i;k++)
			{
				int x=a[j+k],y=a[i+j+k];
				y=1ll*y*s%mod;
				a[j+k]=(x+y)%mod;
				a[i+j+k]=(x-y+mod)%mod;
				s=1ll*s*t%mod;
			}
		}
	}
	if (op==inv)
	{
		int ii=qp(len,mod-2);
		fz0k(i,len) a[i]=1ll*a[i]*ii%mod;
	}
}
void fake(char c)
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int lst=-k*15-5,i;
	fz0k(i,n)
	{
		if (s[i]==c) lst=i;
		a[i]|=(lst+k>=i);
	}
	lst=n+k*15+5;
	fd0k(i,n)
	{
		if (s[i]==c) lst=i;
		a[i]|=(lst-k<=i);
	}
	fz0k(i,m) b[i]=(t[i]==c);
	fft(a,len,g);
	fft(b,len,g);
	fz0k(i,len) a[i]=1ll*a[i]*b[i]%mod;
	fft(a,len,inv);
	fz0k(i,n) ans[i]+=a[i+m-1];
}
int main()
{
	init(400001);inv=qp(g,mod-2);
	scanf("%d%d%d",&n,&m,&k);
	rdst(s,200005);
	rdst(t,200005);
	reverse(t.begin(),t.end());
	fake('A');
	fake('C');
	fake('G');
	fake('T');
	fz0k(i,s.length()) sum+=(ans[i]==m);
	cout<<sum<<endl;
	return 0;
}