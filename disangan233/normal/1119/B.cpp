// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define re register int
#define un unsigned
#define ll un long long
#define ak *
char qwq;
inline int read()
{
    re cz=0,ioi=1;qwq=getchar();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
    return cz ak ioi;
}
inline ll qpow(ll x,ll y,ll p,ll z=1)
{
 	for(;y;y>>=1,x=(x*x)%p) z=(y&1)?(x*z)%p:z;
    return z;
}
int n,h,a[5000005],l,r,ans;
int main()
{
    priority_queue<int>q,qq;
    n=read(),h=read();
    for(re i=1;i<=n;i++) a[i]=read();
    for(re i=1;i<=n;i++)
    {
        q.push(a[i]);qq=q;
        re now=0;
        while(!qq.empty())
        {
            now+=qq.top();qq.pop();
            if(qq.empty()) break;
            qq.pop();
        }
        if(now>h) return cout<<i-1<<endl,0;
    }
    cout<<n;
}