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
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

ll dp[MAXN][MAXN];
int a[MAXN];
int p[MAXN][2];
ll add[MAXN][MAXN];
bool mk[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            dp[i][j]=oo;
    int n,d;
    cin >> n >> d;
    for(int i=1;i<n-1;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        x+=101;
        y+=101;
        p[i][0]=x;
        p[i][1]=y;
        add[x][y]=a[i];
    }

    priority_queue<pip,vector<pip>,greater<pip>> q;
    q.push(pip(0,pii(p[0][0],p[0][1])));
    while(!q.empty())
    {
        pip u=q.top();
        q.pop();
        ll w=u.f;
        int x=u.s.f;
        int y=u.s.s;
        if(mk[x][y])
            continue;

        mk[x][y]=1;
        dp[x][y]=w;
        if(x && !mk[x-1][y])
            q.push(pip(dp[x][y]+d-add[x-1][y],pii(x-1,y)));
        if(y && !mk[x][y-1])
            q.push(pip(dp[x][y]+d-add[x][y-1],pii(x,y-1)));
        if(x<MAXN-1 && !mk[x+1][y])
            q.push(pip(dp[x][y]+d-add[x+1][y],pii(x+1,y)));
        if(y<MAXN-1 && !mk[x][y+1])
            q.push(pip(dp[x][y]+d-add[x][y+1],pii(x,y+1)));
    }
    db(dp[p[n-1][0]][p[n-1][1]])

    return 0;
}