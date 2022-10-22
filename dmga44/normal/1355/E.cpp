#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005

ll aa[MAXN],n,a,r,m;

ll solve(ll x)
{
    ll s[2];
    s[0]=s[1]=0;
    for(int i=0;i<n;i++)
        s[(aa[i]<x)]+=abs(aa[i]-x);
    ll iq=min(s[0],s[1]);
    s[0]-=iq;
    s[1]-=iq;
    return (s[0]*r)+(s[1]*a)+(iq*min(m,a+r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> r >> m;
    for(int i=0;i<n;i++)
        cin >> aa[i];

    ll l=0,r=1e9;
    while(r-l>10)
    {
        ll m1=(l+r+l)/3;
        ll m2=(l+r+r)/3;

        ll c1=solve(m1);
        ll c2=solve(m2);
        if(c1<c2)
            r=m2;
        else
            l=m1;
    }

    ll res=1e18;
    for(int i=l;i<=r;i++)
        res=min(res,solve(i));
    db(res)

    return 0;
}
/**
3 1 100 100
1 3 8
**/