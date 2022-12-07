#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
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
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, cu=1, an=0;
    cin>>n>>m;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(x!=0 and ar[a]!=0)
        {
            if(x<ar[a])
            {
                an=(an+cu)%mod, cu=0;
            }
            if(x>ar[a]) cu=0;
        }
        else if(x==0 and ar[a]>0)
        {
            cu=(1ll*cu*po(m, mod-2))%mod;
            an=(an+1ll*cu*(ar[a]-1))%mod;
        }
        else if(x>0 and ar[a]==0)
        {
            cu=(1ll*cu*po(m, mod-2))%mod;
            an=(an+1ll*cu*(m-x))%mod;
        }
        else
        {
            an=(an+1ll*cu*((1ll*(m-1)*po((2*m)%mod, mod-2))%mod))%mod;
            cu=(1ll*cu*po(m, mod-2))%mod;
        }
    }
    cout<<an;
}