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

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int N=200010,M=1<<18;
int q,n;
ll seg[M*2+10],prop[M*2+10];
set<pii> s;

void pr(int i,int lo,int hi)
{
	if (prop[i]==-1) return;
	seg[i]=(hi-lo)*prop[i];
	if (i<M)
	{
		prop[i*2]=prop[i];
		prop[i*2+1]=prop[i];
	}
	prop[i]=-1;
}

void upd(int l,int r,int x,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r)
	{
		prop[i]=x;
		pr(i,lo,hi);
		return;
	}
	pr(i,lo,hi);
	if (lo>=r || hi<=l) return;
	int mid=(lo+hi)/2;
	upd(l,r,x,lo,mid,i*2);
	upd(l,r,x,mid,hi,i*2+1);
	seg[i]=seg[i*2]+seg[i*2+1];
}

ll ge(int l,int r,int lo=0,int hi=M,int i=1)
{
	pr(i,lo,hi);
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return ge(l,r,lo,mid,i*2)+ge(l,r,mid,hi,i*2+1);
}

int dog(int i,ll bu)
{
	bu+=ge(0,i);
	int o=1,lo=0,hi=M;
	while (o<M)
	{
		int mid=(lo+hi)/2;
		pr(o,lo,hi);
		pr(o*2,lo,mid);
		pr(o*2+1,mid,hi);
		if (bu<seg[o*2]) o=o*2,hi=mid;
		else bu-=seg[o*2],o=o*2+1,lo=mid;
	}
	return o-M;
}

void up(int i,int x)
{
	auto it=s.lower_bound({x,0});
	if ((it->y)>=i) return;
	s.insert({x,i});
	int l=i;
	while (1)
	{
		it=s.find({x,i});
		--it;
		if ((it->y)<=i)
		{
			s.erase(it);
		}
		else
		{
			++it;
			++it;
			l=it->y+1;
			break;
		}
	}
	upd(l,i+1,x);
	//cout<<l<<' '<<i<<' '<<x<<en;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>q;
	s.insert({MOD,0});
	s.insert({0,n+1});
	upd(0,1,MOD);
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		up(i,x);
	}
	upd(n+1,n+2,MOD);
	while (q--)
	{
		ll t,x,y;
		cin>>t>>x>>y;
		if (t==1) up(x,y);
		else
		{
			int cn=0;
			int z=0;
			while (x<=n)
			{
				auto it=s.upper_bound({y,MOD});
				x=max(x,it->y+1);
				if (x>n) break;
				int r=dog(x,y);
				//cout<<"P"<<x<<' '<<y<<' '<<r<<endl;
				++z;
				if (z==100) break;
				cn+=r-x;
				y-=ge(x,r);
				x=r;
				assert(y>=0);
			}
			assert(z<=50);
			cout<<cn<<en;
		}
	}
}