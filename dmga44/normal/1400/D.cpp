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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(4e18)
#define pi acos(-1)
#define MAXN (ll)(3e3+5)

struct ABI{
    vector<int> abi;
    int n;
    ABI(int n) : n(n),abi(n) {}

    int query(int p)
    {
        int res=0;
        while(p)
        {
            res+=abi[p];
            p-=(p&-p);
        }
        return res;
    }

    int query(int l,int r)
    {
        return query(r+1)-query(l);
    }

    void update(int p,int v)
    {
        p++;
        while(p<n)
        {
            abi[p]+=v;
            p+=(p&-p);
        }
    }
};

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
        vector<int> a(n);
        ABI abi(MAXN);
        for(int i=0;i<n;i++)
            cin >> a[i];

        ll res=0;
        for(int i=0;i<n;i++)
        {
//            db(i)
            for(int j=i+2;j<n;j++)
                if(a[i]==a[j])
                    res+=abi.query(i+1,j-1);
            for(int j=i+2;j<n;j++)
                if(a[i]==a[j])
                    abi.update(j,1);
        }
        db(res)
    }

    return 0;
}