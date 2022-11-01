#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll cut(ll a,int c)
{
    ll x=(a/c);
    ll one=c-(a%c);
    ll two=a%c;
    return (one*x*x+two*(x+1)*(x+1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> q; //mv,a,c
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin >> a;
        res+=(a*a);
        if(a>1) q.push({cut(a,2)-cut(a,1),a,1});
    }
    for(int i=0;i<k-n;i++)
    {
        auto [mv,a,c]=q.top();
        q.pop();
        res+=mv;
        c++;
        if(c<a) q.push({cut(a,c+1)-cut(a,c),a,c});
    }
    cout << res << "\n";
    return 0;
}