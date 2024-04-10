#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9+5)
#define pi acos(-1)
#define MAXN (ll)(4e6+5)

int a[MAXN];
int f[MAXN];
bool mk[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    ll res=0;
    for(int i=n-1;i>=0;i--)
    {
        ll o=0;
        for(int j=20;j>=0;j--)
            if((a[i]&(1<<j))==0 && f[o|(1<<j)]>=2)
                o|=(1<<j);
        if(i<n-2)
            res=max(res,a[i]|o);

        queue<int> q;
        q.push(a[i]);
        vector<int> met;
        mk[a[i]]=1;
        met.push_back(a[i]);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(f[u]>=2)
                continue;

            f[u]++;
            for(int j=0;j<=20;j++)
                if(u&(1<<j) && !mk[u-(1<<j)])
                {
                    mk[u-(1<<j)]=1;
                    met.push_back(u-(1<<j));
                    q.push(u-(1<<j));
                }
        }

        for(auto y : met)
            mk[y]=0;
    }
    db(res)

    return 0;
}