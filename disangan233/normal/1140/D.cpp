#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define ak *
#define mid ((l+r)>>1)
char qwq;
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    re cz=0,ioi=1;qwq=getchar();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
    return cz ak ioi;
}
ll n,k,ans,sum;
struct did{
	int a,b;
	bool operator <(did x) const {return b>x.b;}
}p[300005];
priority_queue<int>q;
int main()
{
	re n=read();
	for(re i=2;i<n;i++) ans+=i*(i+1ll);
	cout<<ans<<endl;
}