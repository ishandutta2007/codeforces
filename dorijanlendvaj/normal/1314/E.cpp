//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops,Ofast")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define all(a) begin(a),end(a)

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

const int N=2030,M1=70;
int n,k,dp[2][N][N],dp1[N],ans,op,cn,c[N];
vi par;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool ok()
{
	vi p1=par;
	++cn;
	//prVec(par);
	/*if (k==3)
	{
		ll cz=0,s=0;
		for (int i=0;i<p1.size();++i)
		{
			s+=(i+1)*1ll*(cz+cz+1+p1[i])*(p1[i])/2;
			cz+=p1[i];
		}
		return s<=n;
	}*/
	for (int z=0;z<k-1;++z)
	{
		int su=0,s1=0;
		for (int i=0;i<p1.size();++i)
		{
			su+=(i+1)*p1[i];
			s1+=p1[i];
			++op;
			if (su>n) return 0;
		}
		vi no(s1);
		int zb=0;
		if (z!=k-2) for (int i=0;i<p1.size();++i) for (int j=0;j<p1[i];++j)
		{
			no[zb++]=i+1;
		}
		reverse(all(no));
		p1=no;
	}
	return 1;
}

void rek(int lef,int s,int ma=min(n,M1))
{
	if (s) ++ans;
	++c[s];
	for (int i=1;i<=ma;++i)
	{
		par.pb(i);
		if (ok()) rek(lef-i,s+1,i);
		else
		{
			par.pop_back();
			break;
		}
		par.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>k;
	M998();
	if (k==1)
	{
		dp1[0]=1;
		for (int i=0;i<n;++i)
		{
			int a=i+1;
			for (int j=a;j<=n;++j)
	        {
	            dp1[j]+=dp1[j-a];
	            if (dp1[j]>=MOD) dp1[j]-=MOD;
	        }
		}
		int s=0;
		for (int i=1;i<=n;++i) s=add(s,dp1[i]);
		cout<<s<<en;
		exit(0);
	}
	if (k==2)
	{
		int an=0;
		dp[0][n][0]=1;
		int mma=n;
		int sss=0,ss=0;
		for (int k=0;k<=min(n,80);++k)
		{
			memset(dp[(k+1)%2],0,sizeof(dp[(k+1)%2]));
			int ol=k%2,ne=(k+1)%2;
			int mmma=0;
			for (int ma=mma;ma>=1;--ma)
			{
			    for (int s=max(ma*k,k+1);s<=n;++s)
    			{
    			    int sta;
    			    if (k) sta=1;
    			    else sta=s;
    			    for (int cn=sta;cn<=min(s/(k+1),ma);++cn) if (dp[ol][ma][s-(k+1)*cn])
        		    {
        		    	//cout<<ma<<' '<<k<<' '<<s<<' '<<cn<<en;
        		        dp[ne][cn][s]+=dp[ol][ma][s-(k+1)*cn];
        		        mmma=max(mmma,cn);
        		        ++ss;
        		        //cout<<dp[k+1][s][cn]<<en;
        		        if (dp[ne][cn][s]>=MOD) dp[ne][cn][s]-=MOD;
        		        an+=dp[ol][ma][s-(k+1)*cn];
        		        if (an>=MOD) an-=MOD;
        		    }
        		    if (k==1 && ma!=1) ++s;
    			}
			}
		    mma=mmma;
		    //cout<<mma<<en;
		    sss+=mma;
		}
		cout<<an;
		exit(0);
	}
	if (k==3) rek(min(n,M1),0);
	else rek(min(n,19),0);
	cout<<ans<<en;
	//cout<<op<<' '<<cn<<en;
	//for (int i=1;i<=M1;++i) cout<<c[i]<<' ';
	//cout<<en;
}