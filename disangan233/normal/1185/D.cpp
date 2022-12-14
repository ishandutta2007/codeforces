#include<bits/stdc++.h>
using namespace std;
#define in inline
#define db double
#define ll long long
#define ull unsigned ll
#define re register int
#define ak *
in char getch()
{
	char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getchar()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=2e5+5,mod=1e9+7;
int n,m,ans;
struct did{
	int a,b;
	bool operator< (did x) const {return a<x.a;} 
}a[N];
in void pre()
{
	re op=1;
	for(re i=3;i<n;i++)
	if(a[i+1].a-a[i].a!=a[3].a-a[2].a) 
	{
		op=0;
		break;
	}
	if(op) cout<<a[1].b<<endl,exit(0);
	op=1;
	for(re i=2;i<n-1;i++)
	if(a[i+1].a-a[i].a!=a[2].a-a[1].a) 
	{
		op=0;
		break;
	}
	if(op) cout<<a[n].b<<endl,exit(0);
}
int main()
{
	n=read();
	if(n<=3) return puts("1"),0;
	for(re i=1;i<=n;i++) a[i]=(did){read(),i};
	sort(a+1,a+n+1);pre();
	if((a[n].a-a[1].a)%(n-2)) return puts("-1"),0;
	re hav=1;
	for(re i=1;i<n;i++)
	if(a[i+1].a-a[i].a!=(a[n].a-a[1].a)/(n-2))	
	{
		if(i==n-1||a[i+2].a-a[i].a!=(a[n].a-a[1].a)/(n-2)||ans)
		{
			hav=0;
			break;
		}
		else ans=a[i+1].b,i++;
	} 
	if(hav) cout<<ans;
	else puts("-1");
	return 0;
}