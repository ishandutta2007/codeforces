#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define inf 1e9
char did;
int a[100005],b[129];
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
	int n,maxn=0,js=0,aa,ans[3];
	n=read();
	for(re i=1;i<=n;i++) b[i]=read(),a[b[i]]++;
	sort(b+1,b+n+1);
	for(re i=n;i>=1;i--)
	{
		re bj=1;
		for(re j=1;j<=b[i];j++)
		if(b[i]%j==0)
		if(a[b[i]/j]==0) 
		{
			bj=0;break;
		}
		if(bj)
		{
			js++;cout<<b[i]<<" ";
			for(re j=1;j<=b[i];j++)
			if(b[i]%j==0)
			a[b[i]/j]--;
		}
		if(js==2) return 0;
	}
	return 0;
}