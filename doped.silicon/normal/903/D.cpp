#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;
#define ll unsigned long long
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
using namespace std;
 
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ld long double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y0 yyyyyy0
auto clk=clock();
#define y1 yyyyyy1
#define setb __builtin_popcount
#define BIT(n) (1<<(n))
#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define LSOne(S) (S) & (-S)
inline bool EQ(double a, double b) {return fabs(a - b) < 1e-9;}
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
 
template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
// template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}
template<typename T> string toStr(T x) {stringstream st; st << x; string s; st >> s; return s;}
template<class T>
void splitStr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
 
inline int two(int n) {return 1 << n;}
inline int isOnBit(int n, int b) {return (n >> b) & 1;}
inline void onBit(int & n, int b) {n |= two(b);}
inline void offBit(int & n, int b) {n &= ~two(b);}
inline int lastBit(int n) {return n & (-n);}
inline int cntBit(int n) {int res = 0; while(n && ++res) n -= n &(-n); return res;}
 
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};
 
#define INP "test.inp"
#define OUT "test.out"
 
#define PI 3.1415926535897932385
#define INF 10000000000000000ll
#define EPS 1e-7
#define MAXN 100000
#define MO 1000000007
#define dec decr
#define endl '\n'
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll modexp(ll x, ll y, ll p)
{
    ll res = 1;   
    x = x % p;  
    while (y > 0)
    {
        if (y %2==1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}

ll n1=200006;
ll bt[200006];
ll bt1[200006];
ll getSum(ll x)
{
    ll sum=0;
    for(;x>=1;x-=(x&-x))
        sum+=bt[x];
    return sum;
}
void update(ll x, ll d)
{
    for(;x<=n1;x+=(x&-x))
    {
        bt[x]+=d;
    }
}
ll getSum1(ll x)
{
    ll sum=0;
    for(;x>=1;x-=(x&-x))
        sum+=bt1[x];
    return sum;
}
void update1(ll x, ll d)
{
    for(;x<=n1;x+=(x&-x))
    {
        bt1[x]+=d;
    }
}
int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(9); 
    #ifdef rg
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    ll ar[n]={0};
    vector<ll>v;
    map<int,int>m;
    rep(i,n)
    {
        cin>>ar[i];
        v.pb(ar[i]);
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    rep(i,v.size())
    {
        m[v[i]]=i+1;
    }
    ll ans=0;
    ll ans1=0;
    rep(i,n)
    {
        ll x=ar[i];
        ll val=m[ar[i]];
        ll z=x-1;
        if(m.count(z)==0)
        {
            ll xx=getSum1(val-1);
            ll xs=getSum(val-1);
            ans+=x*xx-xs;
        }
        else
        {
            ll xx=getSum1(val-2);
            ll xs=getSum(val-2);
            ans+=x*xx-xs;
        }
        if(m.count(x+1)==0)
        {
            ll xx=getSum1(n)-getSum1(val);
            ll xs=getSum(n)-getSum(val);
            ans1+=xs-x*xx;
        }
        else
        {
            ll xx=getSum1(n)-getSum1(val+1);
            ll xs=getSum(n)-getSum(val+1);
            ans1+=xs-x*xx;
        }
        update1(val,1);
        update(val,x);
    }
    if(ans>=ans1)
    {
        cout<<ans-ans1;
    }
    else
    {
        string s1=to_string(ans1);
        string s2=to_string(ans);
        reverse(all(s1));
        reverse(all(s2));
        // debug(s1);
        // debug(s2);
        ll i=0;
        string s="";
        ll c=0;
        while(i<s1.length()+2||i<s2.length()+2)
        {
            ll x1=0,x2=0;
            if(i<s1.length())
            {
                x1=s1[i]-'0';
            }
            if(i<s2.length())
            {
                x2=s2[i]-'0';
            }
            int z=x1-x2-c;
            if(z<0)
            {
                z+=10;
                c=1;
            }
            else
            {
                c=0;
            }
            s+=(char)('0'+z);
            i++;
        }
        reverse(all(s));
        // debug(s);
        i=0;
        while(s[i]=='0')
        {
            // debug(s[i]);
            i++;
        }
        // debug(i);
        cout<<'-';
        for(;i<s.length();i++)
        {
            cout<<s[i];
        }
    }

 
    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}