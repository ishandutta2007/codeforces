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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1<<22)

bool ok[MAXN];
int nex[MAXN];
int lca[MAXN][2];
int sum[MAXN][2];
int acts[MAXN][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x,y;
    cin >> n >> x >> y;
    ok[0]=1;
    nex[0]=(1<<21);
    lca[0][0]=nex[0];
    sum[0][0]=1;
    for(int i=1;i<MAXN;i++)
    {
        if(!ok[i^(i&-i)])
            continue;
        ok[i]=1;
        for(int j=0;j<22;j++)
        {
            if(!(i&(1<<j)))
                continue;
            if((1<<j)==(i&-i))
                continue;
            if(((1<<x)==(1<<j)/(i&-i)) || ((1<<y)==(1<<j)/(i&-i)))
                ok[i]=0;
        }

        if(ok[i])
        {
            int kk=1;
            if((i&(1<<(22-x))) || (i&(1<<(22-y))))
                kk=0;
            nex[i]=(kk<<21)|(i>>1);
            lca[i][0]=nex[i];
            sum[i][0]=kk;
        }
    }
    if(n<=22)
    {
        int res=0;
        for(int i=0;i<MAXN;i++)
            if(ok[i])
                res=max(res,__builtin_popcount(i&((1<<n)-1)));
        db(res)
    }
    else
    {
        int x=n-22;
        for(int i=0;i<MAXN;i++)
            if(ok[i])
            {
                acts[i][1]=__builtin_popcount(i);
                acts[i][0]=i;
                if(x&1)
                {
                    acts[i][1]+=sum[i][0];
                    acts[i][0]=lca[i][0];
                }
            }
        for(int j=1;j<31;j++)
        {
            for(int i=0;i<MAXN;i++)
                if(ok[i])
                {
                    lca[i][j&1]=lca[lca[i][1-(j&1)]][1-(j&1)];
                    sum[i][j&1]=sum[i][1-(j&1)]+sum[lca[i][1-(j&1)]][1-(j&1)];
                }
            if(x&(1<<j))
                for(int i=0;i<MAXN;i++)
                    if(ok[i])
                    {
                        acts[i][1]+=sum[acts[i][0]][j&1];
                        acts[i][0]=lca[acts[i][0]][j&1];
                    }
        }

        int res=0;
        for(int i=0;i<MAXN;i++)
            res=max(res,acts[i][1]);
        db(res)
    }

    return 0;
}