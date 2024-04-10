//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll

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

mt19937 rng(0);
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

const int N=300010;
const bool RI=0;
int n,cq,ans[N],inp[N];
int rem[N];
bool bio[N];

vi wo(vi a,int x)
{
	vi e;
	for (auto b: a) if (b!=x) e.pb(b);
	assert(a.size());
	assert(e.size()==a.size()-1);
	return e;
}

vi wi(vi a,int x)
{
	a.pb(x);
	return a;
}

bool ask(vi a)
{
	if (RI)
	{
		++cq;
		int ss=0;
		for (auto b: a) ss+=inp[b];
		return ss%a.size()==0;
	}
	else
	{
		cout<<"? "<<a.size();
		for (auto b: a) cout<<' '<<b;
		cout<<endl;
		int x;
		cin>>x;
		if (x==-1)
		{
			vi v(100000000);
			exit(0);
		}
		return x;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	if (RI)
	{
		for (int i=1;i<=n;++i) inp[i]=i;
		shandom_ruffle(inp+1,inp+n+1);
	}
	int cu=1;
	vector<pii> po;
	for (int i=1;i<=n/2;++i)
	{
		vi lo1,lo2;
		vi sve;
		//cout<<i<<en;
		//for (int j=1;j<=n;++j) if (!bio[j]) cout<<j<<' '<<rem[j]<<en;
		for (int j=1;j<=n;++j) if (!bio[j])
		{
			sve.pb(j);
			if (rem[j]==i%cu) lo1.pb(j);
			if (rem[j]==(n-i+1)%cu) lo2.pb(j);
		}
		/*prVec(lo1);
		prVec(lo2);
		cout<<endl;
		for (auto a: po) cout<<a.x<<' '<<a.y<<en;
		cout<<en<<endl;*/
		if (lo1==lo2)
		{
			shandom_ruffle(lo1.begin(),lo1.end());
			int x=-1,y=-1;
			for (auto a: lo1)
			{
				if (ask(wo(sve,a)))
				{
					if (x==-1) x=a;
					else if (y==-1)
					{
						y=a;
						break;
					}
				}
			}
			if (po.size())
			{
				if (ask({po.back().x,x})) swap(x,y);
			}
			po.eb(x,y);
			bio[x]=bio[y]=1;
			ans[x]=i;
			ans[y]=n-i+1;
			//cout<<"AAA "<<x<<' '<<y<<endl;
			//for (int j=1;j<=n;++j) cout<<bio[j];
			//cout<<endl;
		}
		else
		{
			shandom_ruffle(lo1.begin(),lo1.end());
			shandom_ruffle(lo2.begin(),lo2.end());
			int x=-1,y=-1;
			for (auto a: lo1)
			{
				if (ask(wo(sve,a)))
				{
					if (x==-1)
					{
						x=a;
						break;
					}
				}
			}
			for (auto a: lo2)
			{
				if (ask(wo(sve,a)))
				{
					if (y==-1)
					{
						y=a;
						break;
					}
				}
			}
			assert(x!=-1 && y!=-1);
			if (po.size())
			{
				if (ask({po.back().x,x})) swap(x,y);
			}
			po.eb(x,y);
			bio[x]=bio[y]=1;
			ans[x]=i;
			ans[y]=n-i+1;
		}
		if (i==cu*2)
		{
			vi z;
			for (int j=0;j<po.size();++j) z.pb(po[j].x);
			for (int j=1;j<=n;++j) if (!bio[j] && ask(wi(wo(z,z[(rem[j]+z.size()-1)%z.size()]),j))) rem[j]+=cu;
			cu*=2;
		}
	}
	for (int i=0;i<po.size();++i) if (po[i].y==1)
	{
		for (int j=0;j<po.size();++j) swap(po[j].x,po[j].y);
		for (int j=1;j<=n;++j) ans[j]=n+1-ans[j];
	}
	cout<<"!";
	for (int i=1;i<=n;++i) cout<<' '<<ans[i];
	cout<<endl;
	if (RI) cout<<cq<<endl;
}