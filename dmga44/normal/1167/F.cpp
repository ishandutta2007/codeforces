#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 500005
#define mod (ll)(1000000007)

ll abi1[MAXN],abi2[MAXN],a[MAXN];
map<int,int> m;

void update1(ll p,ll v)
{
    while(p<MAXN)
    {
        abi1[p]=(abi1[p]+v)%mod;
        p+=(p&-p);
    }
}

ll query1(ll p)
{
    ll res=0;
    while(p)
    {
        res=(res+abi1[p])%mod;
        p-=(p&-p);
    }
    return res;
}

void update2(ll p,ll v)
{
    while(p<MAXN)
    {
        abi2[p]=(abi2[p]+v)%mod;
        p+=(p&-p);
    }
}

ll query2(ll p)
{
    ll res=0;
    while(p)
    {
        res=(res+abi2[p])%mod;
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++)
        m[v[i]]=i+1;

    ll res=0,sum=0;
    for(ll i=0;i<n;i++)
    {
        sum=(sum+((i+1)*a[i]))%mod;
        sum=(sum+(a[i]*query1(m[a[i]]))%mod)%mod;
        update1(m[a[i]],i+1);
        sum=(sum+query2(MAXN-m[a[i]]))%mod;
        update2(MAXN-m[a[i]],((i+1)*a[i])%mod);
        res=(res+sum)%mod;
    }
    db(res)

    return 0;
}