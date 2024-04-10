#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,i,sol[25],x;
int main()
{
    cin>>n>>k;
    i=2;
    if(k==1)
    {
        if(n==1)
            cout<<-1;
        else
            cout<<n;
        return 0;
    }
    while(i*i<=n)
    {
        while(n%i==0)
        {
            n/=i;
            x++;
            sol[x]=i;
            if(x==k-1)
            {
                if(n==1)
                {
                    cout<<-1;
                    return 0;
                }
                for(int i=1;i<=k-1;i++)
                    cout<<sol[i]<<" ";
                cout<<n;
                return 0;
            }
        }
        i++;
    }
    if(n!=1)
    {
        sol[++x]=n;
        if(x==k)
        {
            for(int i=1;i<=k;i++)
                cout<<sol[i]<<" ";
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
/**
**/