#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int mex(vector<int> gs)
{
    set<int> s;
    for(auto y : gs)
        s.insert(y);
    int ans=0;
    while(s.count(ans))
        ans++;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> gs;
    gs.push_back(0);
    gs.push_back(1);
    gs.push_back(1);
    for(int i=3;i<=MAXN;i++)
    {
        if(i<=100)
        {
            vector<int>ps;
            for(int j=0;j<i;j++)
            {
                ps.push_back(gs[max(0ll,j-1)]^gs[max(0ll,i-j-2)]);
            }
            gs.push_back(mex(ps));
        }
        else
            gs.push_back(gs[i-34]);
    }

    // for(int i=0;i<=100;i++)
    // {
    //     cerr << "\n";
    //     db(i)
    //     cerr << gs[i] << '\n';
    // }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sz=0;
        int ini=-1;
        ll g=0;
        int extra=0;
        for(int i=0;i<n;i++)
        {
            if(i)
            {
                if(s[i]!=s[i-1])
                {
                    if(ini==-1)
                    {
                        ini=(s[i-1]=='B');
                        sz=2;
                    }
                    else
                    {
                        sz++;
                    }
                }
                else
                {
                    if(ini!=-1)
                    {
                        g^=gs[sz-1];
                        ini=-1;
                        sz=0;
                    }
                }
            }
            if(s[i]=='R')
                extra++;
            else
                extra--;
        }
        if(ini!=-1)
        {
            g^=gs[sz-1];
            ini=-1;
            sz=0;
        }

        // cout << g << ' ' << extra << '\n';
        if(g)
            extra++;
        if(extra<=0)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }

    return 0;   
}