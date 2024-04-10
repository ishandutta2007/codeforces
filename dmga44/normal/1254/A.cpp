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
typedef double ld;
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
#define MAXN (ll)(1e2+5)

string a[MAXN];
char res[MAXN][MAXN];

char act(int x)
{
    if(x<26)
        return 'a'+x;
    if(x<52)
        return 'A'+x-26;
    return '0'+x-52;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int r,c,k;
        cin >> r >> c >> k;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                res[i][j]='.';
        int tot=0;
        for(int i=0;i<r;i++)
        {
            cin >> a[i];
            for(int j=0;j<c;j++)
                tot+=(a[i][j]=='R');
        }
        vector<pii> ps;

        for(int i=0;i<r;i++)
        {
            if(i&1)
            {
                for(int j=c-1;j>=0;j--)
                    ps.push_back(pii(i,j));
            }
            else
            {
                for(int j=0;j<c;j++)
                    ps.push_back(pii(i,j));
            }
        }

        int cont=0;
        int c1=tot/k;
        int c2=c1+1;
        int f1=k-(tot%k);
        int f2=k-f1;
        int v=0;
//        db(tot)
//        db(f1)
//        db(f2)
        for(int i=0;i<r*c;i++)
        {
            v+=(a[ps[i].f][ps[i].s]=='R');
            res[ps[i].f][ps[i].s]=act(cont);
            if(c2*f2>v)
                cont=v/c2;
            else
                cont=f2+(((v-(c2*f2)))/c1);
            cont=min(cont,k-1);
        }
        for(int i=0;i<r;i++,cout << '\n')
            for(int j=0;j<c;j++)
                cout << res[i][j];
    }

    return 0;
}