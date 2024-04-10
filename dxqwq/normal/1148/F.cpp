#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0;
    scanf("%lld",&x);
    return x;
}
int n=read(),sum=0;
int highest(int x)
{
    for(int i=1ll<<62,j=62; i; i>>=1,--j) if(i&x) return j;
    assert(0);
    return 0;
}
int count(int x)
{
    int res=0;
    for(int i=1ll<<62; i; i>>=1) if(i&x) ++res;
    return res;
}
int a[300003],b[300003];
vector<int> v[103];
void solve1()
{
    for(int i=1; i<=n; i++) v[highest(b[i])].push_back(i);
    int ans=0;
    for(int i=0; i<=62; i++)
    {
        int to1=0,to0=0,fyy=ans+(1ll<<i);
        for(int x:v[i]) 
        {
            if(count(b[x]&fyy)&1) to1-=a[x]; else to1+=a[x];
        }
        if(to1<0) ans=fyy; 
    }
    printf("%lld\n",ans);
}
void solve2()
{
    for(int i=1; i<=n; i++) a[i]=-a[i];
    solve1();
}
signed main() 
{
	for(int i=1; i<=n; i++) a[i]=read(),b[i]=read(),sum+=a[i];
	if(sum>0) solve1();
    else solve2();
	return 0;
}