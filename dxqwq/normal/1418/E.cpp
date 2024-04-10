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
inline int qp(int x,int y)
{
	int res=1;
	for(int now=x; y; y>>=1,now=now*now%p) if(y&1) res=res*now%p;
	return res;
}
int a[1000003],pre[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) pre[i]=(a[i]+pre[i-1])%p; 
	for(;m--;)
	{
		int x=read(),y=read(),z=lower_bound(a+1,a+n+1,y)-a,w=n-z+1;
		if(x>w) puts("0"); 
		else printf("%lld\n",(pre[z-1]*(w-x+1)%p*qp(w+1,p-2)%p+(pre[n]+p-pre[z-1])%p*(w-x)%p*qp(w,p-2)%p)%p);
	}
	return 0;
}