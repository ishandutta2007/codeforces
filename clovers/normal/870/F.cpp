#include<bits/stdc++.h>
using namespace std;
const int N=10000005;
#define int long long
int prime[N],bl[N],tot=0,phi[N],f[N],g[N];
void init(int n)
{
    for(int i=1;i<=n;i++) bl[i]=1;
    bl[1]=0; phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(bl[i]) prime[++tot]=i,phi[i]=i-1,f[i]++;
        for(int j=1;j<=tot;j++)
        {
            if(i*prime[j]>n) break;
            bl[i*prime[j]]=0;
            f[prime[j]]++;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            //cout<<prime[j]<<"PPP\n";
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
    //for(int i=1;i<=n;i++) cout<<f[i]<<endl;
    for(int i=2;i<=n;i++) g[i]=g[i-1]+f[i];
}

int ans1=0,ans2=0,ans3=0,rest=0,n;
void solve()
{
    for(int i=2;i<=n;i++) ans1=ans1+i-1-phi[i];
    for(int i=1;i<=tot;i++) 
    {
        int L=max(n/prime[i]+1,prime[i]+1);
        int R=n/2;
        if(L<=R) ans3=ans3+f[prime[i]]*(g[R]-g[L-1]);
        R=n; L=max(n/2+1,L);
        //cout<<prime[i]<<" "<<L<<" "<<R<<endl;
        rest=rest+f[prime[i]]*(g[R]-g[L-1]);
    }
    int sum=(n-1)*(n-2)/2;
    ans2=sum-(rest+ans1+ans3);
    //cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<rest<<endl;
    printf("%lld\n",ans1+ans2*2+ans3*3);
}

signed main()
{
    scanf("%lld",&n);
    init(n);
    solve();
}