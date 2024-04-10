#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

const ll N=2e5+5;

ll total; ll a,b;
ll mana;
ll t[N],c1[N];
ll scd[N],c2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>total>>a>>b;
    cin>>t[0]>>mana;
    for(ll i=1;i<=a;i++) cin>>t[i];
    for(ll i=1;i<=a;i++) cin>>c1[i];
    for(ll i=1;i<=b;i++) cin>>scd[i];
    for(ll i=1;i<=b;i++) cin>>c2[i];
    ll ans=(1LL<<62);
    for(ll i=0;i<=a;i++)
    {
        ll lft=mana-c1[i];
        if(lft<0) continue;
        ll r=0,pas=(1<<17);
        while(pas)
        {
            if(r+pas<=b && c2[r+pas]<=lft) r+=pas; pas/=2;
        }
        ll have=total-scd[r];
        if(have<=0)
        {
            ans=min(ans,0LL);
            continue;
        }
        ans=min(ans,have*t[i]);
    }
    cout<<ans<<"\n";
}
/**

**/