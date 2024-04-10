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

ll res[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    res[1]=1;
    res[2]=3;
    res[3]=5;

    int t;
    cin >> t;
    while(t--)
    {
        ll d,m;
        cin >> d >> m;
        if(d<4)
        {
            cout << res[d]%m << '\n';
            continue ;
        }
        ll last=5%m,p=4;
        while((p*2)-1<d)
        {
            last=(last+((last+1)*p))%m;
            p*=2;
        }
//        cout << last << ' ';
        db(((d-p+1)*(last+1)+last)%m)
    }

    return 0;
}
/**
10
1 1000000
2 1000000
3 1000000
4 1000000
5 1000000
6 1000000
7 1000000
8 1000000
9 1000000
10 1000000
**/