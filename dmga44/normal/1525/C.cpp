#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
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
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)((1e18)+5);
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> x(n);
        for(int i=0;i<n;i++)
            cin >> x[i];
        vector<int> d(n);
        for(int i=0;i<n;i++)
        {
            char c;
            cin >> c;
            d[i]=(c=='L');
        }

        vector<pip> ts;
        for(int i=0;i<n;i++)
            ts.push_back(pip(x[i],pii(d[i],i)));
        vector<int> backs(n);
        sort(all(ts));
        for(int i=0;i<n;i++)
        {
            x[i]=ts[i].f;
            d[i]=ts[i].s.f;
            backs[ts[i].s.s]=i;
        }

        vector<int> ans(n);
        vector<pii> rs[2];
        vector<pii> ls[2];
        for(int i=0;i<n;i++)
        {
            if(d[i]==0)
            {
                rs[x[i]&1].push_back(pii(x[i],i));
            }
            else
            {
                if(rs[x[i]&1].empty())
                    ls[x[i]&1].push_back(pii(x[i],i));
                else
                {
                    pii p=rs[x[i]&1].back();
                    rs[x[i]&1].pop_back();
                    
                    int time=(x[i]-p.f)/2;
                    ans[p.s]=ans[i]=time;
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     // if(ans[i]==0)
        //     //     ans[i]=-1;
        //     cout << ans[i] << " \n"[i==n-1];
        // }

        vector<pii> r2,l2;
        for(int i=0;i<2;i++)
        {
            int sz=rs[i].size();
            for(int j=1;j<rs[i].size();j+=2)
            {
                int time=(rs[i][sz-j].f-rs[i][sz-j-1].f)/2+m-rs[i][sz-j].f;
                ans[rs[i][sz-j].s]=ans[rs[i][sz-j-1].s]=time;
            }
            if(sz&1)
                r2.push_back(pii(rs[i][0]));
        }
        
        for(int i=0;i<2;i++)
        {
            int sz=ls[i].size();
            for(int j=1;j<ls[i].size();j+=2)
            {
                int time=(ls[i][j].f-ls[i][j-1].f)/2+ls[i][j-1].f;
                ans[ls[i][j].s]=ans[ls[i][j-1].s]=time;
            }
            if(sz&1)
                l2.push_back(pii(ls[i].back()));
        }

        for(int i=0;i<r2.size();i++)
            r2[i]=pii(m-r2[i].f,r2[i].s);
        for(int i=0;i<l2.size();i++)
            l2[i]=pii(l2[i].f,l2[i].s);
        
        // for(int i=0;i<n;i++)
        // {
        //     // if(ans[i]==0)
        //     //     ans[i]=-1;
        //     cout << ans[i] << " \n"[i==n-1];
        // }
        for(int i=0;i<r2.size();i++)
            for(int j=0;j<l2.size();j++)
            {
                int tr=r2[i].f;
                int tl=l2[j].f;
                int pr=r2[i].s;
                int pl=l2[j].s;
                // cout << tl << ' ' << tr << '\n';
                if((abs(tr-tl)&1)==(m&1))
                {
                    int time=max(tr,tl)+(m-abs(tr-tl))/2;
                    ans[pr]=ans[pl]=time;
                }
            }

        for(int i=0;i<n;i++)
        {
            int p=backs[i];
            if(ans[p]==0)
                ans[p]=-1;
            cout << ans[p] << " \n"[i==n-1];
        }
    }

    return 0;
}