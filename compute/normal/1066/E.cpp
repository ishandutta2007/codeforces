#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=2e5+7;
long long fac[maxn];
int pre[maxn];
void db()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*2%mod;
}
int main()
{
    db();
    int n,m;
    scanf("%d%d",&n,&m);
    string a,b;
    cin>>a>>b;
    pre[m]=0;
    for(int i=0;i<=m;i++)
    {
        int now=m-i-1;
        pre[now]=pre[now+1];
        if(b[i]=='1') pre[now]++;
    }
    long long ans=0;
    for(int i=n-1;i>=0;i--)
    {
        int now=n-i-1;
        if(a[i]=='1')
        {
            ans=(ans+fac[now]*pre[now])%mod;
        }
    }
    cout<<ans<<endl;

}