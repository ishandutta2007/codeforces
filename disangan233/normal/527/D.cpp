#include<bits/stdc++.h>
using namespace std;
#define re register int
#define inf (1<<30)-1
int n,ans=0;
char didd;
struct did
{
    int l,r;
    bool operator <(did a) const
    {
        if(r!=a.r) return r<a.r;
        else return l<a.l;
    }
}t[2000005];
inline int read()
{
	re luoyang=0,yz=1;
	didd=getchar();
	while(!isdigit(didd)) yz=didd=='-'?-1:yz,didd=getchar();
	while(isdigit(didd)) luoyang=(luoyang<<1)+(luoyang<<3)+didd-'0',didd=getchar();
	return luoyang*yz;
}
int main()
{
    n=read();
    for(re i=1;i<=n;i++)
    {
        re a=read(),b=read();
        t[i].l=a-b;t[i].r=a+b; 
    }
    sort(t+1,t+n+1);
    re r=-inf;
    for(re i=1;i<=n;i++)
    if(t[i].l>=r)
    {
        ans++;
        r=t[i].r;
    } 
    cout<<ans<<endl;
}