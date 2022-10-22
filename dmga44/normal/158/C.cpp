//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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

    int n;
    cin >> n;
    stack<string> path;
    for(int i=0;i<n;i++)
    {
        string ty;
        cin >> ty;
        if(ty=="pwd")
        {
            vector<string> act;
            while(!path.empty())
            {
                act.push_back(path.top());
                path.pop();
            }
            for(int i=act.size()-1;i>=0;i--)
                cout << "/" << act[i];
            db("/")
            for(int i=act.size()-1;i>=0;i--)
               path.push(act[i]);
        }
        else
        {
            string p;
            cin >> p;
            string act="";
            if(p[0]=='/')
            {
                while(!path.empty())
                    path.pop();
            }
            for(int i=0;i<p.size();i++)
            {
                if(p[i]=='/')
                {
                    if(act.size())
                    {
                        path.push(act);
                        act.clear();
                    }
                }
                else if(p[i]=='.')
                {
                    path.pop();
                    i+=2;
                }
                else
                    act.push_back(p[i]);
            }
            if(act.size())
                path.push(act);
        }
    }

    return 0;
}