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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

int c[MAXN];
vector<pii> edges;
bool used[MAXN];
int d[MAXN][MAXN];
int tr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> d[i][j];
    for(int i=0;i<n;i++)
    {
        tr[i]=i;
        c[i]=d[i][i];
        d[i][i]=0;
    }

    int cu=0;
    int add=0;
    while(cu!=n-1)
    {
        int mi=1e9;
        pii kk=pii(-1,-1);
        for(int i=0;i<n;i++)
        {
            if(used[i])
                continue;
            for(int j=0;j<n;j++)
            {
                if(!d[i][j])
                    continue;
                if(d[i][j]<mi)
                {
                    mi=d[i][j];
                    kk=pii(i,j);
                }
            }
        }

        vector<int> to_merge;
        to_merge.push_back(kk.f);
        to_merge.push_back(kk.s);
        for(int i=0;i<n;i++)
        {
            if(used[i] || i==kk.s || i==kk.f)
                continue;
            if(!d[i][kk.s])
                continue;
            if(d[i][kk.s]==mi)
                to_merge.push_back(i);
        }

        int nu=n+add;
        c[nu]=mi;
        add++;
        vector<bool> to_mark(n);
        for(auto v : to_merge)
        {
            edges.push_back(pii(tr[v],nu));
            for(int i=0;i<n;i++)
            {
                if(!d[v][i])
                    to_mark[i]=1;
                else if(d[v][i]==mi)
                    to_mark[i]=1;
            }
        }

        for(int i=0;i<n;i++)
            if(to_mark[i])
                d[kk.f][i]=0;
        tr[kk.f]=nu;
        cu+=(to_merge.size()-1);
        for(int i=1;i<to_merge.size();i++)
            used[to_merge[i]]=1;
    }

    n+=add;
    db(n)
    for(int i=0;i<n;i++)
        cout << c[i] << ' ';
    cout << '\n';
    db(n)
    for(int i=0;i<n-1;i++)
        cout << edges[i].f+1 << ' ' << edges[i].s+1 << '\n';

    return 0;
}