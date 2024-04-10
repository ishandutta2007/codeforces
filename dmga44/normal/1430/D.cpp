#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cant=0;
        int sz=0;
        int ty=-1;
        int erases=0;
        vector<int> bs;
        for(int i=0;i<n;i++)
        {
            if((s[i]-'0')!=ty)
            {
                if(ty!=-1)
                    bs.push_back(sz);
                sz=0;
                cant++;
                ty=s[i]-'0';
            }
            else
            {
                if(erases<cant)
                {
                    erases++;
                    sz--;
                }
            }
            sz++;
        }
        bs.push_back(sz);

//        db(erases)
//        db(bs.size())
        if(bs.size()>erases)
        {
            while(bs.size()>erases)
            {
                erases+=bs.back();
                bs.pop_back();
            }
        }

        db(bs.size()+(erases>bs.size()))
    }

    return 0;
}