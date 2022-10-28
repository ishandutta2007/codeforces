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
vector<int> zFunction(string &s)
{
    int n=sz(s),l,r,i;
    vector<int> z(n);
    z[0]=n;
    l=r=0;
    for(i=1;i<n;++i)
    {
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[z[i]+i])
            ++z[i];
        if(i+z[i]-1>r)
        {
            l=i;r=i+z[i]-1;
        }
    }
    return z;
}
string s,t;
int _runtimeTerror_()
{
    //cout<<(int)('_');
    getline(cin,s);
    getline(cin,t);
    string u=t;
    int len1=sz(s),len2=sz(t);
    // /cout<<len1<<endl;
    if(len1!=len2)
    {
        cout<<"-1 -1";return 0;
    }
    reverse(all(u));
    u=u + "0" + s;
    vector<int> v1=zFunction(u);
    string v=t+s;
    vector<int> v2=zFunction(v);
    string w=s;
    reverse(all(w));
    w=w + "0" + t;
    vector<int> v3=zFunction(w);
    int l=v1[len2+1];
    //cout<<l<<endl;
    if(l==0){
        cout<<"-1 -1";return 0;
    }
    if(l==len1)
    {
        if(len1==1)
        {
            cout<<"-1 -1";return 0;
        }
        cout<<len1-2<<" "<<len1-1;return 0;
    }
    for(int i=l;i>=0;--i)
    {
        int x=v2[len2+i];
        //cout<<len2+i+1<<endl;
        int y=v3[len1+x+1];
        //cout<<x<<" "<<y<<endl;
        if(x+i+y<len2)
            continue;
        //cout<<x<<" "<<y<<endl;
        for(int j=0;j<=x;++j)
        {
            int z=v3[len1+j+1];
            if(j+z+i>=len2)
            {
                cout<<i-1<<" "<<i+j;return 0;
            }
        }
    }
    cout<<"-1 -1";
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