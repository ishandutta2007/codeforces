#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int abi[MAXN];
int pos[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int query(int p)
{
    int res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,x;
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            pos[x]=i+1;
        }

        ll ma=0,res=0;
        for(int i=0;i<m;i++)
        {
            cin >> x;
            if(pos[x]<ma)
                res++;
            else
            {
                ma=pos[x];
                res+=(2*(pos[x]-query(pos[x])))-1;
            }
            update(pos[x],1);
        }
        db(res)

        for(int i=0;i<MAXN;i++)
            abi[i]=pos[i]=0;
    }

    return 0;
}