#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
#define MAXN (ll)(1e6+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    if(s.size()==1)
    {
        if(s=="0" || s=="X" || s=="_")
            db(1)
        else
            db(0)
        return 0;
    }
    if(s[0]=='0')
    {
        db(0)
        return 0;
    }
    if(s.size()==2)
    {
        if(s=="XX")
        {
            db(0)
            return 0;
        }
        int ans=0;
        if((s[0]=='2' || s[0]=='X' || s[0]=='_') && (s[1]=='5' || s[1]=='X' || s[1]=='_'))
            ans++;
        if((s[0]=='5' || s[0]=='X' || s[0]=='_') && (s[1]=='0' || s[1]=='X' || s[1]=='_'))
            ans++;
        if((s[0]=='7' || s[0]=='X' || s[0]=='_') && (s[1]=='5' || s[1]=='X' || s[1]=='_'))
            ans++;
        db(ans)
        return 0;
    }

    ll mul=1;
    int sz=s.size()-1;
    int m2=10;
    bool hay=0;
    if(s[0]=='X' || s[0]=='_')
    {
        if(s[0]=='_')
            mul=9;
        else
        {
            m2=9;
            hay=1;
        }
    }
    for(int i=1;i<sz-1;i++)
    {
        if(s[i]=='_')
            mul*=10;
        if(s[i]=='X')
            hay=1;
    }

    if(s[sz-1]!='X' && s[sz]!='X' && hay)
        mul*=m2;

    int ans=0;
    if(s[sz-1]=='X' && s[sz]=='X')
    {
        if(s[0]!='X')
            ans=1;
    }
    else
    {
        if((s[sz-1]=='0' || (s[sz-1]=='X' && s[0]!='X') || s[sz-1]=='_') && (s[sz]=='0' || (s[sz]=='X' && s[0]!='X') || s[sz]=='_'))
            ans++;
        if((s[sz-1]=='2' || s[sz-1]=='X' || s[sz-1]=='_') && (s[sz]=='5' || s[sz]=='X' || s[sz]=='_'))
            ans++;
        if((s[sz-1]=='5' || s[sz-1]=='X' || s[sz-1]=='_') && (s[sz]=='0' || (s[sz]=='X' && s[0]!='X') || s[sz]=='_'))
            ans++;
        if((s[sz-1]=='7' || s[sz-1]=='X' || s[sz-1]=='_') && (s[sz]=='5' || s[sz]=='X' || s[sz]=='_'))
            ans++;
    }

    db(ans*mul)

    return 0;
}