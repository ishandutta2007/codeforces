#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

ll l[MAXN],r[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<pii> v;
    ll res=n;
    for(ll i=0;i<n;i++)
    {
        cin >> l[i] >> r[i];
        res+=(l[i]+r[i]);
        v.push_back(pii(l[i],0));
        v.push_back(pii(r[i],1));
    }

    sort(v.begin(),v.end());
    queue<ll> ls,rs;

    for(auto y : v)
    {
        if(y.second)
            rs.push(y.first);
        else
            ls.push(y.first);
        while(!ls.empty() && !rs.empty())
        {
            res-=(min(ls.front(),rs.front()));
            ls.pop();
            rs.pop();
        }
    }
    db(res)

    return 0;
}