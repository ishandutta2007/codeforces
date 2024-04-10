#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD=1000000007;

ll expow(ll a,int b)
{
    ll ans=1;
    while(b)
    {
        if(b%2)
            ans=ans*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return ans;
}

map<int,int>mp;

ll slove(int n)
{
    if(n==1)
        return 1;
    int val=mp[n];
    if(val)
        return val;
    ll ans=expow(2,n-1);
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans-=slove(n/i);
            if(ans<0)
                ans+=MOD;
            if(n/i==i) break;
            ans-=slove(i);
            if(ans<0)
                ans+=MOD;
        }
    }
    ans--;
    mp[n]=ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(b%a==0)
    {
        cout<<slove(b/a)<<"\n";
    }
    else
    {
        cout<<"0\n";
    }
    return 0;
}
/**


**/