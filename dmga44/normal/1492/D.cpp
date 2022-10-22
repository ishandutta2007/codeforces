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
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b,k;
    cin >> a >> b >> k;
    b--;
    if(min(a,b)==0 || k==0)
    {
        if(k==0)
        {
            db("Yes")
            for(int i=0;i<=b;i++)
                cout << '1';
            for(int i=0;i<a;i++)
                cout << '0';
            cout << '\n';
            for(int i=0;i<=b;i++)
                cout << '1';
            for(int i=0;i<a;i++)
                cout << '0';
            cout << '\n';
        }
        else
            db("No")
        return 0;
    }

    if(k>=a+b)
    {
        db("No")
        return 0;
    }

    string bb(a+b+1,'1');
    for(int i=0;i<bb.size();i++)
    {
        if(i==k)
            continue;
        if(a==0)
            continue;
        bb[i]='0';
        a--;
    }
    string aa=bb;
    swap(aa[0],aa[k]);
    reverse(all(bb));
    reverse(all(aa));
    db("Yes")
    db(bb)
    db(aa)

    return 0;
}