#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pii> vp(n);
        set<int> s;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin >> x >> y;
            vp[i]=pii(x,y);
            s.insert(x);
            s.insert(y);
        }

        map<int,int> ms;
        int cont=0;
        for(auto y : s)
        {
            cont++;
            ms[y]=cont;
        }

        for(int i=0;i<n;i++)
        {
            vp[i].f=ms[vp[i].f];
            vp[i].s=ms[vp[i].s];
        }

        vector<ppp> le;
        for(int i=0;i<n;i++)
            le.push_back(ppp(pii(vp[i].s-vp[i].f,1),pii(vp[i].f,vp[i].s)));
        sort(all(le));
        vector<pii> ps[cont+1];
        for(int i=0;i<n;i++)
        {
            vector<int> dp(cont+1);
            int res=0;
            for(int j=le[i].s.f;j<=le[i].s.s;j++)
            {
                for(auto y : ps[j])
                {
                    if(y.f<le[i].s.f)
                        continue;
                    dp[j]=max(dp[j],(int)dp[y.f-1]+(int)y.s);
                }
                dp[j]=max(dp[j],dp[j-1]);
                res=max(res,dp[j]);
            }
//            cout << le[i].s.s << ' ' << le[i].s.f << ' ' << res+1 << '\n';
            ps[le[i].s.s].push_back(pii(le[i].s.f,res+1));
        }
        int res=0;
        vector<int> dp(cont+1);
        for(int i=1;i<=cont;i++)
        {
            for(auto y : ps[i])
                dp[i]=max(dp[i],(int)dp[y.f-1]+(int)y.s);
            dp[i]=max(dp[i],dp[i-1]);
            res=max(res,dp[i]);
        }
        db(res)
    }

    return 0;
}
/**
4
4
1 5
2 4
2 3
3 4
5
1 5
2 3
2 5
3 5
2 2
3
1 3
2 4
2 3
7
1 10
2 8
2 5
3 4
4 4
6 8
7 7
**/