#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
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
#define MAXN (ll)(3e5+5)

vector<int> g1[MAXN];
vector<int> g2[MAXN];
int tt;
int l[MAXN],r[MAXN];
int ans;

void dfs2(int u)
{
    l[u]=tt;
    tt++;
    for(auto v : g2[u])
        dfs2(v);
    r[u]=tt-1;
}

void dfs1(int u,set<pip>& s)
{
    pip act=pip(l[u],pii(r[u],u));
    auto it=s.lower_bound(act);
    pip post=pip(1e9,pii(1e9,0));
    pip prev=pip(-1e9,pii(-1e9,0));
    if(it!=s.end())
        post=*it;
    if(it!=s.begin())
    {
        it--;
        prev=*it;
    }
    // db("")
    // cout << u << '\n';
    // for(auto y : s)
    //     cout << y.first << ' ' << y.second.first << ' ' << y.second.second << '\n'; 

    pip to_rem=pip(-1,pii(-1,-1));
    pip to_ins=pip(-1,pii(-1,-1));
    if(prev.second.first>=act.second.first)//contained
    {
        to_rem=prev;
        s.erase(prev);
        to_ins=act;
        s.insert(act);
    }
    else if(post.first>act.second.first)//there is some space
    {
        to_ins=act;
        s.insert(act);
    }
    // cout << to_rem.first << ' ' << to_rem.second.first << ' ' << to_rem.second.second << '\n'; 
    // cout << to_ins.first << ' ' << to_ins.second.first << ' ' << to_ins.second.second << '\n';

    ans=max(ans,(ll)s.size());

    for(auto v : g1[u])
        dfs1(v,s);
    
    if(to_ins.first!=-1)
        s.erase(to_ins);
    if(to_rem.first!=-1)
        s.insert(to_rem);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=1;i<n;i++)
        {
            int p;
            cin >> p;
            p--;
            g1[p].push_back(i);
        }
        for(int i=1;i<n;i++)
        {
            int p;
            cin >> p;
            p--;
            g2[p].push_back(i);
        }

        dfs2(0);

        set<pip> s;
        dfs1(0,s);

        db(ans)

        for(int i=0;i<n;i++)
        {
            g1[i].clear();
            g2[i].clear();
        }
        tt=0;
        ans=0;
    }

    return 0;
}