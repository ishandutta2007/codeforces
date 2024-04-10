#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10, mod=998244353;
int tr[sz][sz], f[sz];
int main()
{
    for(int a=0; a<sz; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;
    }
    f[0]=1;
    for(int a=1; a<sz; a++) f[a]=(1ll*f[a-1]*a)%mod;
    //freopen("input.txt", "r", stdin);
    int x, y, z, q1=0, q2=0, q3=0;
    cin>>x>>y>>z;
    for(int a=0; a<=min(x, y); a++)
    {
        int q=(1ll*tr[x][a]*tr[y][a])%mod;
        q=(1ll*q*f[a])%mod;
        q1=(q1+q)%mod;
    }
    for(int a=0; a<=min(x, z); a++)
    {
        int q=(1ll*tr[x][a]*tr[z][a])%mod;
        q=(1ll*q*f[a])%mod;
        q2=(q2+q)%mod;
    }
    for(int a=0; a<=min(y, z); a++)
    {
        int q=(1ll*tr[y][a]*tr[z][a])%mod;
        q=(1ll*q*f[a])%mod;
        q3=(q3+q)%mod;
    }
    int an=(1ll*q1*q2)%mod;
    an=(1ll*an*q3)%mod;
    cout<<an;
}