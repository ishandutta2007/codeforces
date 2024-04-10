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

void compress(vi&v)
{
	set<int> s;
	for (auto a: v) s.insert(a);
	vi o(all(s));
	for (auto&a: v) a=lower_bound(all(o),a)-o.begin();
}

void compress(vl&v)
{
	set<ll> s;
	for (auto a: v) s.insert(a);
	vl o(all(s));
	for (auto&a: v) a=lower_bound(all(o),a)-o.begin();
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
int t,n,ss[N],par[N],de[N];
set<pair<int,pii>> s[N];
set<int> im[N];
bool bio[N];
bool chi[N];
vi ch[N];
ll k;

void dfs(int i,int p=-1)
{
	ss[i]=1;
	par[i]=p;
	for (auto a: ch[i]) if (a!=p)
	{
		de[a]=de[i]+1;
		dfs(a,i);
		ss[i]+=ss[a];
	}
}

void dfs1(int i,int r,int p)
{
	vi od;
	im[r].insert(i);
	for (auto a: ch[i]) if (a!=p && ss[a]%2) od.pb(a);
	while (od.size()>=2)
	{
		int a=od.back();
		od.pop_back();
		int b=od.back();
		od.pop_back();
		s[r].insert({de[i],{a,b}});
	}
	if (od.size()==1)
	{
		int a=od.back();
		od.pop_back();
		s[r].insert({de[i],{a,i}});
	}
	for (auto a: ch[i]) if (a!=p) dfs1(a,r,i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>k;
	if (n==2)
	{
		if (k==1)
		{
			cout<<"YES\n1 2\n";
			exit(0);
		}
		else
		{
			cout<<"NO\n";
			exit(0);
		}
	}
	for (int i=1;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		ch[a].pb(b);
		ch[b].pb(a);
	}
	dfs(1);
	int cen=-1;
	for (int i=1;i<=n;++i)
	{
		bool ok=1;
		if (n-ss[i]>n/2) ok=0;
		for (auto a: ch[i]) if (par[i]!=a && ss[a]>n/2) ok=0;
		if (ok) cen=i;
	}
	de[cen]=0;
	//cout<<cen<<endl;
	dfs(cen);
	for (auto a: ch[cen]) dfs1(a,a,cen);
	priority_queue<pii> pq;
	ll sd=0;
	for (int i=1;i<=n;++i) sd+=de[i];
	k=sd-k;
	if (k<0 || k%2)
	{
		cout<<"NO\n";
		exit(0);
	}
	k/=2;
	for (auto a: ch[cen]) pq.push({im[a].size(),a});
	vector<pii> v;
	while (k)
	{
		int a=pq.top().y;
		pq.pop();
		if (s[a].empty())
		{
			cout<<"NO\n";
			exit(0);
		}
		auto it=s[a].upper_bound({k,{MOD,MOD}});
		if (it==s[a].begin())
		{
			assert(k==1);
			for (auto x: ch[a]) if (x!=cen) chi[x]=1;
			for (auto x: im[a]) if (chi[x])
			{
				v.eb(a,x);
				im[a].erase(x);
				im[a].erase(a);
				break;
			}
			pq.push({im[a].size(),a});
			break;
		}
		--it;
		v.eb(it->y.x,it->y.y);
		im[a].erase(it->y.x);
		im[a].erase(it->y.y);
		k-=it->x;
		s[a].erase(it);
		pq.push({im[a].size(),a});
	}
	/*for (auto a: v) cout<<a.x<<' '<<a.y<<en;
	for (auto a: ch[cen])
	{
		cout<<a<<en;
		for (auto b: im[a]) cout<<b<<' ';
		cout<<en;
	}*/
	while (1)
	{
		int a=pq.top().y;
		pq.pop();
		int b=pq.top().y;
		pq.pop();
		//cout<<a<<' '<<b<<en;
		int x=*im[a].begin();
		if (im[b].empty())
		{
			v.eb(x,cen);
			break;
		}
		int y=*im[b].begin();
		v.eb(x,y);
		im[a].erase(x);
		im[b].erase(y);
		pq.push({im[a].size(),a});
		pq.push({im[b].size(),b});
	}
	cout<<"YES\n";
	for (auto a: v) cout<<a.x<<' '<<a.y<<en;
}