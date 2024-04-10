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
    #define MOD 998244353
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
ll n1=200005;
ll mark[200005+1]={0};
vector<pair<ll,ll>>v[200005+1];
vector<ll>dd;
ll ans[200005+1]={0};
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
        ll n,m;
        cin>>n>>m;
        rep(i,m)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            c=c*2;
            // debug(c);
            v[a].pb(mp(b,c));
            v[b].pb(mp(a,c));
        }
        set<pair<ll,ll>>v1;
        rep(i,n)
        {
            ll x;
            cin>>x;
            ans[i+1]=x;
            v1.insert(mp(x,i+1));
        }
        while(!v1.empty())
        {
            ll x=(*v1.begin()).ff;
            ll y=(*v1.begin()).ss;
            // debug(x);
            // debug(y);
            v1.erase(v1.begin());
                swap(x,y);
            for(auto z:v[x])
            {
                if(ans[z.ff]>y+z.ss)
                {
                    v1.erase(mp(ans[z.ff],z.ff));
                    v1.insert(mp(z.ss+y,z.ff));
                    ans[z.ff]=z.ss+y;
                }
            }
        }
        rep(i,n)
        {
            cout<<ans[i+1]<<' ';
        }



                return 0;
    }