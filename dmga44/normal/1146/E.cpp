#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005

int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q,a;
    cin >> n >> q;
    vector<pip> v;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        v.push_back(pip(abs(a),pii(a,i)));
    }

    sort(v.rbegin(),v.rend());

    vector<pii> qs;
    for(int i=0;i<q;i++)
    {
        char c;
        cin >> c >> a;
        if(c=='<')
            qs.push_back(pii(0,a));
        else
            qs.push_back(pii(1,a));
    }

    bool mod=0;
    int p=0,ant=MAXN;
    for(int i=0;i<q;i++)
    {
        int t=qs[q-i-1].first;
        a=qs[q-i-1].second;
        if(abs(a)<=ant)
        {
            while(p<n && v[p].first>abs(a)-((a<0)==t))
            {
                int mul=1;
                if(mod)
                    mul=-1;
                if(t)
                {
                    if(v[p].second.first>a)
                        res[v[p].second.second]=mul*-v[p].second.first;
                    else
                        res[v[p].second.second]=mul*v[p].second.first;
                }
                else
                {
                    if(v[p].second.first<a)
                        res[v[p].second.second]=mul*-v[p].second.first;
                    else
                        res[v[p].second.second]=mul*v[p].second.first;
                }
                p++;
            }
            ant=abs(a);
        }

        if(a<0)
        {
            if(t)
                mod=1-mod;
        }
        else
        {
            if(!t)
                mod=1-mod;
        }
    }

    int mul=1;
    if(mod)
        mul=-1;
    while(p<n)
    {
        res[v[p].second.second]=(mul*v[p].second.first);
        p++;
    }

    for(int i=0;i<n;i++)
        cout << res[i] << ' ';

    return 0;
}