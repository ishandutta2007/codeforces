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
const int N=1e5+5;
ll n,m,a[N],b[N],f[N][2],mx[N][2];
int main()
{
	n=read();
	for(re i=1;i<=n;i++) a[i]=read();
	for(re i=1;i<=n;i++) b[i]=read();
	f[1][0]=mx[1][0]=a[1];
	f[1][1]=mx[1][1]=b[1];
	for(re i=2;i<=n;i++)
	{
		f[i][0]=max(mx[i-1][1],mx[i-2][0])+a[i];
		f[i][1]=max(mx[i-1][0],mx[i-2][1])+b[i];
		mx[i][0]=max(mx[i-1][0],f[i][0]);
		mx[i][1]=max(mx[i-1][1],f[i][1]);
	}
	cout<<max(mx[n][0],mx[n][1])<<endl;
}