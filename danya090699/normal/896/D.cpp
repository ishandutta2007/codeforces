#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int mod, m, ef=1;
int f[sz][12], f2[sz], st[sz][12];
int po(int x, int y)
{
    int re=1%mod;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        x=(1ll*x*x)%mod;
        y>>=1;
    }
    return re;
}
int fc(int n, int k)
{
    int re=(1ll*f2[n]*po((1ll*f2[n-k]*f2[k])%mod, ef-1))%mod;
    for(int a=0; a<m; a++) re=(1ll*re*st[f[n][a]-f[n-k][a]-f[k][a]][a])%mod;
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, r;
    cin>>n>>mod>>l>>r;
    vector <int> de;
    int x=mod;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            while(x%a==0)
            {
                x/=a, ef*=a;
            }
            ef/=a, ef*=(a-1);
            de.push_back(a);
        }
    }
    if(x>1)
    {
        de.push_back(x), ef*=(x-1);
    }
    m=de.size();
    for(int a=0; a<m; a++) st[0][a]=1%mod;
    f2[0]=1;
    for(int a=1; a<=n; a++)
    {
        int x=a;
        for(int b=0; b<m; b++)
        {
            while(x%de[b]==0)
            {
                f[a][b]++, x/=de[b];
            }
            f[a][b]+=f[a-1][b];
            st[a][b]=(1ll*st[a-1][b]*de[b])%mod;
        }
        f2[a]=(1ll*f2[a-1]*x)%mod;
    }
    int an=0;
    for(int a=0; a<=n; a++)
    {
        int lg=l, rg=r;
        if(l%2!=a%2) lg++;
        if(r%2!=a%2) rg--;
        rg=min(rg, a);
        if(lg<=rg)
        {
            int cu=fc(a, (a-lg)/2+lg);
            if(rg+2<=a) cu-=fc(a, (a-rg-2)/2+(rg+2));
            if(cu<0) cu+=mod;
            cu=(1ll*cu*fc(n, a))%mod;
            an=(0ll+an+cu)%mod;
        }
    }
    cout<<an;
}