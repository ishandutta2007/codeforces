#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

ll r,c;

inline ll dir(ll rx,ll cx)
{
    if(c==cx)
    {
        if(rx<r) return 0; else return 1;
    }
    if(r==rx)
    {
        if(cx<c) return 2; else return 3;
    }
    if(r-c==rx-cx)
    {
        if(rx<r) return 4; else return 5;
    }
    if(r+c==rx+cx)
    {
        if(rx<r) return 6; else return 7;
    }
    return -1;
}

inline ll dist(ll rx,ll cx)
{
    return max(abs(r-rx),abs(c-cx));
}

ll mi[11],inf=(1LL<<60);
bool a[11];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(ll i=0;i<8;i++) mi[i]=inf;
    ll n; cin>>n;
    cin>>r>>c;
    while(n--)
    {
        string t; cin>>t;
        ll rx,cx; cin>>rx>>cx;
        ll d=dir(rx,cx);
        ll now=dist(rx,cx);
        if(now<mi[d])
        {
            mi[d]=now;
            if(d<=3)
            {
                if(t=="R" || t=="Q") a[d]=1; else a[d]=0;
            }
            else
            {
                if(t=="B" || t=="Q") a[d]=1; else a[d]=0;
            }
        }
    }
    for(ll i=0;i<8;i++)
    {
        if(a[i])
        {
            cout<<"YES\n"; return 0;
        }
    }
    cout<<"NO\n";
}
/**

**/