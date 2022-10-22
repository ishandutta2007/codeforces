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

map<pii,vector<point>> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x,y,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        if(!x && !y)
            continue;
        int g=__gcd(abs(x),abs(y));
        mp[pii(x/g,y/g)].push_back(point(x,y));
    }

    vector<ld> vd;
    for(auto y : mp)
    {
        vector<point> v=y.s;

        sort(all(v),[&](point a,point b)
         {
            return abs(a)<abs(b);
         });

//        db("")
//        cout << y.f.f << ' ' << y.f.s << '\n';
        ld sum=0;
        for(int i=0;i<v.size();i++)
        {
            if((i*2+1)<=k)
            {
                vd.push_back((k-(2*i+1))*abs(v[v.size()-i-1]));
//                cout << (k-(2*i+1))*abs(v[v.size()-i-1]) << '\n';
            }
            else
            {
                ld bef=(k-1)/2+1;
                ld val=abs(v[i-bef]);
                ld add=(k-1-2*bef)*val-2*sum;
//                cout << add << '\n';
                vd.push_back(add);
                sum+=val;
            }
        }
    }
    vd.push_back(0);
    sort(allr(vd));

//    for(auto y : vd)
//        db(y)

    ld res=0;
    for(int i=0;i<k;i++)
        res+=vd[i];
    cout.precision(15);
    cout<<fixed;
    db(res)

    return 0;
}
/**
6 5
0 0
1 1
2 2
3 3
0 1
0 2

13 10
0 0
1 0
2 0
3 0
4 0
5 0
6 0
7 0
8 0
9 0
0 -2
0 1
0 2

10 5
2 2
4 4
3 5
6 10
0 5
0 0
5 0
10 0
0 10
4 7
**/