#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n,T;
int t[20],g[20];
long long f[250][(1<<15)+10][3];
int main()
{
    cin>>n>>T;
    for(int i=0;i<n;i++)scanf("%d%d",&t[i],&g[i]);
    for(int i=0;i<n;i++)if (t[i]<=T)f[t[i]][1<<i][g[i]]=1;
    int full=(1<<n)-1;
    rep(i,T)
    {
        for(int j=0;j<=full;j++)
            for(int k=0;k<n;k++)
            if (((j&(1<<k))==0)&&(i+t[k]<=T))
                rep(p,3)
                {
                    if (p==g[k])continue;
                    (f[i+t[k]][j|(1<<k)][g[k]]+=f[i][j][p])%=1000000007;
                }
    }
    long long ans=0;
    rep(i,full)rep(j,3)(ans+=f[T][i][j])%=1000000007;
    cout<<ans<<endl;
}