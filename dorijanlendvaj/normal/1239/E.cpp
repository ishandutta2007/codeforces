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
int n;
vi v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	for (int i=0;i<2*n;++i)
	{
		int a;
		cin>>a;
		v.pb(a);
	}
	sort(v.begin(),v.end());
	int x=v[0],y=v[1];
	vi n1,n2;
	for (int i=2;i<=n;++i) n1.pb(v[i]);
	for (int i=n+1;i<n*2;++i) n2.pb(v[i]);
	vi ne[30];
	int sve=0;
	for (int i=2;i<n*2;++i) sve+=v[i];
	for (int b=0;b<(1<<(n1.size()));++b)
	{
		int s=0;
		for (int i=0;i<n-1;++i) if (b&(1<<i)) s+=n1[i];
		ne[__builtin_popcount(b)].pb(s);
	}
	for (int i=0;i<25;++i) sort(ne[i].begin(),ne[i].end());
	int mi=MOD,be=-1,s1=-1,s2=-1,c1=-1,c2=-1;
	vi ne2[30];
	for (int b=0;b<(1<<(n2.size()));++b)
	{
		int s=0;
		for (int i=0;i<n-1;++i) if (b&(1<<i)) s+=n2[i];
		int pc=__builtin_popcount(b);
		if (sve/2-s>ne[n-1-pc].back()) continue;
		/*auto it=lower_bound(ne[n-1-pc].begin(),ne[n-1-pc].end(),sve/2-s);
		//cout<<b<<' '<<s<<' '<<pc<<en;
		int dif=*it+s-sve/2;
		if (dif<mi)
		{
			mi=dif;
			be=b;
			s2=s;
			s1=*it;
			c1=n-1-pc;
		}*/
		ne2[n-1-pc].pb(s);
	}
	for (int i=0;i<25;++i)
	{
		sort(ne2[i].begin(),ne2[i].end());
		int l=0;
		int si=ne2[i].size();
		for (int r=(int)ne[i].size()-1;r>=0;--r)
		{
			while (l<si && ne2[i][l]+ne[i][r]<sve/2) ++l;
			if (l==si) break;
			int dif=ne2[i][l]+ne[i][r]-sve/2;
			if (dif<mi)
			{
				mi=dif;
				s2=ne2[i][l];
				s1=ne[i][r];
				c2=n-1-i;
				c1=i;
			}
		}
	}
	for (int b=0;b<(1<<(n2.size()));++b)
	{
		int s=0;
		for (int i=0;i<n-1;++i) if (b&(1<<i)) s+=n2[i];
		int pc=__builtin_popcount(b);
		if (s==s2 && pc==c2) be=b;
	}
	//cout<<mi<<' '<<be<<' '<<s1<<' '<<s2<<' '<<c1<<en;
	for (int b=0;b<(1<<(n1.size()));++b)
	{
		int s=0;
		for (int i=0;i<n-1;++i) if (b&(1<<i)) s+=n1[i];
		if (s==s1 && __builtin_popcount(b)==c1)
		{
			vi u,v;
			for (int i=0;i<n-1;++i) if (b&(1<<i)) u.pb(n1[i]);
			else v.pb(n1[i]);
			for (int i=0;i<n-1;++i) if (be&(1<<i)) u.pb(n2[i]);
			else v.pb(n2[i]);
			sort(u.begin(),u.end());
			sort(v.begin(),v.end());
			reverse(v.begin(),v.end());
			cout<<x;
			for (auto a: u) cout<<' '<<a;
			cout<<en;
			for (auto a: v) cout<<a<<' ';
			cout<<y<<en;
			exit(0);
		}
	}
}