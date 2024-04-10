#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a)    memset(a,0,sizeof(a))
#define mem1(a)    memset(a,-1,sizeof(a))
#define memf(a)    memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const long double PI = acos(-1);

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
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
        root->freq++;
        for(ll j=30;j>=0;--j)
        {
            ll onoff=n&(1LL<<j);
            onoff=(onoff>0);
            if(temp->child[onoff]==NULL)
                temp->child[onoff]=getnode();
            temp=temp->child[onoff];
            temp->freq++;
        }
    }
    void erase(ll n)
    {
        node *temp=root;
        root->freq--;
        for(ll j=30;j>=0;--j)
        {
            if(n&(1LL<<j))
            {
                temp->child[1]->freq--;
                temp=temp->child[1];
            }
            else
            {
                 temp->child[0]->freq--;
                 temp=temp->child[0];
            }
        }
    }
    ll query(ll n,ll m)
    {
        node *temp=root;
        ll ans=0;
        for(int j=30;j>=0;--j)
        {
            if(n&(1<<j))
            {
                if(m&(1<<j))
                {
                    if(temp->child[1])
                        ans+=temp->child[1]->freq;
                    if(temp->child[0])
                        temp=temp->child[0];
                    else break;
                }
                else
                {
                    if(temp->child[1])
                        temp=temp->child[1];
                    else break;
                }
            }
            else
            {
                if(m&(1<<j))
                {
                    if(temp->child[0])
                        ans+=temp->child[0]->freq;
                    if(temp->child[1])
                        temp=temp->child[1];
                    else break;
                }
                else
                {
                     if(temp->child[0])
                        temp=temp->child[0];
                    else break;
                }
            }
        }
        return ans;
    }
}trie;

int _runtimeTerror_()
{
    ll q;
    cin>>q;
    while(q--)
    {
        int tt;
        ll p,l;
        cin>>tt>>p;
        if(tt==1)
            trie.insert(p);
        else if(tt==2)
            trie.erase(p);
        else
        {
            ll l;
            cin>>l;
            cout<<trie.query(p,l)<<endl;
        }
    }
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
    cerr<<"\n"<<_time_;
    return 0;
}