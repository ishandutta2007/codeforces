#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s*f;
}
const long long p=1e9+7;
long long qp(long long x,int y)
{
    long long res=1;
    for(long long now=x; y; y>>=1,now=now*now%p) if(y&1) res=res*now%p;
    return res;
}
unordered_map<int,long long> mp; 
//f(x)xgcd1
//g(x)f(x)gcd=12^(x-1)
//f(x)g(x)gcd1f(x')
//
long long f(int x)
{
    if(x<=2) return 1;
    if(mp[x]) return mp[x];
    long long res=qp(2,x-1)-1;
    for(int i=2; i*i<=x; i++) if(x%i==0)
    {
        if(i*i==x) res+=p-f(i),res%=p;
        else res+=p-f(i),res+=p-f(x/i),res%=p;
    }
    return mp[x]=res;
}
int main()
{
    int n=read(),m=read();
    if(m%n) puts("0"); else printf("%lld\n",f(m/n));
    return 0;
}