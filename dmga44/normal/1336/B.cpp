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

ll cal(ll x,ll y,ll z)
{
    return (x-y)*(x-y)+(x-z)*(x-z)+(z-y)*(z-y);
}

ll solve(vector<ll> x,vector<ll> y,vector<ll> z)
{
    ll res=4e18;
    for(auto vx : x)
    {
        vector<int> py,pz;
        int y1=lower_bound(all(y),vx)-y.begin();
        if(y1<y.size() && y[y1]==vx)
            py.push_back(y1);

        y1--;
        int y2=upper_bound(all(y),vx)-y.begin();
        int z1=lower_bound(all(z),vx)-z.begin();
        if(z1<z.size() && z[z1]==vx)
            pz.push_back(z1);
        z1--;
        int z2=upper_bound(all(z),vx)-z.begin();

        if(y1>=0)
            py.push_back(y1);
        if(y2<y.size())
            py.push_back(y2);
        if(z1>=0)
            pz.push_back(z1);
        if(z2<z.size())
            pz.push_back(z2);

        for(auto vy : py)
            for(auto vz : pz)
                res=min(res,cal(vx,y[vy],z[vz]));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int nr,ng,nb,x;
        cin >> nr >> ng >> nb;
        vector<ll> pqr,pqg,pqb;
        for(int i=0;i<nr;i++)
        {
            cin >> x;
            pqr.push_back(x);
        }
        for(int i=0;i<ng;i++)
        {
            cin >> x;
            pqg.push_back(x);
        }
        for(int i=0;i<nb;i++)
        {
            cin >> x;
            pqb.push_back(x);
        }

        sort(all(pqr));
        sort(all(pqg));
        sort(all(pqb));

        ll res=4e18;
        res=min(res,solve(pqr,pqg,pqb));
        res=min(res,solve(pqg,pqr,pqb));
        res=min(res,solve(pqb,pqg,pqr));
        db(res)
    }

    return 0;
}
/**
2
2 2 3
7 8
6 3
3 1 4
1 1 1
1
1
1000000000
**/