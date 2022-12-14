#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define ak *
char qwq;
ll n,k,p[200005],c[200005],ans=1e18,cnt;
inline ll read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
inline void pre()
{
    cnt=0;
    for(re i=2;i*i<=k;++i)
    if(k%i==0)
	{
        p[++cnt]=i;c[cnt]=0;
        while(k%i==0) c[cnt]++,k/=i;
    }
    if(k>1) p[++cnt]=k,c[cnt]=1;
}
int main()
{
    n=read();k=read();
    pre();
    for(re i=1;i<=cnt;++i)
	{
        re t=0,x=n;
        while(x) t+=x/=p[i];
        t/=c[i];
        if(t<ans) ans=t;
    }
    printf("%lld\n",ans);
    return 0;
}