#include<bits/stdc++.h>
using namespace std;
#define re register int
#define db double
#define ll long long
#define in inline
#define ak *
in char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getch()
char qwq;
in ll read()
{
    ll cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
const int M=1e5+5;
ll n,m,x,y,z,a[M];
int main()
{
	x=read(),y=read(),z=read();
	cout<<(ll)((x+y)/z)<<" ";
	ll a=x%z,b=y%z;
	if((ll)((x+y)/z)==(ll)(x/z)+(ll)(y/z)) puts("0");
	else if(a==0||b==0)puts("0");
	else cout<<z-max(a,b);
	return 0;
}