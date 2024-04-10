#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> pip;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,x,s1=0,s2=0;
    cin >> n;
    vector<pii> v1,v2;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        v1.push_back(pii(x,i));
        s1+=x;
    }

    for(int i=0;i<n;i++)
    {
        cin >> x;
        v2.push_back(pii(x,i));
        s2+=x;
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    vector<pip> b1,b2;
    bool ok=1,no=0;
    for(int i=0;i<n;i++)
    {
        if(v1[i].first<v2[i].first)
            b1.push_back(pip(pii(v1[i].first,v1[i].second),v2[i].first));
        else if(v1[i].first!=v2[i].first)
            b2.push_back(pip(pii(v1[i].first,v1[i].second),v2[i].first));
    }

    sort(b1.begin(),b1.end());
    sort(b2.begin(),b2.end());

    if(s1!=s2)
        db("NO")
    else
    {

        int l=0,r=0,ok=1;
        vector<pip> res;
        while(l<b1.size() && r<b2.size() && ok)
        {
//            cout << l << ' ' << r << '\n';
//            cout << b1[l].first.first << ' ' << b1[l].second << '\n';
//            cout << b2[r].first.first << ' ' << b2[r].second << '\n';
            if(b2[r].second<b1[l].second)
                ok=0;
            else
            {
                ll dif=min(b1[l].second-b1[l].first.first,b2[r].first.first-b2[r].second);
                res.push_back(pip(pii(b1[l].first.second+1,b2[r].first.second+1),dif));
                b1[l].first.first+=dif;
                b2[r].first.first-=dif;
                if(b1[l].first.first==b1[l].second)
                    l++;
                if(b2[r].first.first==b2[r].second)
                    r++;
            }
        }
        if(!ok)
            db("NO")
        else
        {
            db("YES")
            cout << res.size() << '\n';
            for(auto y : res)
                cout << y.first.first << ' ' << y.first.second << ' ' << y.second << '\n';
        }

    }

    return 0;
}