#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,q,st[MAXN][20],suf[MAXN],c[MAXN],Log2[MAXN];
int calc(int l,int r)
{
	if(l>r) return 0;
	int LOG=Log2[r-l+1];
	int bck=st[l][LOG]^calc(l+(1<<LOG),r);
	if((suf[l+(1<<LOG)]-suf[r+1])&1) bck^=(1<<LOG);
	return bck;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i) c[read()]^=1;
	for(int i=2;i<=m;++i) Log2[i]=Log2[i>>1]+1;
	for(int i=m;i>=1;--i)
	{
		suf[i]=suf[i+1]+c[i];
		int LOG=Log2[m-i+1];
		for(int j=1;j<=LOG;++j)
		{
			st[i][j]=st[i][j-1]^st[i+(1<<j-1)][j-1];
			if((suf[i+(1<<j-1)]-suf[i+(1<<j)])&1) st[i][j]^=(1<<j-1);
		}
		//cout<<i<<" "<<LOG<<" "<<st[i][LOG]<<endl;
	}
	q=read();
	while(q--)
	{
		int l=read(),r=read();
		if(calc(l,r)) putchar('A');
		else putchar('B');
	}
	putchar('\n');
	return 0;
}