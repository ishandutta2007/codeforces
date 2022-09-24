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
const int N=1000010,M=1<<20;
int q,n,cn,beg[N],kr[N],a[N],b[N];
array<int,6> id={-MOD,-MOD,-MOD,-MOD,-MOD,-MOD};
array<int,6> seg0[M*2+10],seg1[M*2+10];
bool prop[M*2+10];
vector<pii> ch[N];

array<int,6> mak(int de)
{
	return {de,-de,0,-2*de,-de,de};
}

array<int,6> mak2(int de)
{
	return {-MOD,-MOD,-MOD,-2*de,-MOD,-MOD};
}

array<int,6> mer(array<int,6> a,array<int,6> b) //a,a-2b,a-2b+c,-2b,-2b+c,c
{
	array<int,6> res;
	res[0]=max(a[0],b[0]);
	res[1]=max(max(a[1],b[1]),a[0]+b[3]);
	res[2]=max(max(a[2],b[2]),max(a[1]+b[5],a[0]+b[4]));
	res[3]=max(a[3],b[3]);
	res[4]=max(max(a[4],b[4]),a[3]+b[5]);
	res[5]=max(a[5],b[5]);
	return res;
}

void dfs(int i,int p=-1,int su=0,int d=0)
{
	if (su) seg1[cn+M]=mak(d),seg0[cn+M]=mak2(d);
	else seg0[cn+M]=mak(d),seg1[cn+M]=mak2(d);
	beg[i]=cn;
	++cn;
	for (auto a: ch[i]) if (a.x!=p)
	{
		dfs(a.x,i,su^a.y,d+1);
		//cout<<"id "<<i<<' '<<cn<<en;
		if (su) seg1[cn+M]=mak(d),seg0[cn+M]=mak2(d);
		else seg0[cn+M]=mak(d),seg1[cn+M]=mak2(d);
		++cn;
	}
	kr[i]=cn;
}

void pr(int i)
{
	if (prop[i])
	{
		swap(seg0[i],seg1[i]);
		if (i<M)
		{
			prop[i*2]^=1;
			prop[i*2+1]^=1;
		}
		prop[i]=0;
	}
}

void upd(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r)
	{
		prop[i]^=1;
		pr(i);
		return;
	}
	pr(i);
	if (lo>=r || hi<=l) return;
	int mid=(lo+hi)/2;
	upd(l,r,lo,mid,i*2);
	upd(l,r,mid,hi,i*2+1);
	seg0[i]=mer(seg0[i*2],seg0[i*2+1]);
	seg1[i]=mer(seg1[i*2],seg1[i*2+1]);
}

void pri(array<int,6> a)
{
	for (int i=0;i<6;++i) cout<<a[i]<<' ';
	cout<<en;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	for (int i=0;i<M*2;++i) seg0[i]=seg1[i]=id;
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x;
		cin>>a[i]>>b[i]>>x;
		ch[a[i]].eb(b[i],x);
		ch[b[i]].eb(a[i],x);
	}
	dfs(1);
	//for (int i=1;i<=n;++i) cout<<"begen: "<<beg[i]<<' '<<kr[i]<<en;
	for (int i=M-1;i;--i) seg0[i]=mer(seg0[i*2],seg0[i*2+1]);
	for (int i=M-1;i;--i) seg1[i]=mer(seg1[i*2],seg1[i*2+1]);
	for (int i=1;i<n;++i) if (beg[a[i]]>beg[b[i]]) swap(a[i],b[i]);
	//for (int i=1;i<n;++i) cout<<"ed: "<<a[i]<<' '<<b[i]<<en;
	/*pri(seg1[M]);
	pri(seg1[M+1]);
	pri(seg1[M+2]);
	pri(seg1[M+3]);
	pri(seg1[M/2]);
	pri(seg1[M/2+1]);
	pri(seg1[M/4]);*/
	cin>>q;
	while (q--)
	{
		int ed;
		cin>>ed;
		upd(beg[b[ed]],kr[b[ed]]);
		cout<<max(seg0[1][2],seg1[1][2])<<en;
	}
}