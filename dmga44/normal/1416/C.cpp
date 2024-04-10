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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

ll a[MAXN];

ll invv(vector<int>& a)
{
    ll c1=0;
    ll res=0;
    for(auto y : a)
    {
        if(y==0)
            res+=c1;
        else
            c1++;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p;
    for(int i=0;i<n;i++)
        p.push_back(i);
    for(int i=0;i<n;i++)
        cin >> a[i];

    ll inv=0;
    ll r2=0;
    for(int i=29;i>=0;i--)
    {
        vector<pii> mp;
        ll mask=0;
        for(int j=29;j>i;j--)
            mask|=(1<<j);
        for(int j=0;j<n;j++)
            mp.push_back(pii(a[j]&mask,j));
        sort(all(mp));

        ll s1=0;
        ll s2=0;
        int pos=0;
        while(pos<n)
        {
            int ini=mp[pos].f;
            vector<int> pp;
            while(pos<n && mp[pos].f==ini)
            {
                pp.push_back(mp[pos].s);
                pos++;
            }
            if(pp.size()==1)
                continue;
            vector<int> ok;
            for(auto yy : pp)
            {
                if(a[yy]&(1<<i))
                    ok.push_back(1);
                else
                    ok.push_back(0);
            }
            ll v1=invv(ok);
            for(int j=0;j<ok.size();j++)
                ok[j]=1-ok[j];
            ll v2=invv(ok);
            s1+=v1;
            s2+=v2;
        }

        if(s1<=s2)
            inv+=s1;
        else
        {
            inv+=s2;
            r2|=(1<<i);
        }
    }

    cout << inv << ' ' << r2 << '\n';

    return 0;
}