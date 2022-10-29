// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
#define MOD 1000000007
#define EPS 1e-7
// #define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb emplace_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef bhartiya
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }




vector<ll>v[100005];
ll cnt[100005];
ll vis[100005];
ll rem[100005];
void solve()
{
    ll n,x,y;
    cin>>n>>x>>y;
    rep(i,n+5)
    {
        vis[i]=0;
        cnt[i]=0;
        rem[i]=0;
        v[i].clear();
    }
    vector<ll>ans;
    rep(i,n)
    {
        ll z;
        cin>>z;
        ans.pb(z);
        cnt[z]++;
        v[z].pb(i);
    }
    set<pair<ll,ll>>s,s1;
    rep(i,n+2)
    {
        if(v[i].size()!=0)
        {
            s.insert(mp(v[i].size(),i));
        }
    }
    ll x1=x;
    while(x1--)
    {
        auto z=*s.rbegin();
        vis[v[z.ss][z.ff-1]]=1;
        cnt[z.ss]--;
        s.erase(z);
        z.ff--;
        s.insert(z);
    }


    // rep(i,n)
    // {
    //     trace(vis[i]);
    // }
    
    vector<ll>re;
    x1=n-y;
    s1=s;
    // trace(x1);
    while(x1!=0)
    {
        auto z=*s.rbegin();
        s.erase(z);
        ll z1=min(x1,z.ff);
        // trace(z,x1,z.ff,z1);
        z.ff-=z1;
        x1-=z1;
        cnt[z.ss]-=z1;
        // trace(cnt[z.ss]);
        rem[z.ss]=1;
    }


    // trace(cnt[1]);
    // trace(cnt[3]);
    // trace(cnt[2]);
    s=s1;
    queue<ll>q;
    ll left=0, k=-1;
    while(!s.empty())
    {
        auto z=*s.rbegin();
        // trace(z);
        s.erase(z);
        if(k==-1)
        {
            k=z.ss;
            left=cnt[z.ss];
        }
        else 
        {
            while(cnt[z.ss]--)
            {
                ll bt=q.front();
                q.pop();
                ans[bt]=z.ss;
                vis[bt]=1;
                // trace(z.ss);
                // trace(z.ff);
                // trace(bt);
            }
        }
        while(z.ff--)
        {
            q.push(v[z.ss][z.ff]);
        }
    }
    // trace(left,k);
    while(left--)
    {
        while(1)
        {
            if(q.empty())
            {
                cout<<"NO"<<endl;
                return;
            }
            ll bt=q.front();
            q.pop();
            if(ans[bt]!=k)
            {
                ans[bt]=k;
                vis[bt]=1;
                break;
            }
        }
    }
    // trace(ans);
    rep(i,n+1)
    {
        if(rem[i+1]==0)
        {
            re.pb(i+1);
        }
    }
    if(re.empty())
    {
        cout<<"NO"<<endl;
        return;
    }
    rep(i,n)
    {
        if(vis[i]==0)
        {
            ll bt=ans[i];
            if(re[0]==bt)
            {
                if(re.size()==1)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                else
                {
                    ans[i]=re[1];
                }
            }
            else
            {
                ans[i]=re[0];
            }
        }
    }
    cout<<"YES"<<endl;
    for(auto z: ans)
    {
        cout<<z<<' ';
    }
    cout<<endl;


}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    fr(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}