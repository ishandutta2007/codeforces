#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
#define db double
#define in inline
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getch()
char qwq;
inline int read()
{
    re cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
const int N=2e5+5;
int a[N],n;
int main()
{
	n=read();re mx=0,id=0;
	for(re i=1;i<=n;i++) a[i]=read();
	for(re i=1;i<=n;i++)
	{
		if(a[i]>mx) mx=a[i],id=i;
	}
	for(re i=1;i<id;i++)
	if(a[i]>=a[i+1]) return puts("NO"),0;
	for(re i=id+1;i<=n;i++)
	if(a[i-1]<=a[i]) return puts("NO"),0;
	puts("YES");
}