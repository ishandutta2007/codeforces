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

const int N=1000010;
int n,dp[N],de[N],d2[N],par[N],a1[N],a2[N];
pii d3[N],d4[N];
vi ch[N],ch1[N];
bool bio[N];

void dfs1(int i)
{
	bio[i]=1;
	for (auto a: ch[i]) if (!bio[a])
	{
		par[a]=i;
		ch1[i].pb(a);
		de[a]=de[i]+1;
		dfs1(a);
		dp[i]=max(dp[i],dp[a]);
	}
	++dp[i];
}

void dfs2(int i,int k)
{
	d2[i]=de[i]+k;
	vector<pii> li;
	for (auto a: ch1[i]) li.eb(dp[a],a);
	sort(li.begin(),li.end());
	reverse(li.begin(),li.end());
	for (int i=1;i<li.size();++i)
	{
		dfs2(li[i].y,max(k,li[0].x-de[i]+1));
	}
	if (li.empty()) return;
	if (li.size()==1)
	{
		dfs2(li[0].y,k);
	}
	else
	{
		dfs2(li[0].y,max(k,li[1].x-de[i]+1));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		ch[a].pb(b);
		ch[b].pb(a);
	}
	if (n==2)
	{
		cout<<"2 1";
		exit(0);
	}
	int root=1;
	while (ch[root].size()==1) ++root;
	dfs1(root);
	d2[root]=1;
	vector<pii> v;
	for (auto a: ch[root]) v.pb({dp[a],a});
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for (int i=1;i<(int)v.size();++i) dfs2(v[i].y,v[0].x+1);
	dfs2(v[0].y,v[1].x+1);
	for (int i=1;i<=n;++i)
	{
		vector<pii> li;
		if (i!=root) li.eb(d2[i],par[i]);
		for (auto a: ch1[i]) li.eb(dp[a]+1,a);
		sort(li.begin(),li.end());
		reverse(li.begin(),li.end());
		if (li.size()>=2) d3[i]=li[1];
		d4[i]=li[0];
	}
	for (int i=1;i<=n;++i)
	{
		vector<int> li;
		for (auto a: ch1[i]) li.pb(dp[a]);
		if (i!=1)
		{
			if (par[i]!=root)
			{
				if (i==d4[par[i]].y) li.pb(d3[par[i]].x);
				else li.pb(d4[par[i]].x);
			}
			else if (i==v[0].y)
			{
				li.pb(v[1].x+1);
			}
			else li.pb(v[0].x+1);
		}
		sort(li.begin(),li.end());
		reverse(li.begin(),li.end());
		a1[1]=max(a1[1],ch[i].size()+1);
		for (int j=0;j<(int)li.size();++j)
		{
			a1[li[j]]=max(a1[li[j]],j+1);
			a2[li[j]]=max(a2[li[j]],j+1);
			if (j>=1 && li[j]+1<=li[j-1]) a1[li[j]+1]=max(a1[li[j]+1],j+1);
		}
	}
	for (int p=1;p<=n;++p)
	{
		vector<int> li;
		if (p!=1)
		{
			if (par[p]!=root)
			{
				if (p==d4[par[p]].y) li.pb(d3[par[p]].x);
				else li.pb(d4[par[p]].x);
			}
			else if (p==v[0].y)
			{
				li.pb(v[1].x+1);
			}
			else li.pb(v[0].x+1);
		}
		for (auto a: ch1[p]) li.pb(dp[a]);
		sort(li.begin(),li.end());
		reverse(li.begin(),li.end());
		//cout<<i<<' ';
		//prVec(li);
		//cout<<en;
		vector<pii> v1;
		for (int j=0;j<(int)li.size();++j) if (j==(int)li.size()-1 || li[j]!=li[j+1]) v1.pb({li[j],j+1});
		reverse(li.begin(),li.end());
		for (auto i: ch1[p])
		{
			//makni dp[i]
			vi li1;
			for (auto a: ch1[i]) li1.pb(dp[a]);
			sort(li1.begin(),li1.end());
			//prVec(li1);
			//prVec(li);
			for (int j=0;j<(int)li1.size();++j) a2[li1[j]]=max(a2[li1[j]],(int)li1.size()-j+(li.end()-lower_bound(li.begin(),li.end(),li1[j]))-(dp[i]>=li1[j]));
			for (auto a: v1) a2[a.x]=max(a2[a.x],int(a.y+(li1.end()-lower_bound(li1.begin(),li1.end(),a.x)))-(dp[i]>=a.x));
			//cout<<p<<' '<<i<<' '<<a2[1]<<en;
		}
	}
	a1[n]=a2[n]=1;
	for (int i=n;i>=1;--i) a1[i]=max(a1[i],a1[i+1]);
	for (int i=n;i>=1;--i) a2[i]=max(a2[i],a2[i+1]);
	for (int i=1;i<=n/2;++i) cout<<a1[i]<<' '<<a2[i]<<' ';
	if (n%2) cout<<a1[n/2+1];
}