#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int ini=0;
        vector<pii> vals;
        for(int i=0;i<n;i++)
        {
            cin >> v[i];
            if(i && v[i]<v[i-1])
            {
                vals.push_back(pii(ini,v[i-1]));
                ini=v[i];
            }
            if(!i)
                ini=v[i];
        }
        vals.push_back(pii(ini,v[n-1]));

        bool ok=1;
        for(int i=1;i<vals.size();i++)
            ok&=vals[i-1].first>vals[i].second;
        if(ok)
            db("Yes")
        else
            db("No")
    }

    return 0;
}
/**
5
5
2 3 4 5 1
1
1
3
1 3 2
4
4 2 3 1
5
1 5 2 4 3
**/