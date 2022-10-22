#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
typedef pair<char,int> pci;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,x;
    cin >> n;
    vector<pii> v;
    for(ll i=0;i<n;i++)
    {
        cin >> x;
        v.push_back(pii(x,i));
    }

    sort(v.begin(),v.end());

    vector<ll> t;
    t.push_back(v[1].first-v[0].first);
    t.push_back(v[n-1].first-v[n-2].first);
    if(n>=3)
    {
        t.push_back(v[2].first-v[1].first);
        t.push_back(v[n-2].first-v[n-3].first);
    }
    for(auto y : t)
    {
        map<ll,ll> m,mm;
        ll ma=0;
        set<ll> dif;
        for(ll i=0;i<n;i++)
        {
            mm[v[i].first]=v[i].second;
            m[v[i].first]=m[v[i].first-y]+1;
            ma=max(ma,m[v[i].first]);
            if(m[v[i].first]>1)
                dif.erase(v[i].first-y);
            dif.insert(v[i].first);
        }

        if(ma==n-1)
        {
            int st;
            for(auto y : dif)
                if(m[y]==n-1)
                    st=y;
            map<int,int> mmm;
            for(int i=0;i<n-1;i++)
                mmm[st-(i*y)]++;
            for(int i=0;i<n;i++)
            {
                if(mmm[v[i].first])
                    mmm[v[i].first]--;
                else
                {
                    db(v[i].second+1)
                    return 0;
                }
            }
        }
        else if(ma==n)
        {
            for(auto y : dif)
                if(m[y]==n)
                {
                    db(mm[y]+1)
                    return 0;
                }
        }
    }
    db(-1)

    return 0;
}