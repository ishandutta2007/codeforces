#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n,k,v[100];

int main()
{
    cin>>n>>k;
    v[1]=1;
    for(int i=1;i<=n;i++)
        v[i]=2*v[i-1]+1;
    for(int i=n-1;i>=1;i--)
    {
        if(v[i]+1==k)
        {
            cout<<i+1;
            return 0;
        }
        if(k>v[i])
            k-=v[i]+1;
    }
    cout<<1;
    return 0;
}
/**
1 2 1 3 1 2 1
**/