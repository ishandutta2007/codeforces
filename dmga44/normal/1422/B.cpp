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
typedef unsigned long long ull;
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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e2+5)

bool mk[MAXN][MAXN];
int a[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
                mk[i][j]=0;
            }
        ll res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(mk[i][j])
                    continue;
                vector<int> vs;
                queue<pii> q;
                q.push(pii(i,j));
                mk[i][j]=1;
                while(!q.empty())
                {
                    pii xx=q.front();
                    q.pop();

                    int x=xx.f;
                    int y=xx.s;
                    vs.push_back(a[x][y]);
                    if(!mk[n-1-x][y])
                    {
                        mk[n-1-x][y]=1;
                        q.push(pii(n-1-x,y));
                    }
                    if(!mk[x][m-1-y])
                    {
                        mk[x][m-1-y]=1;
                        q.push(pii(x,m-1-y));
                    }
                }

                sort(all(vs));
                for(int j=0;j<vs.size();j++)
                    res+=abs(vs[j]-vs[vs.size()/2]);
            }
        db(res)
    }

    return 0;
}