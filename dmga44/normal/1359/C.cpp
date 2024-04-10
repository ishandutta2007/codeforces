#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--)
    {
        ll h,c,t;
        cin >> h >> c >> t;
        t-=c;
        h-=c;
        if(t*2<=h)
            db(2)
        else
        {
            ll res=0;
            for(ll po=(1ll<<40);po;po>>=1)
            {
                ll r1=res+po;
                ll tt=t*(r1*2+1);
                ll hh=h*(r1+1);
                if(hh>=tt)
                    res=r1;
            }
            ll p1=res;
            ll p2=res+1;
//            db(res)
            ll v1=((ld)h*(p1+1))/(2*p1+1);
            ll v2=((ld)h*(p2+1))/(2*p2+1);
            ll tt=2*t*(2*p1+1)*(2*p2+1);
            ll hh=h*(p1+1)*(2*p2+1)+h*(p2+1)*(2*p1+1);
//            db(tt)
//            db(hh)
//            cout.precision(10);
//            cout<<fixed;
//            db(v1)
//            db(v2)
            if(hh<=tt)
                db((ll)(2*p1+1))
            else
                db((ll)(2*p2+1))

        }
    }

    return 0;
}
/**
3
30 10 20
41 15 30
18 13 18

1
1000000 0 500001
**/