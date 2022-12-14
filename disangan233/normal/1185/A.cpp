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
#define gc() getch()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=1e5+5;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b) swap(a,b); if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	re ans=0;
	if(c-b<d) ans+=d-(c-b);
	if(b-a<d) ans+=d-(b-a);
	cout<<ans<<endl;
}