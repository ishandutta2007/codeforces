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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

int ask(string q,int i,int j)
{
    cout << q << ' ' << i+1 << ' ' << j+1 << '\n';
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int xors[MAXN];
int n;

void solve(int b,vector<int> v)
{
    if((1<<(b+1))==n)
    {
        int x=ask("AND",v[0],v[1]);
        if(x&(1<<b))
            x^=(1<<b);
        int top=xors[v[0]]^x;
//        db(top)
        for(int i=0;i<n;i++)
            xors[i]^=top;
        return ;
    }
    vector<int> m[2];
    for(auto p : v)
    {
        if(xors[p]&(1<<b))
            m[1].push_back(p);
        else
            m[0].push_back(p);
    }

    if(m[1].size()>m[0].size())
    {
        solve(b+1,m[1]);
        return;
    }
    solve(b+1,m[0]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<n;i++)
        xors[i]=ask("XOR",0,i);

    vector<int> tot;
    for(int i=0;i<n;i++)
        tot.push_back(i);

    solve(0,tot);

//    cout << "!";
//    for(int i=0;i<n;i++)
//        cout << ' ' << xors[i];
//    cout << '\n';
    int b=0;
    while((1<<b)<n)
        b++;
    b--;

    vector<int> m[2];
    for(int i=0;i<n;i++)
    {
        if(xors[i]&(1<<b))
            m[1].push_back(i);
        else
            m[0].push_back(i);
    }

    pii kk;
    if(m[0].size()>1)
        kk=pii(m[0][0],m[0][1]);
    else
        kk=pii(m[1][0],m[1][1]);

    int x=ask("AND",kk.f,kk.s);
    x&=(1<<b);
    int top=(xors[kk.f]^x)&(1<<b);
    for(int i=0;i<n;i++)
        xors[i]^=top;

    cout << "!";
    for(int i=0;i<n;i++)
        cout << ' ' << xors[i];
    cout << '\n';

    return 0;
}