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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll aux(vector<ll> a,ll d)
{
    if(a.empty())
        return 1;
    int n=a.size();

    ll sum=0;
    for(auto x : a)
        sum+=x;
    sum+=d;
    ll lim=(sum-1)/2;

    vector<ll> ac[2];
    ac[0].push_back(0);
    ac[1].push_back(0);
    for(int i=0;i<n;i++)
        ac[i&1].push_back(a[i]);
    for(int i=0;i<2;i++)
        for(int j=1;j<ac[i].size();j++)
            ac[i][j]+=ac[i][j-1];

//    db(lim)
//    for(auto x : a)
//        cout << x << ' ';
//    cout << '\n';

    sum=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>lim)
            break;
        int l=(i>>1)+1;
        int r=l;
        for(int po=(1<<17);po;po>>=1)
            if(r+po<ac[i&1].size() && ac[i&1][r+po]-ac[i&1][l]+sum<=lim)
                r+=po;
        ll ads=r-l;
        ans+=ads+1;
//        db(i)
//        db(ads+1)

        if(i<=n-4)
        {
            sum+=a[n-1];
            if(sum<=lim)
            {
                r=l;
                for(int po=(1<<17);po;po>>=1)
                    if(r+po<ac[i&1].size() && ac[i&1][r+po]-ac[i&1][l]+sum<=lim && i+2*(r+po-l)<=n-4)
                        r+=po;
                ll ads=r-l;
                ans+=ads+1;
//                db(ads+1)

            }
            sum-=a[n-1];
        }
//        db("xxx")
    }
//    db(ans)
//    db("")
    return ans;
}

ll solve(vector<ll> a)
{
    if(a.size()==1)
        return 1;
    ll ans=aux(a,0);
    auto ca=a;
    reverse(all(ca));
    ca.pop_back();
    reverse(all(ca));
    ans+=aux(ca,a[0]);

    ll sum=0;
    for(auto x : a)
        sum+=x;
    ll lim=(sum-1)/2;
    if(a.size()>=2)
    {
        ll s2=0;
        int p=a.size();
        while(s2<=lim && p>1)
        {
            ans++;
            p--;
            s2+=a[p];
        }
    }

    return ans%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        db(solve(a))
    }

    return 0;
}