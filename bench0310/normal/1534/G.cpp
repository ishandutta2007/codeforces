#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[i]={x+y,x-y};
    }
    sort(v.begin(),v.end());
    priority_queue<ll> l;
    priority_queue<ll,vector<ll>,greater<ll>> r;
    ll dl=0,dr=0;
    ll m=0;
    int now=0;
    for(auto [nxt,t]:v)
    {
        dl-=(nxt-now);
        dr+=(nxt-now);
        now=nxt;
        if(l.empty()||(l.top()+dl<t&&t<r.top()+dr))
        {
            l.push(t-dl);
            r.push(t-dr);
        }
        else if(t<=l.top()+dl)
        {
            l.push(t-dl);
            l.push(t-dl);
            m-=t;
            ll x=l.top()+dl;
            l.pop();
            m+=x;
            r.push(x-dr);
        }
        else
        {
            r.push(t-dr);
            r.push(t-dr);
            m+=t;
            ll x=r.top()+dr;
            r.pop();
            m-=x;
            l.push(x-dl);
        }
    }
    cout << m/2 << "\n";
    return 0;
}