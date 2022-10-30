#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, q;
ll tleft[300005];
ll tright[300005];
ll safeleft[300005];
ll saferight[300005];
ll a[300005][4];
ll b[4];
ll ans;
vector < ll > safe;
ll dis(ll pa, ll pb)
{
    return abs(pa-pb);
}
ll solve(ll i, ll x, ll y)
{
    ll ansa=dis(x, tright[i]);
    ansa+=dis(tright[i], tleft[i]);
    ansa+=dis(tleft[i], y);
    ll ansb=dis(x, tleft[i]);
    ansb+=dis(tright[i], tleft[i]);
    ansb+=dis(tright[i], y);
    return 1+min(ansa, ansb);
}
ll solvelast(ll x)
{
    ll ansa=dis(x, tright[n]);
    ansa+=dis(tright[n], tleft[n]);
    ll ansb=dis(x, tleft[n]);
    ansb+=dis(tright[n], tleft[n]);
    return 1+min(ansa, ansb);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k>>q;
    ll x=0, y=0;
    for (ll i=1; i<=k; i++)
    {
        cin>>x>>y;
        if (tleft[x]==0) tleft[x]=y;
        tleft[x]=min(tleft[x], y);
        tright[x]=max(tright[x], y);
    }
    for (ll i=1; i<=q; i++)
    {
        cin>>x;
        safe.push_back(x);
    }
    sort(safe.begin(), safe.end());
    for (ll j=1; j<=safe[0]; j++)
    {
        saferight[j]=safe[0];
    }
    for (ll j=safe[0]; j<safe[1]; j++)
    {
        safeleft[j]=safe[0];
    }
    for (ll i=1; i<safe.size()-1; i++)
    {
        for (ll j=safe[i-1]+1; j<=safe[i]; j++)
        {
            saferight[j]=safe[i];
        }
        for (ll j=safe[i]; j<safe[i+1]; j++)
        {
            safeleft[j]=safe[i];
        }
    }
    for (ll j=safe[safe.size()-2]+1; j<=safe[safe.size()-1]; j++)
    {
        saferight[j]=safe[safe.size()-1];
    }
    for (ll j=safe[safe.size()-1]; j<=m; j++)
    {
        safeleft[j]=safe[safe.size()-1];
    }
    while (tleft[n]==0)
    {
        n--;
    }
    if (n==1)
    {
        cout<<tright[1]-1;
        return 0;
    }
    if (tright[1]==0)
    {
        a[1][0]=saferight[1]-1;
        b[0]=saferight[1];
    }
    else{
            if (safeleft[tright[1]]!=0)
            {
                a[1][0]=tright[1]-1+dis(tright[1], safeleft[tright[1]]);
                b[0]=safeleft[tright[1]];
            }
            if (saferight[tright[1]]!=0)
            {
                a[1][1]=tright[1]-1+dis(tright[1], saferight[tright[1]]);
                b[1]=saferight[tright[1]];
            }
    }
    for (ll i=2; i<n; i++)
    {
        ll c[4];
        if (tright[i]==0)
        {
            for (ll j=0; j<4; j++)
            {
            a[i][j]=a[i-1][j]+1;
            }
            continue;
        }
        c[0]=safeleft[tleft[i]];
        c[1]=saferight[tleft[i]];
        c[2]=safeleft[tright[i]];
        c[3]=saferight[tright[i]];
        for (ll p=0; p<4; p++)
        {
            a[i][p]=INT_MAX;
            a[i][p]*=a[i][p];
        }
        for (ll j=0; j<4; j++)
        {
            if (b[j]!=0)
            {
                for (ll p=0; p<4; p++)
                {
                    if (c[p]!=0)
                    {
                        a[i][p]=min(a[i][p], a[i-1][j]+solve(i, b[j], c[p]));
                    }
                }
            }
        }
        for (ll j=0; j<4; j++)
        {
            b[j]=c[j];
        }
    }
    ans=INT_MAX;
    ans*=ans;
    for (ll j=0; j<4; j++)
    {
        if (b[j]!=0)
        {
            ans=min(ans, a[n-1][j]+solvelast(b[j]));
        }
    }
    cout<<ans;
}