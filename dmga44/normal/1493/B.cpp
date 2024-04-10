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
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int h,m;

bool ok(int t)
{
    int h0=t/m;
    int m0=t%m;
    int d1=h0/10;
    int d2=h0%10;
    int d3=m0/10;
    int d4=m0%10;
    vector<int> ds;
    ds.push_back(d1);
    ds.push_back(d2);
    ds.push_back(d3);
    ds.push_back(d4);
    bool res=1;
    vector<int> nds;
    for(auto v : ds)
    {
        if(v==3 || v==4 || v==6 || v==7 || v==9)
            res=0;
        if(v==0)
            nds.push_back(0);
        if(v==1)
            nds.push_back(1);
        if(v==2)
            nds.push_back(5);
        if(v==5)
            nds.push_back(2);
        if(v==8)
            nds.push_back(8);
    }
    if(!res)
        return 0;

    int h1=nds[3]*10+nds[2];
    int m1=nds[1]*10+nds[0];
    res&=(h1<h);
    res&=(m1<m);
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
        cin >> h >> m;
        string s;
        cin >> s;
        int h0=(s[0]-'0')*10+(s[1]-'0');
        int m0=(s[3]-'0')*10+(s[4]-'0');
        int t=h0*m+m0;
        while(!ok(t))
            t=(t+1)%(h*m);
        h0=t/m;
        m0=t%m;
        cout << (char)(h0/10+'0') << (char)(h0%10+'0') << ':' << (char)(m0/10+'0') << (char)(m0%10+'0') << '\n';
    }

    return 0;
}