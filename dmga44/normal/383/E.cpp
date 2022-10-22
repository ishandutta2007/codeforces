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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1<<24)

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        vector<bool> mk(26);
        for(auto y : s)
            mk[y-'a']=1;
        vector<int> kk;
        for(int i=0;i<26;i++)
            if(mk[i])
                kk.push_back(i);
        for(int j=1;j<(1<<kk.size());j++)
        {
            int b=__builtin_popcount(j);
            int mask=0;
            for(int k=0;k<kk.size();k++)
                if(j&(1<<k))
                    mask|=(1<<kk[k]);
            if(b&1)
                a[mask]++;
            else
                a[mask]--;
        }
    }

    for(int i=0;i<24;i++)
        for(int j=0;j<(1<<24);j++)
            if(j&(1<<i))
                a[j]+=a[j^(1<<i)];

    ll res=0;
    for(int i=0;i<(1<<24);i++)
        res^=((ll)a[i]*(ll)a[i]);
    db(res)

    return 0;
}