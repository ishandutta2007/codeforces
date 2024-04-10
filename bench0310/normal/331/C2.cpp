#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<array<ll,2>,array<ll,2>> m;

array<ll,2> go(ll n,int mx)
{
    if(n==0) return {0,0};
    if(n<=9) return {1,max(n,ll(mx))};
    if(m.find({n,mx})!=m.end()) return m[{n,mx}];
    string s=to_string(n);
    int d=(s[0]-'0');
    ll x=stoll(s.substr(1));
    ll lim=1;
    for(int i=0;i<(int)s.size()-1;i++) lim*=10;
    array<ll,2> res={0,0};
    do
    {
        int nmx=max(mx,d);
        array<ll,2> t=go(x,nmx);
        res[0]+=t[0];
        res[1]+=t[1];
        x-=t[1];
        if(x==0)
        {
            x-=nmx;
            res[1]+=nmx;
            if(nmx) res[0]++;
        }
        x+=lim;
    }while(d--);
    return (m[{n,mx}]=res);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << go(n,0)[0] << "\n";
    return 0;
}