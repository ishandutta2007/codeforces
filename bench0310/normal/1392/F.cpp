#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sm(ll a,ll b)
{
    return ((b-a+1)*(a+b))/2;
}

ll s(ll x,ll num)
{
    return sm(x-num+1,x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> h(n+1,0);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> h[i];
        sum+=h[i];
    }
    ll l=0,r=2000000000000;
    while(l<r-1)
    {
        ll m=(l+r)/2;
        if(s(m-1,n-1)+m<=sum) l=m;
        else r=m;
    }
    vector<ll> res(n+1,0);
    ll now=l;
    for(int i=n;i>=1;i--)
    {
        if(s(now-1,i-1)+now>sum) now--;
        res[i]=now;
        sum-=now;
    }
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}