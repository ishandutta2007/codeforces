#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
int n,m;
int main()
{
	n=read();m=read();
	for(re i=1;(ll)i*(i-1)/2<=n+m+10;i++)
	{
		re sum=(ll)i*(i+1)/2;
		if(sum-(n-i)==m) return cout<<n-i<<endl,0;
	}
}