//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int ll
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

const int N=200010,M=1<<18;
int n,m,seg[M*2+10];
set<pair<pii,pii>> s;
set<pii> cek[N];
set<int> im[N];
int an[N];

void upd(int i,int x)
{
	for (i+=M;i;i/=2) seg[i]+=x;
}

int ge(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return ge(l,r,lo,mid,i*2)+ge(l,r,mid,hi,i*2+1);
}

int nel(int i)
{
	i+=M;
	while (1)
	{
		if (i%2==0) i/=2;
		else
		{
			if (seg[i^1])
			{
				i^=1;
				while (i<M)
				{
					if (seg[i*2+1]) i=i*2+1;
					else i=i*2;
				}
				return i-M;
			}
			i/=2;
		}
	}
}

int ner(int i)
{
	i+=M;
	while (1)
	{
		if (i%2==1) i/=2;
		else
		{
			if (seg[i^1])
			{
				i^=1;
				while (i<M)
				{
					if (seg[i*2]) i=i*2;
					else i=i*2+1;
				}
				return i-M;
			}
			i/=2;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>m;
	int dx=0,pos=1;
	for (int i=0;i<n;++i)
	{
		int t,a,b;
		cin>>t>>a>>b;
		s.insert({{t,i},{a,b}});
	}
	int cut=0;
	while (s.size())
	{
		auto u=*s.begin();
		s.erase(s.begin());
		int t=u.x.x,ind=u.x.y,a=u.y.x,b=u.y.y;
		//cout<<pos<<' '<<dx<<' '<<t<<' '<<ind<<' '<<a<<' '<<b<<endl;
		pos+=dx*(t-cut);
		cut=t;
		if (a>0 && b>0)
		{
			upd(a,1);
			cek[a].insert({ind,b});
		}
		for (auto x: cek[pos])
		{
			upd(pos,-1);
			upd(x.y,1);
			im[x.y].insert(x.x);
		}
		for (auto x: im[pos])
		{
			upd(pos,-1);
			an[x]=t;
		}
		cek[pos].clear();
		im[pos].clear();
		if (ge(0,m+1)==0) dx=0;
		else if (ge(pos+1,m+1)>=ge(0,pos)) dx=1;
		else dx=-1;
		int t1;
		if (dx==1)
		{
			int p1=ner(pos);
			//cout<<pos<<' '<<p1<<en;
			t1=p1-pos+t;
		}
		else if (dx==-1)
		{
			int p1=nel(pos);
			t1=pos-p1+t;
		}
		else t1=-MOD;
		//cout<<t1<<en;
		if (dx && (s.empty() || s.begin()->x.x>t1))
		{
			s.insert({{t1,0},{0,0}});
		}
	}
	for (int i=0;i<n;++i) cout<<an[i]<<en;
}