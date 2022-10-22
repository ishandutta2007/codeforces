#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
typedef pair<char,int> pci;
#define mod (ll(1e9+7))

int dp[(1<<15)][3],ty[15],ti[(1<<15)];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,t;
    cin >> n >> t;
    for(int i=0;i<n;i++)
    {
        cin >> ti[(1<<i)] >> ty[i];
        ty[i]--;
        dp[(1<<i)][ty[i]]=1;
    }

    for(int i=1;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            if(!(i&(1<<j)))
            {
                ti[i+(1<<j)]=ti[i]+ti[(1<<j)];
                for(int u=0;u<3;u++)
                    if(u!=ty[j])
                        dp[i|(1<<j)][ty[j]]=(dp[i|(1<<j)][ty[j]]+dp[i][u])%mod;
            }

    int res=0;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<3;j++)
            if(ti[i]==t)
                res=(res+dp[i][j])%mod;
    db(res)

//    ll n,x;
//    cin >> n;
//    vector<pii> v;
//    for(ll i=0;i<n;i++)
//    {
//        cin >> x;
//        v.push_back(pii(x,i));
//    }
//
//    sort(v.begin(),v.end());
//
//    vector<ll> t;
//    t.push_back(v[1].first-v[0].first);
//    t.push_back(v[n-1].first-v[n-2].first);
//    if(n>=3)
//    {
//        t.push_back(v[2].first-v[1].first);
//        t.push_back(v[n-2].first-v[n-3].first);
//    }
//    for(auto y : t)
//    {
//        map<ll,ll> m,mm;
//        ll ma=0;
//        set<ll> dif;
//        for(ll i=0;i<n;i++)
//        {
//            mm[v[i].first]=v[i].second;
//            m[v[i].first]=m[v[i].first-y]+1;
//            ma=max(ma,m[v[i].first]);
//            if(m[v[i].first]>1)
//                dif.erase(v[i].first-y);
//            dif.insert(v[i].first);
//        }
//
//        if(ma==n-1)
//        {
//            for(auto y : dif)
//                if(m[y]==1)
//                {
//                    db(mm[y]+1)
//                    return 0;
//                }
//        }
//        else if(ma==n)
//        {
//            for(auto y : dif)
//                if(m[y]==n)
//                {
//                    db(mm[y]+1)
//                    return 0;
//                }
//        }
//    }
//    db(-1)

//    map<ll,ll> m;
//    ll ma=0;
//    for(int i=0;i<n-1;i++)
//    {
//        m[v[i+1].first-v[i].first]++;
//        ma=max(ma,m[v[i+1].first-v[i].first]);
//    }
//
//    if(ma==n-1)
//        db(v[0].second+1)
//    else if(ma==n-2)
//    {
//        if(m[v[1].first-v[0].first]==n-2)
//            db(v[n-1].second+1)
//        else
//            db(v[0].second+1)
//    }
//    else if(ma==n-3)
//    {
//
//        ll d1=v[1].first-v[0].first;
//        if(m[d1]!=ma)
//            d1=v[n-1].first-v[n-2].first;
//        if(m[d1]!=ma)
//            db(-1)
//        for(ll i=1;i<n-1;i++)
//            if(v[i+1].first-v[i-1].first==d1 && v[i+1].first-v[i].first<d1 && v[i].first-v[i-1].first<d1)
//            {
//                db(v[i].second+1)
//                return 0;
//            }
//        db(-1)
//    }
//    else
//        db(-1)

    return 0;
}