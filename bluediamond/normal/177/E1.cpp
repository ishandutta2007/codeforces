#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e4+5;
int n;
ll d;
ll a[N],b[N];

ll cnt(ll x)
{
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll sus=a[i]*x;
        ll jos=b[i];
        ans+=sus/jos+1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  ///  cout<<"\n\n";
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    ll r1=0,pas=(1<<30);
    ll r2=0;
    while(pas)
    {
        if(cnt(r1+pas)<d)
            r1+=pas;
        if(cnt(r2+pas)<=d)
            r2+=pas;
        pas/=2;
    }
    cout<<r2-r1<<"\n";
    return 0;
}
/**

**/