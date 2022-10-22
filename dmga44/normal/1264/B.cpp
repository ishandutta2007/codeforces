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
#define mod (int)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int sum=a+b+c+d;
    int sa=a+c;
    int sb=b+d;
    vector<int> res(sum);
    vector<int> res2(sum);
    if(sa==sum/2)
    {
        for(int i=a;i<sa;i++)
            res[2*i+1]=2;
        for(int i=0;i<sb;i++)
        {
            res[2*i]=1;
            if(i>=b)
                res[2*i]+=2;
        }
    }
    else if(sb==sum/2)
    {
        for(int i=0;i<sb;i++)
        {
            res[2*i+1]=1;
            if(i>=b)
                res[2*i+1]+=2;
        }
        for(int i=a;i<sa;i++)
            res[2*i]+=2;
    }
    else
    {
        db("NO")
        return 0;
    }

    bool ok=1;
    for(int i=0;i<sum-1;i++)
        ok&=(abs(res[i]-res[i+1])==1);

    if(!ok)
    {
        if(sum%2==0)
            for(int i=0;i<sum/2;i++)
                swap(res[2*i],res[2*i+1]);
    }

    ok=1;
    for(int i=0;i<sum-1;i++)
        ok&=(abs(res[i]-res[i+1])==1);

    if(ok)
    {
        db("YES")
        for(int i=0;i<sum;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    else
        db("NO")

    return 0;
}