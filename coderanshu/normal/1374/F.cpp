#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
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
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}
void shift(vector<int> &a,int idx)
{
    swap(a[idx+2],a[idx+1]);
    swap(a[idx+1],a[idx]);
}
int _runtimeTerror_()
{
    ll n;
    cin>>n;
    vector<int> a(n+1),b;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    b=a;
    sort(all(b));
    vector<int> ans;
    for(int i=1;i<=n-2;++i)
    {
        if(a[i]==b[i])
            continue;
        for(int j=i+1;j<=n;++j)
        {
            if(b[i]==a[j])
            {
                int cur=j-2;
                for(int k=cur;k>=i;k-=2)
                {
                    ans.pb(k);
                    shift(a,k);
                }
                if((j-i)%2==1)
                {
                    ans.pb(i);ans.pb(i);
                    shift(a,i);
                    shift(a,i);
                }
            }
        }
    }
    if(a!=b && a[n-2]==a[n])
        ans.pb(n-2),shift(a,n-2);
    if(a!=b)
    {
        int idx=-1;
        for(int i=1;i<=n-2;++i)
        {
            if(a[i]==a[i-1])
            {
                idx=i;break;
            }
        }
        if(idx==-1)
        {
            cout<<"-1\n";return 0;
        }
        for(int i=n-2;i>=idx-1;--i)
            ans.pb(i);
    }
    cout<<sz(ans)<<'\n';
    for(auto k:ans)
        cout<<k<<' ';
    cout<<'\n';
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}