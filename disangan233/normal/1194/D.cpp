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
const int N=105,M=1e6+5;
int n,m;
int main()
{
	re t=read();
	while(t--)
	{
		n=read();m=read();
		if(!n) puts("Bob");
		else if(m%3) puts(n%3?"Alice":"Bob");
		else
		{
			re k=m/3,md=n%(m+1);
			puts(md%3==0&&md!=m?"Bob":"Alice");
		}
	}
}