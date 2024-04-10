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
const int N=1e3+5;
int n,m,a[N],b[N],k,ans;
int main()
{
	n=read();m=read();k=ceil(1.0*n/2);
	for(re i=1;i<=n;i++) b[a[i]=read()]++;
	for(re i=1;i<=m;i++)
	{
		while(b[i]>=2&&k) ans+=2,b[i]-=2,k--;
		if(k==0) break;
	}
	if(k==0) return cout<<ans<<endl,0;
	for(re i=1;i<=m;i++)
	{
		if(b[i]) ans++,k--;
		if(k==0) break;
	}
	cout<<ans<<endl;
}