#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=1e6+10;
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
int rev(int x){return po(x, mod-2);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int bad=po((po(3, n)-3+mod)%mod, n);

    int muq=po(po(3, n), n);
    int li1=po((po(3, n)-2+mod)%mod, n), li0=po((po(3, n)-3+mod)%mod, n);
    muq=(muq-3ll*li1+2ll*li0+3ll*mod)%mod;
    bad=(bad-muq+mod)%mod;

    int q=0, c=1;
    for(int a=1; a<n; a++)
    {
        c=(1ll*c*(n-a+1))%mod;
        c=(1ll*c*rev(a))%mod;

        int cu=po((po(3, n-a)-1+mod)%mod, n);

        int muq=po(po(3, n), n-a);
        int x=po((po(3, n)-2+mod)%mod, n-a);
        muq=(muq-x+mod)%mod;

        cu=(cu-muq+mod)%mod;
        cu=(1ll*c*cu)%mod;

        if(a%2) q=(q+cu)%mod;
        else q=(q-cu+mod)%mod;
    }

    bad=(bad-3ll*q+3ll*mod)%mod;

    int an=po(po(3, n), n);
    an=(an-bad+mod)%mod;

    cout<<an;
}