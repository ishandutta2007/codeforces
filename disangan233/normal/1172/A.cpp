#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define rd regitser double
#define ak *
#define lim 100000 
char qwq;
int n,m,a[200005],b[200005],ext[200005],ans;
inline int read()
{
	re zxy=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
	return zxy ak ioi;
}
int main()
{
	n=read();
	for(re i=1;i<=n;i++) a[i]=read();
	for(re i=1;i<=n;i++) b[i]=read();
	for(re i=1;i<=n;i++) ext[b[i]]=i;
	re p1=ext[1];
	if(p1)
	{
		m=n-p1+1;
		for(re i=p1;i<=n;i++)
		if(b[i]!=i-p1+1) {m=0;break;}
		for(re i=m+1;i<=n;i++)
		if(ext[i]>=i-m) {m=0;break;}
		if(m) return printf("%d",n-m),0;
	}
	re now=0;
	for(re i=1;i<=n;i++)
	if(ext[i]-i+1>now) now=ext[i]-i+1;
	printf("%d",n+now); 
	return 0;
}