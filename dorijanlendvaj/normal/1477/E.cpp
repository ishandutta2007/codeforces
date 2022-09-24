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

template<class T>
vi compress(vector<T>&v)
{
	set<T> s;
	for (auto a: v) s.insert(a);
	vector<T> o(all(s));
	vi nv;
	for (int i=0;i<(int)v.size();++i) nv.pb(lower_bound(all(o),v[i])-o.begin());
	return nv;
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
const int N=200010,M=1<<20;
int m,n,q,a[N],b[N],cn[M*2+10];
ll su[M*2+10],ours;
multiset<int> our;

void upd(int i,int x)
{
	int re=i;
	for (i+=M;i;i/=2)
	{
		cn[i]+=x;
		su[i]+=x*re;
	}
}

ll ges(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return su[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return ges(l,r,lo,mid,i*2)+ges(l,r,mid,hi,i*2+1);
}

int gec(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return cn[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return gec(l,r,lo,mid,i*2)+gec(l,r,mid,hi,i*2+1);
}

int gekth(int k)
{
	if (k<=0) return -MOD;
	int i=1;
	while (i<M)
	{
		if (cn[i*2]>=k) i=i*2;
		else
		{
			k-=cn[i*2];
			i=i*2+1;
		}
	}
	return i-M;
}

ll pok(int u,int k,bool nase)
{
	int nas=min(min(*our.begin(),gekth(1)),u-k);
	ll thes=ges(u-k,M)-gec(u-k,M)*1ll*(u-k);
	if (nase) return k+ours-u-(n-1)*1ll*nas-thes;
	else return ours-n*1ll*nas-thes;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>m>>q;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		our.insert(a[i]);
		ours+=a[i];
	}
	for (int i=0;i<m;++i)
	{
		cin>>b[i];
		upd(b[i],1);
	}
	while (q--)
	{
		int t;
		cin>>t;
		if (t==1)
		{
			int i,x;
			cin>>i>>x;
			--i;
			our.erase(our.find(a[i]));
			ours-=a[i];
			a[i]=x;
			our.insert(a[i]);
			ours+=a[i];
		}
		if (t==2)
		{
			int i,x;
			cin>>i>>x;
			--i;
			upd(b[i],-1);
			b[i]=x;
			upd(b[i],1);
		}
		if (t==3)
		{
			int k;
			cin>>k;
			ll ma=max(pok(gekth(m),k,0),pok(gekth(max(m-n+1,1)),k,0));
			auto it=our.upper_bound(gekth(m)+k);
			if (it!=our.end()) ma=max(ma,pok(*it,k,1));
			if (it!=our.begin())
			{
				--it;
				ma=max(ma,pok(*it,k,1));
			}
			it=our.upper_bound(gekth(m-n+1)+k);
			if (it!=our.end()) ma=max(ma,pok(*it,k,1));
			if (it!=our.begin())
			{
				--it;
				ma=max(ma,pok(*it,k,1));
			}
			cout<<ma<<en;
		}
	}
}