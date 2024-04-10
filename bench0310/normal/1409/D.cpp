#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int sum(ll a)
{
    int res=0;
    while(a)
    {
        res+=(a%10);
        a/=10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        int s;
        cin >> n >> s;
        ll res=(1ll<<60);
        if(sum(n)<=s) res=0;
        else if(sum(n+1)<=s) res=1;
        ll p=1;
        ll a=0;
        ll z=n;
        while(z)
        {
            a+=(p*(z%10));
            p*=10;
            z/=10;
            if(sum(n+p-a)<=s) res=min(res,p-a);
        }
        cout << res << "\n";
    }
    return 0;
}