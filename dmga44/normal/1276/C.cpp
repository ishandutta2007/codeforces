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
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll sum[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int,int> fs;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        fs[x]++;
    }

    vector<pii> ee;
    for(auto y : fs)
    {
        sum[y.s]++;
        ee.push_back(pii(y.s,y.f));
    }
    sort(allr(ee));

    for(int i=MAXN-2;i>=1;i--)
        sum[i]+=sum[i+1];

    for(int i=2;i<MAXN;i++)
        sum[i]+=sum[i-1];


    int mul=1;
    pii res=pii(1,1);
    for(int w=1;w<=n;w++)
    {
        ll ma=n/w;
        ll h=0;
        for(int po=(1<<19);po;po>>=1)
        {
            int len=h+po;
            if(len<=ma && sum[min(len,w)]>=len*w)
                h=len;
        }
        if(mul<w*h)
        {
            mul=h*w;
            res=pii(w,h);
        }
    }

    db(mul)
    int w=res.f;
    int h=res.s;
    cout << w  << ' ' << h << '\n';
    vector<vector<int> > m(w,vector<int>(h));
    vector<int> a;
    for(auto y : ee)
        for(int i=0;i<min((int)y.f,min(w,h)) && a.size()<mul;i++)
            a.push_back(y.s);

    if(w<=h)
    {
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            {
                int p=i*w+j;
                m[j][(i+j)%h]=a[p];
            }
    }
    else
    {
        for(int i=0;i<w;i++)
            for(int j=0;j<h;j++)
            {
                int p=i*h+j;
                m[(i+j)%w][j]=a[p];
            }
    }

    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
            cout << m[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}