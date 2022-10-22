#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,q,a[MAXN],ans[MAXN];
int check()
{
	int tmp=q;
	for(int i=1;i<=n;++i)
	{
		if(tmp<=0) return 0;
		if(tmp<a[i]) --tmp;
	}
	return 1;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),q=read();
		for(int i=1;i<=n;++i) a[i]=read();
		if(check())
		{
			for(int i=1;i<=n;++i) putchar('1');
			putchar('\n');
			continue;
		}
		for(int i=n,val=0;i>=1;--i)
		{
			if(val<a[i] && val==q) ans[i]=0;
			else
			{
				ans[i]=1;
				if(val<a[i]) ++val;
			}
		}
		for(int i=1;i<=n;++i) printf("%d",ans[i]);
		putchar('\n');
	}
	return 0;
}
//tetu no isi to hagane no tuyosa