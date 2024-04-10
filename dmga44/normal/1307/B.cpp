#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 105

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,x;
        cin >> n >> x;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin >> v[i];

        sort(v.begin(),v.end());

        ll res=1e9;
        for(int i=0;i<n;i++)
        {
            if(v[i]==x)
                res=1;
            if(v[i]*2>=x)
                res=min(res,2ll);
            else
                res=min(res,((x-1)/v[i])+1);
        }
        db(res)
    }

    return 0;
}