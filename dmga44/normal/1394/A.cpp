#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll d,n,m;
    cin >> n >> d >> m;
    vector<ll> a;
    vector<ll> ac(n+1);
    ll sum=0;
    int c1=0;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
        if(x>m)
            c1++;
    }

    sort(allr(a));
    for(int i=0;i<n;i++)
        ac[i+1]=ac[i]+a[i];

    for(ll i=0;i<=c1;i++)
    {
        if(!i)
        {
            if(a[0]>m)
                continue;
            else
            {
                sum=ac[n];
                break;
            }
        }
        bool ok=0;
        for(ll j=0;j<=d;j++)
        {
            ll cant=(i-1)*(d+1)+j+1;
            if(cant>n)
            {
                ok=1;
                break;
            }
            ll add=ac[i];
            int c2=(i-1)*(d)+j;
            if(c2+i<c1)
                continue;
            ll men=c2+i-c1;
            add+=(ac[n-men]-ac[c1]);
            sum=max(sum,add);
//            cout << i << ' ' << j << ' ' << add << ' ' << cant << '\n';
        }
        if(ok)
            break;
    }
    db(sum)

    return 0;
}
/**
5 2 11
8 10 15 23 5
**/