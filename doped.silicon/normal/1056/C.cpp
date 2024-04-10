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
#define INF 1000111222
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007
#define dec decr
//END OF COMPETITVE PROGRAMMING TEMPLATE
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
            ll n,m1;
            cin>>n>>m1;
            vector<pair<ll,ll>> p;
            ll m[2*n];
            ll b[2*n];
            vector<pair<ll,ll>> v;
            
            rep(i,2*n)
            {
            	ll px;
            	cin>>px;
            	p.pb(mp(px,i+1));
            	m[i]=-1;
            	b[i]=0;
            }
            rep(i,m1)
            {
            	ll a,b;
            	cin>>a>>b;
            	v.pb(mp(a,b));
            	m[a-1]=b-1;
            	m[b-1]=a-1;
            }
            ll t;
            //cout<<"HI"<<endl;
            cin>>t;
            //debug(t);
            if(t==1)
            {
            	//cout<<"HI"<<endl;
            	rep(i,m1)
            	{
            		ll a,b1;
            		a=v[i].first;
            		b1=v[i].second;
            		p[a-1].second=-1;
            		p[b1-1].second=-1;
            		ll ans;
            		if(p[a-1]>p[b1-1])
            		{
            			ans=a;
            		}
            		else ans=b1;
            		cout<<ans<<endl<<flush;
            		cin>>a;
            		if(a==-1)
            		return 0;
            	}
            	ll x1=p.size();
            	sort(p.begin(),p.end());
            	for(ll i=p.size()-1;i>=0;i--)
            	{
            		if(p[i].second!=-1&&b[p[i].second-1]!=-1)
            		{
            			cout<<p[i].second<<endl<<flush;
            			p[i].second=-1;
            			ll x;
            			cin>>x;
            			//debug(x);
            			if(x==-1)
            			return 0;
            			b[x-1]=-1;
            		}
            	}
            }
            else
            {
            	
            	ll ptr=2*n-1;
            	bool k1=true;
            	ll i1;
            	rep(i,n)
            	{
            		ll xx;
            		cin>>xx;
            		b[xx-1]=-1;
            		p[xx-1].second=-1;
            		
            		while(i<n&&m[xx-1]!=-1&&k1)
            		{
            			cout<<m[xx-1]+1<<endl<<flush;
            			//b[m[xx-1]]=-1;
            			p[m[xx-1]].second=-1;
            			i++;
            			if(i<n)
            			cin>>xx;
            			p[xx-1].second=-1;
            			
            			//b[xx-1]=-1;
            		}
            		rep(j,m1)
            	    {
            	    
            		ll a,b1;
            		a=v[j].first;
            		b1=v[j].second;
            		if(p[a-1].second!=-1)
            		{
            		p[a-1].second=-1;
            		p[b1-1].second=-1;
            		ll ans;
            		if(p[a-1]>p[b1-1])
            		{
            			ans=a;
            		}
            		else ans=b1;
            		cout<<ans<<endl<<flush;
            		i++;
            		if(i<n)
            		cin>>a;
            		if(a==-1)
            		return 0;
            		}
            	    }
            	    i1=i;
            		break;
            	}
            	ll x1=p.size();
            	sort(p.begin(),p.end());
            	for(ll i=p.size()-1;i>=0;i--)
            	{
            		if(p[i].second!=-1&&b[p[i].second-1]!=-1)
            		{
            			cout<<p[i].second<<endl<<flush;
            			p[i].second=-1;
            			i++;
            			
            			ll x;
            			if(i1<n)
            			cin>>x;
            			//debug(x);
            			if(x==-1)
            			return 0;
            			b[x-1]=-1;
            		}
            	}
            }
            return 0;
}