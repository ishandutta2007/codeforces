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
#define INT_SIZE 32 
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
        ll n,m,k;
        cin>>n>>m>>k;
        vector<string>v;
        ll o=0;
        ll ans=m*n;
        rep(i,n)
        {
            string s1,s="";
            cin>>s1;

            ll l=0,r=m-1;
            while(l<m&&s1[l]=='0')
            {
                l++;
            }
            while(r>=0&&s1[r]=='0')
                r--;
            // debug(l);
            // debug(r);
            for(ll j=l;j<=r;j++)
            {
                s=s+s1[j];
                if(s1[j]=='1')
                    o++;
            }
            v.pb(s);
            // debug(s);
            ans-=m-s.length();
        }       
        // debug(o); 
        if(o<=k)
        {
            cout<<0;
            return 0;
        }
        while(k>0)
        {
            ld eff=0;
            ll st=-1;
            ll dir=0;
            ll k1=0;
            rep(i,n)
            {
                string s=v[i];
                ll sk=0,t=0;
                m=s.length();
                rep(j,m)
                {
                    if(s[j]=='1')
                    {
                        if(t>0)
                        {
                            if(sk*1.0/t>=eff)
                            {
                                eff=sk*1.0/t;
                                st=i;
                                dir=1;
                                k1=t;
                            }
                        }
                        t++;
                        if(t>k)
                        {
                            break;
                        }
                    }

                        sk++;
                }
                if(t<=k)
                {
                    if(t>0)
                    {
                        if(sk*1.0/t>=eff)
                        {
                            eff=sk*1.0/t;
                            st=i;
                            dir=1;
                            k1=t;
                        }
                    }
                }
                sk=0,t=0;
                for(ll j=m-1;j>=0;j--)
                {
                    if(s[j]=='1')
                    {
                        if(t>0)
                        {
                            if(sk*1.0/t>=eff)
                            {
                                eff=sk*1.0/t;
                                st=i;
                                dir=-1;
                                k1=t;
                            }
                        }
                        t++;
                        if(t>k)
                        {
                            break;
                        }
                    }
                    sk++;
                }

            }
            k-=k1;
            ans-=(ll)(eff*k1+0.1);
            string s=v[st],s1="";
            ll z=0;
            if(dir==1)
            {
                rep(i,s.length())
                {
                    if(s[i]=='1')
                        z++;
                }
                if(z==k1)
                    v[st]=  "";
                else
                {
                    ll l=0;
                    z=0;
                    while(l<s.length())
                    {
                        if(s[l]=='1')
                            z++;
                        if(z>k1)
                        {
                            break;
                        }
                        l++;
                    }
                    for(ll i=l;i<s.length();i++)
                    {
                        s1=s1+s[i];
                    }
                    v[st]=s1;
                }
            }
            else
            {
                ll l=s.length()-1;
                z=0;
                while(l>=0)
                {
                    if(s[l]=='1')
                        z++;
                    if(z>k1)
                    {
                        break;
                    }
                    l--;
                }
                rep(i,l+1)
                {
                    s1=s1+s[i];
                }
                v[st]=s1;
            }
        }
        cout<<ans;

            return 0;
}