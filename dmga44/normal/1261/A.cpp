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
#define MAXN (ll)(5e5+5)

string s;

int nex(int p,char c)
{
    while(s[p]!=c)
        p++;
    return p;
}

void rev(int l,int r)
{
    int m=(l+r)/2;
    for(int i=l;i<=m;i++)
        swap(s[i],s[l+r-i]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        cin >> s;
        vector<pii> res;
        for(int i=0;i<k-1;i++)
        {
            int p1=nex(2*i,'(');
            rev(2*i,p1);
            res.push_back(pii(2*i,p1));
            int p2=nex(2*i+1,')');
            rev(2*i+1,p2);
            res.push_back(pii(2*i+1,p2));
        }
        int p=2*(k-1);
        for(int i=0;i<n/2-k+1;i++)
        {
            int p1=nex(i+p,'(');
            rev(i+p,p1);
            res.push_back(pii(i+p,p1));
        }

        db(res.size())
        for(auto y : res)
            cout << y.f+1 << ' ' << y.s+1 << '\n';
//        db(s)
    }

    return 0;
}