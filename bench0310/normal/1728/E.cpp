#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll g=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll res=0;
    vector<int> d(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        res+=b;
        d[i]=(a-b);
    }
    ranges::sort(d,greater<>());
    int pos=n+1;
    for(int i=n;i>=1;i--) if(d[i-1]<0) pos=i;
    vector<ll> opt(n+1,0);
    opt[0]=res;
    for(int i=1;i<=n;i++) opt[i]=opt[i-1]+d[i-1];
    int m;
    cin >> m;
    while(m--)
    {
        ll x,y;
        cin >> x >> y;
        ll a,b;
        ll g=exgcd(x,y,a,b);
        if(n%g)
        {
            cout << "-1\n";
            continue;
        }
        a*=(n/g);
        ll s=(y/g);
        a=((a%s)+s)%s;
        if(a*x>n)
        {
            cout << "-1\n";
            continue;
        }
        ll now=opt[a*x];
        if(a*x<pos)
        {
            ll k=(pos-a*x-1)/(s*x);
            now=max(now,opt[(a+k*s)*x]);
            if((a+(k+1)*s)*x<=n) now=max(now,opt[(a+(k+1)*s)*x]);
        }
        cout << now << "\n";
    }
    return 0;
}