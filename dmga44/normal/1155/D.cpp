#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 300005

ll a[MAXN],ad[MAXN],ac[MAXN],ad2[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,x;
    cin >> n >> x;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        ac[i+1]=(ac[i]+a[i]);
    }

    ll mi=0,sum=0;
    for(ll i=n-1;i>=0;i--)
    {
        ad[i+1]=sum-mi;
        sum+=a[i];
        mi=min(mi,sum);
    }
    ad[0]=sum-mi;

    mi=0,sum=0;
    for(ll i=0;i<n;i++)
    {
        ad2[i]=sum-mi;
        sum+=a[i];
        mi=min(mi,sum);
    }
    ad2[n]=sum-mi;

    ll mid=0,res=0;
    for(ll i=0;i<n;i++)
    {
        mid=min(mid,(-ad2[i+1])+(ac[i+1]*x));
        res=max(res,(ac[i+1]*x)+ad[i+1]-mid);
    }
    db(res)

    return 0;
}