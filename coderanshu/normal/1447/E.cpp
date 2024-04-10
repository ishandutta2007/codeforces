#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

ll ans = 0;

struct node
{
    ll freq;
    node* child[2];
};
node* getnode()
{
    node* ret=new node();
    ret->child[0]=NULL;
    ret->child[1]=NULL;
    ret->freq=0;
    return ret;
}
struct TRIE
{
    node *root;
    TRIE()
    {
        root = getnode();
    }
    void insert(ll n)
    {
        node *temp=root;
        for(ll j=29;j>=0;--j)
        {
            ll onoff=n&(1LL<<j);
            onoff=(onoff>0);
            if(temp->child[onoff]==NULL)
                temp->child[onoff]=getnode();
            temp=temp->child[onoff];
        }
        temp->freq++;
    }
    void dfs(node *r,int cnt=0)
    {
        if(!r)
            return ;
        amax(ans,cnt+r->freq);
        for(int i=0;i<2;++i)
        {
            if(r->child[i])
            {
                int val = 0;
                if(r->child[i^1])
                    ++val;
                dfs(r->child[i],val+cnt);
            }
        }
    }
}tr;

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        tr.insert(x);
    }
    tr.dfs(tr.root,0);
    cout<<n-ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}