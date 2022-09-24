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
const int MOD=1000000007;
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

const int N=1000010;
int t,n,p1[N],p2[N];
vi dp[N];
string h[N];
vi sorp[N],ha1[N],ha2[N];

pii ge(int i,int l,int r)
{
	return {sub(ha1[i][r],mult(ha1[i][l],p1[r-l])),sub(ha2[i][r],mult(ha2[i][l],p2[r-l]))};
}

int cmsu(int i1,int i2,int l1,int l2,int le)
{
	if (le<=0) return 0;
	bool fl=0;
	if (l1+le>(int)h[i1].size() || l2+le>(int)h[i2].size())
	{
		le=min(le,(int)h[i1].size()-l1);
		le=min(le,(int)h[i2].size()-l2);
		fl=1;
	}
	//cout<<i1<<' '<<i2<<' '<<l1<<' '<<l2<<' '<<le<<en;
	if (ge(i1,l1,l1+le)==ge(i2,l2,l2+le))
	{
		if (fl)
		{
			if (h[i1].size()<h[i2].size()) return -1;
			if (h[i1].size()>h[i2].size()) return 1;
		}
		return 0;
	}
	int lo=0,hi=le;
	while (lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if (ge(i1,l1,l1+mid)==ge(i2,l2,l2+mid)) lo=mid;
		else hi=mid-1;
	}
	if (h[i1][l1+lo]<h[i2][l2+lo]) return -1;
	else return 1;
}

int cmrem(int i1,int i2,int j1,int j2)
{
	int mul=1;
	if (j1>j2)
	{
		swap(i1,i2);
		swap(j1,j2);
		mul=-1;
	}
	int ms=min((int)h[i1].size(),(int)h[i2].size());
	//j2=min(j2,ms-1);
	//j1=min(j1,ms-1);
	//cout<<i1<<' '<<i2<<' '<<j1<<' '<<j2<<endl;
	int r1=cmsu(i1,i2,0,0,j1);
	//cout<<r1<<en;
	if (r1==-1) return -mul;
	if (r1==1) return mul;
	r1=cmsu(i1,i2,j1+1,j1,j2-j1);
	//cout<<r1<<en;
	if (r1==-1) return -mul;
	if (r1==1) return mul;
	r1=cmsu(i1,i2,j2+1,j2+1,ms-j2-1);
	//cout<<r1<<en;
	if (r1==-1) return -mul;
	if (r1==1) return mul;
	int s1=h[i1].size()-(j1<(int)h[i1].size()-1);
	int s2=h[i2].size()-(j2<(int)h[i2].size()-1);
	if (s1>s2) return mul;
	if (s2>s1) return -mul;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	h[0]=" ";
	dp[0]={1};
	ha1[0]={0,' '};
	ha2[0]={0,' '};
	sorp[0]={0};
	p1[0]=p2[0]=1;
	for (int i=1;i<N;++i) p1[i]=mult(p1[i-1],bases[0]),p2[i]=mult(p2[i-1],bases[1]);
	for (int i=1;i<=n;++i)
	{
		cin>>h[i];
		//for (int j=0;j<5e4;++j) h[i]+="ba";
		h[i].pb(' ');
		vi cur;
		vi poc,kr;
		for (int j=0;j<(int)h[i].size()-1;++j)
		{
			cur.pb(j);
			if (h[i][j]>h[i][j+1])
			{
				for (auto a: cur) poc.pb(a);
				cur.clear();
			}
			if (h[i][j]<h[i][j+1])
			{
				for (auto a: cur) kr.pb(a);
				cur.clear();
			}
		}
		cur.pb((int)h[i].size()-1);
		for (auto a: cur) poc.pb(a);
		cur.clear();
		reverse(all(kr));
		for (auto a: poc) sorp[i].pb(a);
		for (auto a: kr) sorp[i].pb(a);
		//prVec(sorp[i]);
		ha1[i].pb(0);
		ha2[i].pb(0);
		for (auto c: h[i]) ha1[i].pb(add(c,mult(ha1[i].back(),bases[0])));
		for (auto c: h[i]) ha2[i].pb(add(c,mult(ha2[i].back(),bases[1])));
		int su=0;
		int i1=0,i2=0;
		dp[i].resize(h[i].size());
		while (i1<(int)h[i-1].size() || i2<(int)h[i].size())
		{
			//cout<<i1<<' '<<i2<<endl;
			if (i2==(int)h[i].size())
			{
				su=add(su,dp[i-1][sorp[i-1][i1]]);
				++i1;
				continue;
			}
			if (i1==(int)h[i-1].size())
			{
				dp[i][sorp[i][i2]]=su;
				++i2;
				continue;
			}
			int u=cmrem(i-1,i,sorp[i-1][i1],sorp[i][i2]);
			//cout<<"hmm "<<i-1<<' '<<i<<' '<<sorp[i-1][i1]<<' '<<sorp[i][i2]<<' '<<u<<en;
			if (u<=0)
			{
				su=add(su,dp[i-1][sorp[i-1][i1]]);
				++i1;
				continue;
			}
			else
			{
				dp[i][sorp[i][i2]]=su;
				++i2;
				continue;
			}
		}
		//prVec(dp[i],1);
	}
	int su=0;
	for (auto a: dp[n]) su=add(su,a);
	cout<<su<<en;
}