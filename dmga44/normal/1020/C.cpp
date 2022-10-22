#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 3005

ll p[MAXN],c[MAXN],cant[MAXN],c2[MAXN];
vector<pii> ps[MAXN];
vector<pip> vp;
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<pii> pos;
    for(ll i=0;i<n;i++)
    {
        cin >> p[i] >> c[i];
        p[i]--;
        cant[p[i]]++;
        if(!p[i])
            continue;
        pos.push_back(pii(c[i],i));
        ps[p[i]].push_back(pii(c[i],i));
    }

    for(int i=0;i<m;i++)
        sort(ps[i].rbegin(),ps[i].rend());

    for(int i=1;i<m;i++)
        for(int j=0;j<ps[i].size();j++)
            vp.push_back(pip(-j-1,ps[i][j]));

    sort(pos.begin(),pos.end());
    sort(vp.begin(),vp.end());

    c2[0]=cant[0];
    ll res=3000000000000000;
    for(int i=0;i<=n;i++)
    {
        ll sum=0;
        for(int j=0;j<n;j++)
            mk[j]=0;
        cant[0]=c2[0];
        for(int j=0;j<min(i,(int)pos.size());j++)
        {
            cant[0]++;
            sum+=pos[j].first;
            mk[pos[j].second]=1;
        }
        ll pp=0;
        while(pp<vp.size() && cant[0]<=(-(vp[pp].first)))
        {
            if(mk[vp[pp].second.second])
            {
                pp++;
                continue;
            }
            sum+=vp[pp].second.first;
            cant[0]++;
            pp++;
        }
        res=min(res,sum);
    }
    db(res)

    return 0;
}