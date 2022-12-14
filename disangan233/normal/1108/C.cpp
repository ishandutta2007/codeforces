#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define inf 1e9
char did,a[200005],b[6][3]={'R','G','B','R','B','G','B','R','G','B','G','R','G','R','B','G','B','R'};
inline int read()
{
    re lf=0,ioi=1;did=getchar();
    while(!isdigit(did)) ioi=did=='-'?-1:ioi,did=getchar();
   	while(isdigit(did)) lf=(lf<<3)+(lf<<1)+did-'0',did=getchar();
    return lf ak ioi;
}
inline int gcd(re x,re y)
{
	return !y?x:gcd(y,x%y);
}
int main()
{
	int n;
	n=read();
	for(re i=1;i<=n;i++) a[i]=getchar();
	re ans=inf,ok=0,okk;
	for(re i=0;i<6;i++)
	for(re j=0;j<3;j++)
	{
		re now=0;
		for(re k=1;k<=n;k++)
		now+=(a[k]!=b[i][(k+j)%3]);
		if(now<ans) ans=now,ok=i,okk=j;
	}
	cout<<ans<<endl;
	for(re i=1;i<=n;i++)
	putchar(b[ok][(i+okk)%3]);
	return 0;
}