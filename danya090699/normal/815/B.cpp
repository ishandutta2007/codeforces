#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x, mod=1e9+7;
int po(int x, int y)
{
    if(y==0) return 1;
    else
    {
        if(y%2==0)
        {
            int cu=po(x, y/2);
            return (cu*cu)%mod;
        }
        else return (po(x, y-1)*x)%mod;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    if(n%4==0) x=n/2-1;
    if(n%4==1) x=(n+1)/2-1;
    if(n%4==2) x=n/2-1;
    if(n%4==3) x=(n-1)/2-1;
    int tr[x+1], f[x+1];
    f[0]=1;
    for(int a=1; a<=x; a++) f[a]=(f[a-1]*a)%mod;
    for(int a=0; a<=x; a++)
    {
        tr[a]=(f[x]*po((f[a]*f[x-a])%mod, mod-2))%mod;
    }
    int q[n];
    if(n%4==0)
    {
        for(int a=0; a<n; a++)
        {
            if(a%2==0) q[a]=tr[a/2];
            else q[a]=-tr[a/2];
            if(q[a]<0) q[a]+=mod;
        }
    }
    if(n%4==1)
    {
        for(int a=0; a<n; a++)
        {
            if(a%2==1) q[a]=0;
            else q[a]=tr[a/2];
        }
    }
    if(n%4==2)
    {
        for(int a=0; a<n; a++) q[a]=tr[a/2];
    }
    if(n%4==3)
    {
        int q2[n-1];
        for(int a=0; a<n-1; a++) q2[a]=tr[a/2];
        q[0]=1, q[n-1]=mod-1;
        for(int a=1; a<n-1; a++)
        {
            if(a%2==1) q[a]=(q2[a-1]+q2[a])%mod;
            else q[a]=q2[a]-q2[a-1];
            if(q[a]<0) q[a]+=mod;
        }
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        int cu;
        cin>>cu;
        an=(an+cu*q[a])%mod;
    }
    cout<<an;
}