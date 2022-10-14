#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int now=x; y; y>>=1,now=now*now%p) if(y&1) res=res*now%p;
	return res;
}
int a[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	int ans=0;
	for(int i=1; i<=n; i++) ans+=(qp(2,n-i+1)+(n-i)*qp(2,n-i))%p*a[i]%p,ans%=p;
	printf("%lld\n",ans*(998244354/2)%p);
	return 0;
}