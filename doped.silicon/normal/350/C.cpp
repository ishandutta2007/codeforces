#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}

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
bool sor(const pair<int,int> &a, 
               const pair<int,int> &b)
{
	if(abs(a.first)<abs(b.first))
	return true;
	if(abs(a.first)>abs(b.first))
	return false;
            return (abs(a.second) < abs(b.second));
}

int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            ll n;
            cin>>n;
            vii v1,v2,v3,v4;
            ll ans=0;
            rep(i,n)
            {
               ll a,b;
               cin>>a>>b;
               if(a==0)
               ans-=2;
               if(b==0)
               ans-=2;
               if(a>=0&&b>=0)
               v1.pb(mp(a,b));
               else if(a<=0&&b<=0)
               v2.pb(mp(a,b));
               else if(a<0&&b>0)
               v3.pb(mp(a,b));
               else
               v4.pb(mp(a,b));
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end(),sor);
            sort(v3.begin(),v3.end(),sor);
            sort(v4.begin(),v4.end(),sor);
            //rep(i,v1.size())
            /*cout<<v1[i].first<<" "<<v1[i].second<<'\n';
            rep(i,v2.size())
            cout<<v2[i].first<<" "<<v2[i].second<<'\n';
            rep(i,v3.size())
            cout<<v3[i].first<<" "<<v3[i].second<<'\n';
            rep(i,v4.size())
            cout<<v4[i].first<<" "<<v4[i].second<<'\n';*/
           // cout<<ans<<endl;
            ans+=6*n;
            cout<<ans<<'\n';
            rep(i,v1.size())
            {
            	ll x=v1[i].first;
            	ll y=v1[i].second;
                        if(x!=0)
                        {
                        	if(x>0)
                        	cout<<"1 "<<x<<" R"<<'\n';
                        	else
                        	cout<<"1 "<<abs(x)<<" L"<<'\n';
                        }
                        if(y!=0)
                        {
                        	if(y>0)
                        	cout<<"1 "<<y<<" U"<<'\n';
                        	else
                        	cout<<"1 "<<abs(y)<<" D"<<'\n';
                        }
                        cout<<"2"<<'\n';
                        if(y!=0)
                        {
                        	if(y>0)
                        	cout<<"1 "<<y<<" D"<<'\n';
                        	else
                        	cout<<"1 "<<abs(y)<<" U"<<'\n';
                        }
                        if(x!=0)
                        {
                        	if(x>0)
                        	cout<<"1 "<<x<<" L"<<'\n';
                        	else
                        	cout<<"1 "<<abs(x)<<" R"<<'\n';
                        }
                        
                        cout<<"3"<<'\n';
            }
            rep(i,v2.size())
            {
            	ll x=v2[i].first;
            	ll y=v2[i].second;
                        if(x!=0)
                        {
                        	if(x>0)
                        	cout<<"1 "<<x<<" R"<<'\n';
                        	else
                        	cout<<"1 "<<abs(x)<<" L"<<'\n';
                        }
                        if(y!=0)
                        {
                        	if(y>0)
                        	cout<<"1 "<<y<<" U"<<'\n';
                        	else
                        	cout<<"1 "<<abs(y)<<" D"<<'\n';
                        }
                        cout<<"2"<<'\n';
                        if(y!=0)
                        {
                        	if(y>0)
                        	cout<<"1 "<<y<<" D"<<'\n';
                        	else
                        	cout<<"1 "<<abs(y)<<" U"<<'\n';
                        }
                        if(x!=0)
                        {
                        	if(x>0)
                        	cout<<"1 "<<x<<" L"<<'\n';
                        	else
                        	cout<<"1 "<<abs(x)<<" R"<<'\n';
                        }
                        
                        cout<<"3"<<'\n';
            }
            rep(i,v3.size())
            {
            	ll x=v3[i].first;
            	ll y=v3[i].second;
                        if(x!=0)
                        {
                        	if(x>0)
                        	cout<<"1 "<<x<<" R"<<'\n';
                        	else
                        	cout<<"1 "<<abs(x)<<" L"<<'\n';
                        }
                        if(y!=0)
                        {
                        	if(y>0)
                        	cout<<"1 "<<y<<" U"<<'\n';
                        	else
                        	cout<<"1 "<<abs(y)<<" D"<<'\n';
                        }
                        cout<<"2"<<'\n';
                        if(y!=0)
                        {
                        	if(y>0)
                        	cout<<"1 "<<y<<" D"<<'\n';
                        	else
                        	cout<<"1 "<<abs(y)<<" U"<<'\n';
                        }
                        if(x!=0)
                        {
                        	if(x>0)
                        	cout<<"1 "<<x<<" L"<<'\n';
                        	else
                        	cout<<"1 "<<abs(x)<<" R"<<'\n';
                        }
                        
                        cout<<"3"<<'\n';
            }
            rep(i,v4.size())
            {
            	ll x=v4[i].first;
            	ll y=v4[i].second;
                        if(x!=0)
                        {
                        	if(x>0)
                        	cout<<"1 "<<x<<" R"<<'\n';
                        	else
                        	cout<<"1 "<<abs(x)<<" L"<<'\n';
                        }
                        if(y!=0)
                        {
                        	if(y>0)
                        	cout<<"1 "<<y<<" U"<<'\n';
                        	else
                        	cout<<"1 "<<abs(y)<<" D"<<'\n';
                        }
                        cout<<"2"<<'\n';
                        if(y!=0)
                        {
                        	if(y>0)
                        	cout<<"1 "<<y<<" D"<<'\n';
                        	else
                        	cout<<"1 "<<abs(y)<<" U"<<'\n';
                        }
                        if(x!=0)
                        {
                        	if(x>0)
                        	cout<<"1 "<<x<<" L"<<'\n';
                        	else
                        	cout<<"1 "<<abs(x)<<" R"<<'\n';
                        }
                        
                        cout<<"3"<<'\n';
            }
            return 0;
}