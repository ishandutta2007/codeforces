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
#define MAXN 205

int prec[MAXN*MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll a,b,q;
        cin >> a >> b >> q;
        int lcm=(a*b)/__gcd(a,b);
        for(int k=1;k<lcm;k++)
        {
            prec[k+1]=prec[k];
            if(((k%a)%b)!=((k%b)%a))
                prec[k+1]++;
        }

        while(q--)
        {
            ll l,r;
            cin >> l >> r;
            ll xl=l/lcm;
            ll xr=r/lcm;
            ll rl=l%lcm;
            ll rr=r%lcm;
            if(xl==xr)
                cout << prec[rr+1]-prec[rl] << ' ';
            else
            {
                ll res=0;
                res+=prec[lcm]-prec[rl];
                res+=(xr-xl-1)*(prec[lcm]);
                res+=prec[rr+1];
                cout << res << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
/**
2
4 6 5
1 1
1 3
1 5
1 7
1 9
7 10 2
7 8
100 200
**/