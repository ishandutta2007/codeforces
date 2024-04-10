#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=1e9+7;
int q[sz], f[sz], st2[sz];
int main()
{
    int n;
    cin>>n;
    for(int a=0; a<sz; a++) q[a]=0;
    st2[0]=1;
    for(int a=1; a<sz; a++) st2[a]=(st2[a-1]*2)%mod;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        q[x]++;
    }
    for(int a=1; a<sz; a++)
    {
        f[a]=0;
        for(int b=a; b<sz; b+=a) f[a]+=q[b];
    }
    for(int a=sz-1; a>0; a--)
    {
        f[a]=st2[f[a]]-1;
        for(int b=a+a; b<sz; b+=a)
        {
            f[a]-=f[b];
            if(f[a]<0) f[a]+=mod;
        }
    }
    cout<<f[1];
}