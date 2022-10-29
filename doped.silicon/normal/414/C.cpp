    #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
    #include <bits/stdc++.h>

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
    #define ll long long
    #define ld double
    #define ui unsigned int
    #define all(ar) ar.begin(), ar.end()
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define y0 yyyyyy0
    auto clk=clock();
    #define y1 yyyyyy1

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
    template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}
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
    #define INF 1000000000000000000
    #define EPS 1e-7
    #define MAXN 100000
    #define MOD 1000000007
    #define dec decr
    //END OF COMPETITVE PROGRAMMING TEMPLATE
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
            if (y & 1)    
                res = (res*x) % p;
            y = y>>1;     
            x = (x*x) % p; 
        }
        return res;
    }
map<ll,ll>ma;
vector<ll>v;
ll f=1;
long long rev[22];
long long inv[22];
bool ivt[22];
void merge(ll l,ll m,ll r)
{
    // debug(l);
    // debug(r);
    vector<ll>v1;
    ll an=0;
    ll p1=0,p2=0,a=l,b=m+1;
    ll z=(r-l+1)/2;
    // debug(a);
    // debug(b);
    // rep(i,4)
    // {
    //     debug(v[i]);
    // }
    while(p1<z&&p2<z)
    {

        if(v[p1+a]<=v[p2+b])
        {
            v1.pb(v[p1+a]);
            p1++;
        }
        else
        {
            v1.pb(v[p2+b]);
            an+=z-p1;
            // debug(an);
            p2++;
        }
        // debug(p1);
        // debug(p2);
    }
    while(p1<z)
    {
        v1.pb(v[p1+a]);
        p1++;
    }
    while(p2<z)
    {
        v1.pb(v[p2+b]);
        p2++;
    }
    for(ll i=l;i<=r;i++)
    {
        v[i]=v1[i-l];
        // debug(v1[i-l]);
    }
    ll zz=ma[r-l+1];
    // debug(zz);
    // cout<<endl;
    if(f)
    inv[zz]+=an;
    else
        rev[zz]+=an;
}
void ms(ll l,ll r)
{
    if(l>=r)
        return;
    ll z=r-l+1;
    z=z/2;
    ll m=l+z-1;
    ms(l,m);
    ms(m+1,r);
    merge(l,m,r);
    
}
int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(9);
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    ll k=1;
    f=1;
    ma[1]=0;
    rep(i,n)
    {
        k*=2;
        ma[k]=i+1;
    }
    n=k;
    vector<ll>v1;
    rep(i,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    v1=v;
    ms(0,n-1);
    v=v1;
    reverse(all(v));
    // rep(i,n)
    // {
    //     debug(v[i]);
    // }
    f=0;
    ms(0,n-1);
    ll kx;
    cin>>kx;
    // kx=1000000;
    n=ma[n];
    rep(i,n)
    {
        // cout<<i+1<<endl;
        // cout<<inv[i+1]<<endl;
        // cout<<rev[i+1]<<endl;
        // cout<<endl;
    }
    rep(ix,kx)
    {
        ll q;
        cin>>q;
        // q=20;
        for(ll i=1;i<=q;i++)
        {
            ivt[i]=(ivt[i]+1)%2;
        }
        long long ans=0;
        rep(i,n)
        {
            if(ivt[i+1])
                ans+=rev[i+1];
            else
            {
                ans+=inv[i+1];
            }
        }
        cout<<ans<<'\n';
    }
    // cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;


    return 0;
}