#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7, sz=2e3+10;
int k, pa, pb, va, vb, dp[sz][sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int cou(int i, int j)
{
    if(dp[i][j]==-1)
    {
        if(j>=k) dp[i][j]=j;
        else
        {
            if(i+j>=k) dp[i][j]=(i+j+1ll*pa*po(pb, mod-2))%mod;
            else
            {
                dp[i][j]=(1ll*cou(i+1, j)*va+1ll*cou(i, i+j)*vb)%mod;
            }
        }
    }
    return dp[i][j];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>k>>pa>>pb;
    va=(1ll*pa*po(pa+pb, mod-2))%mod;
    vb=(1ll*pb*po(pa+pb, mod-2))%mod;
    for(int a=0; a<sz; a++) for(int b=0; b<sz; b++) dp[a][b]=-1;
    cout<<cou(1, 0);
}