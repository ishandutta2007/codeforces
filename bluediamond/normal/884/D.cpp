#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

priority_queue<ll> pq;

void ins(ll x)
{
    pq.push(-x);
}

ll get()
{
    ll x=-pq.top();
    pq.pop();
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /// * do it in reverse order!

    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        ins(x);
    }

    ll ans=0;
    if (n%2==0)
    {
        ll x=get()+get();
        ans+=x;
        ins(x);
        n--;
    }

    while (n>=3)
    {
        n-=2;
        ll x=get()+get()+get();
        ans+=x;
        ins(x);
    }
    cout<<ans<<"\n";

}