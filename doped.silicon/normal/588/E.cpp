#pragma GCC optimize("Ofast")
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp> // Common file  
    #include <ext/pb_ds/tree_policy.hpp>  
    #include <functional> // for less  
    #include <iostream>  
    using namespace __gnu_pbds;  
    using namespace std;
    #define ll long long
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
    #define MOD 1000000009
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
const int N=100005;
vector<ll>v[100005];
ll tim=1;
ll tin[100005];
ll tout[100005];
ll up[N][20];
vector<ll>iden[N][20];
vector<ll>id[N];
vector<ll>t1,t2;
void merge(vector<ll>a,vector<ll>b,vector<ll>&c)
{
	ll n1=a.size();
	ll n2=b.size();
	ll p1=0,p2=0;
	while(c.size()<=10&&(p1<n1||p2<n2))
	{
		if(p1==n1)
		{
			c.pb(b[p2]);
			p2++;
		}
		else if(p2==n2)
		{
			c.pb(a[p1]);
			p1++;
		}
		else
		{
			if(a[p1]<b[p2])
			{
				c.pb(a[p1]);
				p1++;
			}
			else
			{
				c.pb(b[p2]);
				p2++;
			}
		}
	}
	// debug(c.size());
}
void dfs(ll x,ll p)
{
	tin[x]=tim++;
	up[x][0]=p;
	for(ll i=1;i<=19;i++)
	{
		up[x][i]=up[up[x][i-1]][i-1];
	}
	iden[x][0]=id[p];
	// debug(id[p].size());
	// debug(x);
	for(ll i=1;i<=19;i++)
	{
		vector<ll>f1;
		ll z=up[x][i-1];
		if(z!=0)
		merge(iden[x][i-1],iden[z][i-1],f1);
		else
		{
			f1=iden[x][i-1];
		}
		iden[x][i]=f1;
		// debug(i);
		// debug(iden[x][i-1].size());
		// debug(f1.size());
		// for(auto zz:f1)
		// {
		// 	debug(zz);
		// }
	}
	// cout<<endl;
	for(auto z:v[x])
	{
		if(z!=p)
		{
			dfs(z,x);
		}
	}
	tout[x]=tim++;
}
bool isan(ll x,ll y)
{
    return tin[x]<=tin[y]&&tout[y]<=tout[x];
}
ll lca(ll x, ll y)
{
    if(isan(x,y))return x;
    if(isan(y,x))return y;
    for(ll i=19;i>=0;i--)
    {
        if(!isan(up[x][i],y)&&up[x][i]!=0)
        {
            x=up[x][i];
        }
    }
    return up[x][0];
}
void find1(ll x,ll y)
{
	t1.clear();
	t1=id[x];
	if(x==y)
		return;
	// debug(x);
	// debug(y)
	for(ll i=19;i>=0;i--)
	{
		if(!isan(up[x][i],y)&&up[x][i]!=0)
        {
        	vector<ll>f1;
        	merge(t1,iden[x][i],f1);
        	t1=f1;
            x=up[x][i];
        }
	}
	x=up[x][0];
	// debug(x);
	// debug(t1.size());
	vector<ll>f1;
	merge(t1,id[x],f1);
	t1=f1;
}
void find2(ll x,ll y)
{
	t2.clear();
	if(x==y)
		return;
	t2=id[x];
	for(ll i=19;i>=0;i--)
	{
		if(!isan(up[x][i],y)&&up[x][i]!=0)
        {
        	vector<ll>f1;
        	merge(t2,iden[x][i],f1);
        	t2=f1;
            x=up[x][i];
        }
	}
}
void find(ll x,ll y,ll a)
{
	if(x==y)
	{
		ll k=id[x].size();
		cout<<min(a,k)<<' ';
		for(auto z:id[x])
		{
			cout<<z<<' ';
			a--;
			if(a<=0)
				break;
		}
		cout<<endl;
	}
	else
	{
		// debug(x);
		// debug(y);
		ll lcc=lca(x,y);
		find1(x,lcc);
		find2(y,lcc);
		vector<ll>f1;
		// debug(lca);
		// debug(t1.size());
		// debug(t2.size());
		merge(t1,t2,f1);
		ll k=f1.size();
		cout<<min(a,k)<<' ';
		for(auto z:f1)
		{
			cout<<z<<' ';
			a--;
			if(a<=0)
				break;
		}
		cout<<endl;	
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
    ll n,m,q;
    cin>>n>>m>>q;
    rep(i,n-1)
    {
    	ll x,y;
    	cin>>x>>y;
    	// x--;
    	// y--;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    rep(i,m)
    {
    	ll x;
    	cin>>x;
    	// x--;
    	id[x].pb(i+1);
    }
    rep(i,n)
    {
    	sort(all(id[i+1]));
    	if(id[i+1].size()>10)
    	{
    		id[i+1].resize(10);
    	}
    }
    dfs(1,0);
    rep(i,q)
    {
    	ll x,y,z;
    	cin>>x>>y>>z;
    	find(x,y,z);
    }

 
 
    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}