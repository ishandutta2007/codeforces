#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll s,k;
ll fib[10000];
ll sum[10000];
ll p[10000];

ll ask(ll l,ll r)
{
   // cout<<l<<" "<<r<<"\n";
    if(l<0)
    {
        l=0;
    }
    if(l>r)
    {
        return 0;
    }
    if(l==0)
    {
        return p[r];
    }
    else
    {
        return p[r]-p[l-1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s>>k;
    p[0]=1;
    for(int i=1;i<=1000;i++)
    {
        p[i]=p[i-1]+ask(i-k,i-1);
    }
    int go=0;
    for(int i=0;i<=1000;i++)
    {
        if(ask(i,i)>s)
        {
            go=i-1;
            break;
        }
    }
    vector<ll>res;
    for(int i=go;i>=0;i--)
    {
        ll x=ask(i,i);
        if(s>=x)
        {
            s-=x;
            res.push_back(x);
        }
    }
    res.push_back(0);
    cout<<res.size()<<"\n";
    for(auto &x:res)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

**/