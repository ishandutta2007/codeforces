#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
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
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll solve(int l,int r,vector<int>& a)
{
    if(l==r)
        return 1;

    int mid=(l+r)>>1;
    
    ll ans=solve(l,mid,a)+solve(mid+1,r,a);

    vector<pii> bestr;
    bestr.push_back(pii(a[mid+1],a[mid+1]));
    for(int i=mid+2;i<=r;i++)
    {
        ll mi=bestr.back().first;
        ll ma=bestr.back().second;
        bestr.push_back(pii(min(mi,a[i]),max(ma,a[i])));
    }

    vector<int> ac;
    ac.push_back(0);
    for(int i=0;i<bestr.size();i++)
        ac.push_back(ac.back()+(__builtin_popcountll(bestr[i].first)==__builtin_popcountll(bestr[i].second)));

    ll mi=a[mid],ma=a[mid];
    int p_i=0,p_a=0;
    vector<int> fi_a(60);
    vector<int> fi_i(60);
    vector<int> fa_a(60);
    vector<int> fa_i(60);
    for(int i=mid;i>=l;i--)
    {
        mi=min(a[i],mi);
        ma=max(a[i],ma);

        while(p_i<bestr.size() && bestr[p_i].first>mi)
        {
            fi_i[__builtin_popcountll(bestr[p_i].first)]++;
            fi_a[__builtin_popcountll(bestr[p_i].second)]++;
            p_i++;
        }
        while(p_a<bestr.size() && bestr[p_a].second<ma)
        {
            fa_i[__builtin_popcountll(bestr[p_a].first)]++;
            fa_a[__builtin_popcountll(bestr[p_a].second)]++;
            p_a++;
        }

        ans+=(__builtin_popcountll(mi)==__builtin_popcountll(ma))*min(p_a,p_i);
        ans+=(ac.back()-ac[max(p_a,p_i)]);
        
        if(p_i<p_a)
        {
            ans+=fa_i[__builtin_popcountll(ma)]-fi_i[__builtin_popcountll(ma)];
        }
        else
        {
            ans+=fi_a[__builtin_popcountll(mi)]-fa_a[__builtin_popcountll(mi)];
        }
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << solve(0,n-1,a) << '\n';

    return 0;   
}