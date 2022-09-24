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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w)
{
	cout<<w.size()<<endl;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<endl;
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

const int N=150010,C=400,M=1<<18; //min degree to be heavy
int n,q,ind[N],to[N],cnt,par[N],ss[N];
int valH[N],seg[M*2+10];
vi ch[N],ch1[N];
vi hev;
bool he[N];
bool bio[N];

void dfs(int i)
{
	bio[i]=1;
	ind[i]=cnt++;
	ss[i]=1;
	for (auto d: ch[i]) if (!bio[d]) ch1[i].pb(d),par[d]=i,dfs(d),ss[i]+=ss[d];
	to[i]=cnt;
}

void addi(int&a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}

void upd(int i,int x)
{
	for (i+=M;i;i/=2) addi(seg[i],x);
}

int ge(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return add(ge(l,r,lo,mid,i*2),ge(l,r,mid,hi,i*2+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>q;
	M998();
	for (int i=1;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		ch[a].pb(b);
		ch[b].pb(a);
	}
	dfs(1);
	for (int i=1;i<=n;++i) if (ch1[i].size()>=C) hev.pb(i),he[i]=1;
	int suQ=0;
	while (q--)
	{
		int t,i;
		cin>>t>>i;
		if (t==1)
		{
			int x;
			cin>>x;
			/*upd(ind[i],x);
			addi(suQ,x);
			for (auto a: hev)
			{
				if (ind[i]>ind[a] && ind[i]<to[a])
				{
					int lo=0,hi=ch1[a].size()-1;
					while (lo<hi)
					{
						int mid=(lo+hi+1)/2;
						if (ind[mid]<ind[i]) hi=mid-1;
						else lo=mid;
					}
					addi(valH[a],mult(x,n-ss[ch1[a][lo]]));
				}
				else addi(valH[a],mult(x,ss[a]));
			}*/
			if (he[i])
			{
				addi(valH[i],x);
			}
			else
			{
				upd(0,mult(ss[i],x));
				for (auto a: ch1[i])
				{
					int z=mult(ss[a],x);
					upd(ind[a],sub(0,z));
					upd(to[a],z);
				}
				upd(ind[i],mult(n-ss[i],x));
				upd(to[i],sub(0,mult(n-ss[i],x)));
			}
		}
		else
		{
			/*if (he[i]) cout<<divide(valH[i],n)<<en;
			else
			{
				int ans=0,s2=0;
				for (auto a: ch1[i])
				{
					int r=ge(ind[a],to[a]);
					addi(s2,r);
					addi(ans,mult(r,n-ss[a]));
				}
				addi(ans,mult(sub(suQ,s2),ss[i]));
				cout<<divide(ans,n)<<en;
			}*/
			int ans=ge(0,ind[i]+1);
			for (auto a: hev)
			{
				if (i==a) addi(ans,mult(n,valH[a]));
				else if (ind[i]>ind[a] && ind[i]<to[a])
				{
					int lo=0,hi=ch1[a].size()-1;
					while (lo<hi)
					{
						int mid=(lo+hi+1)/2;
						if (ind[ch1[a][mid]]>ind[i]) hi=mid-1;
						else lo=mid;
					}
					//cout<<i<<' '<<a<<' '<<lo<<' '<<ch1[a][lo]<<en;
					addi(ans,mult(valH[a],n-ss[ch1[a][lo]]));
				}
				else addi(ans,mult(valH[a],ss[a]));
			}
			cout<<divide(ans,n)<<en;
		}
	}
}