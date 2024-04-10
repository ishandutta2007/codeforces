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
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

#define bsz (ll)(250)

struct bucket
{
    int32_t abi[MAXN];
    int plus;

    void update(int p,int v)
    {
        p++;
        while(p<MAXN)
        {
            abi[p]=(abi[p]+v+mod)%mod;
            p+=(p&-p);
        }
    }

    int query(int p)
    {
        p++;
        int ans=0;
        while(p)
        {
            ans=(ans+abi[p])%mod;
            p-=(p&-p);
        }
        return ans;
    }

    int cant(int k)
    {
        int pos=k-plus;
        if(pos<0)
            return 0;
        if(pos>MAXN)
            pos=MAXN-2;
        return query(pos);
    }
};

bucket buckets[405];

void update(vector<int>& vals,vector<int>& a, int l,int r,int v)
{
    if(l/bsz==r/bsz)
    {
        for(int i=l;i<=r;i++)
        {
            buckets[i/bsz].update(a[i],(mod-vals[i])%mod);
            a[i]+=v;
            buckets[i/bsz].update(a[i],+vals[i]);
        }
    }
    else
    {
        // cout << "xxx\n";
        // cout << buckets[l/bsz].query(2) << '\n';
        for(int i=l;i/bsz==l/bsz;i++)
        {
            buckets[i/bsz].update(a[i],(mod-vals[i])%mod);
            a[i]+=v;
            buckets[i/bsz].update(a[i],+vals[i]);
        }
        // cout << buckets[l/bsz].query(2) << '\n';

        for(int i=(l/bsz)+1;i<r/bsz;i++)
            buckets[i].plus+=v;

        for(int i=r;i/bsz==r/bsz;i--)
        {
            buckets[i/bsz].update(a[i],(mod-vals[i])%mod);
            a[i]+=v;
            buckets[i/bsz].update(a[i],+vals[i]);
        }
    }
}

int query(vector<int>& vals,vector<int>& a, int p,int k)
{
    ll ans=0;
    for(int i=0;i<p/bsz;i++)
        ans+=buckets[i].cant(k);
    // cout << "ans:" << ans << '\n';
    for(int i=p;i/bsz==p/bsz && i>=0;i--)
        if(a[i]<=k)
        {
            // cout << i << ' ' << a[i] << ' ' << vals[i] << '\n';
            ans+=vals[i];
        }
    return ans%mod;
}

vector<int> pos[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        pos[i].push_back(-1);
    vector<int> vals(n+1);
    vals[0]=1;
    buckets[0].update(0,1);
    vector<int> a(n+1);

    // db("xxx")

    ll xxx=1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        x--;
        // x=i;
        if(pos[x].size()>1)
            update(vals,a,pos[x][pos[x].size()-2]+1,pos[x].back(),-1);
        update(vals,a,pos[x].back()+1,i,+1);
        pos[x].push_back(i);
        vals[i+1]=query(vals,a,i,k);
        // if(i)
        //     xxx=(xxx+xxx)%mod;
        // db(i)
        // cout << buckets[0].plus << ' ' << i+1 << ' ' << vals[i+1] << '\n';
        // if(xxx!=vals[i+1])
        // {
        //     cout << vals[i+1] << ' ' << xxx << '\n';
        //     cout << i+1 << '\n';
        //     break;
        // }
        buckets[(i+1)/bsz].update(0,vals[i+1]);
    }
    cout << vals[n] << '\n';

    return 0;   
}