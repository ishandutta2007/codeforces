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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    vector<int> l(n);
    vector<int> r(n);
    for(int i=1;i<n;i++)
        if(a[i]>a[i-1])
            l[i]=l[i-1]+1;
    for(int i=n-2;i>=0;i--)
        if(a[i]>a[i+1])
            r[i]=r[i+1]+1;
    int ma=0;
    for(int i=0;i<n;i++)
        ma=max(ma,max(l[i],r[i]));

    vector<pii> pos;
    for(int i=0;i<n;i++)
    {
        if(l[i]==ma)
            pos.push_back(pii(i-l[i],0));
        if(r[i]==ma)
            pos.push_back(pii(i+r[i],1));
    }

    int res=0;
    for(int i=0;i<n;i++)
        if(r[i]==l[i] && l[i]==ma && ma%2==0)
        {
            if(pos.size()==2)
                res++;
        }
    db(res)

    return 0;
}
/**
9
1 2 5 4 3 6 9 8 7
**/