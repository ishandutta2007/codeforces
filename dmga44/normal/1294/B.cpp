#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ll,pii> pip;

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
        vector<pii> v(n);
        for(int i=0;i<n;i++)
            cin >> v[i].first >> v[i].second;

        v.push_back(pii(0,0));
        sort(v.begin(),v.end());

        bool ok=1;
        vector<char> res;
        for(int i=1;i<=n;i++)
        {
            if(v[i].second<v[i-1].second)
                ok=0;
            for(int j=0;j<v[i].first-v[i-1].first;j++)
                res.push_back('R');
            for(int j=0;j<v[i].second-v[i-1].second;j++)
                res.push_back('U');
        }

        if(ok)
        {
            db("YES")
            for(auto y : res)
                cout << y;
            cout << '\n';
        }
        else
            db("NO")
    }

    return 0;
}