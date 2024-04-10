#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 300000
using namespace std;
int n,q,mod,a[N+5],b[N+5],f[N+5],cnt;
char opt;
inline void add(int &x,int val)
{
    cnt-=!x;
    x=(x+val)%mod;
    cnt+=!x;
}
int main()
{
    scanf("%d %d %d",&n,&q,&mod);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    for(int i=1;i<=n;++i) scanf("%d",b+i),a[i]=(a[i]-b[i]+mod)%mod;
    for(int i=n;i>=2;--i) a[i]=(a[i]-a[i-1]+mod)%mod,a[i]=(a[i]-a[i-2]+mod)%mod;
    for(int i=1;i<=n;++i) cnt+=!a[i];
    f[1]=1;for(int i=2;i<=n;++i) f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=1,l,r;i<=q;++i)
    {
        for(opt=getchar();opt!='A' && opt!='B';opt=getchar());
        scanf("%d %d",&l,&r);
        if(opt=='A')
        {
            add(a[l],1);
            if(r+1<=n) add(a[r+1],mod-f[r-l+1]),add(a[r+1],mod-f[r-l]);
            if(r+2<=n) add(a[r+2],mod-f[r-l+1]);
        }
        else
        {
            add(a[l],mod-1);
            if(r+1<=n) add(a[r+1],f[r-l+1]),add(a[r+1],f[r-l]);
            if(r+2<=n) add(a[r+2],f[r-l+1]);
        }
        cnt==n?puts("YES"):puts("NO");
    }
    return 0;
}