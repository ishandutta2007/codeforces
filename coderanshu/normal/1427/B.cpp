#include<bits/stdc++.h>
using namespace std ;

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

const int M=1000000007;
const int MM=998244353;
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

int _runtimeTerror_()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i=0;
    while(i<n && s[i]=='L')
        ++i;
    if(i==n)
    {
        if(k==0)
            cout<<"0\n";
        else
            cout<<2*k-1<<"\n";
        return 0;
    }
    int j = n-1;
    while(j>=0 && s[j]=='L')
        --j;
    ll ans = 0;
    vector<int> x;
    int cnt = 0;
    for(int k=i;k<=j;++k)
    {
        if(s[k]=='W')
        {
            if(cnt)
                x.pb(cnt);
            if(k && s[k-1]=='W')
                ans += 2;
            else
                ++ans;
            cnt = 0;
        }
        else
        {
            ++cnt;
        }
    }
    sort(all(x));
    reverse(all(x));
    while(true)
    {
        if(k==0)
            break;
        if(x.empty())
            break;
        if(x.back()==1)
            ans += 3,x.pop_back();
        else
        {
            --x.back();
            ans += 2;
        }
        --k;
    }
    cnt = i + n-1-j;
    if(k)
        ans += min(k,(ll)cnt)*2;
    cout<<ans<<"\n";
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