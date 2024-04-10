#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
char s[1001];
int ca,cb,cc,na,nb,nc,qa,qb,qc,m,len,ans;
int check(int v)
{
	int a=v*na-ca,b=v*nb-cb,c=v*nc-cc;
	int cost=max(a,0ll)*qa+max(b,0ll)*qb+max(c,0ll)*qc;
	return cost<=m;
}
signed main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;++i)
	{
		if(s[i]=='B') ++na;
		if(s[i]=='S') ++nb;
		if(s[i]=='C') ++nc;
	}
	ca=read(),cb=read(),cc=read();
	qa=read(),qb=read(),qc=read();
	m=read();
	int l=1,r=m+1000;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}