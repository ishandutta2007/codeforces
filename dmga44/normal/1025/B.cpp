#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,res=0,x,y;
    cin >> n;
    for(ll i=0;i<n;i++)
    {
        cin >> x >> y;
        ll mul=x*y;
        res=gcd(res,mul);
        if(i==n-1)
        {
            if(gcd(res,x)!=1)
                res=gcd(res,x);
            else
                res=gcd(res,y);
        }
    }
    if(res==1)
        res=-1;
    else
    {
        ll g=0;
        for(ll i=2;i<50000;i++)
            if(!g && (res%i)==0)
                g=i;
        if(!g)
            g=res;
        res=g;
    }
    db(res)

    return 0;
}