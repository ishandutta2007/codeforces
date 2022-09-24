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
int n,fr[N],an[N];
vi per;
vector<pii> res;

pii ins(int i)
{
	++fr[i];
	int a=0,b=0;
	for (int j=0;j<n;++j)
	{
		a+=fr[j]*(fr[j]-1)*(fr[j]-2)/6;
	}
	for (int j=0;j<n-2;++j)
	{
		b+=fr[j]*fr[j+1]*fr[j+2];
	}
	return {a,b};
}

vector<vi> gen(vi st)
{
	vector<vi> ans;
	if (st.size()==n)
	{
		ans.pb(st);
		return ans;
	}
	for (int i=0;i<=n;++i)
	{
		vi g=st;
		g.pb(i);
		auto re=gen(g);
		for (auto a: re) ans.pb(a);
	}
	return ans;
}

void test(vi a)
{
	for (int i=0;i<n;++i) fr[i]=a[i];
	fr[n]=0;
	auto p=ins(n);
	vector<pii> v;
	for (int i=0;i<n;++i)
	{
		auto u=ins(per[i]);
		v.pb({u.x-p.x,u.y-p.y});
		p=u;
	}
	if (v==res)
	{
		cout<<"! ";
		for (auto b: a) cout<<b<<' ';
		cout<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	per={0,0,2,1};
	if (n==4) per={1,3,2,3};
	for (int i=3;i<n-1;++i) per.pb(i);
	int uu,vv;
	cin>>uu>>vv;
	for (auto a: per)
	{
		cout<<"+ "<<a+1<<endl;
		int _a,_b;
		cin>>_a>>_b;
		res.eb(_a-uu,_b-vv);
		uu=_a;
		vv=_b;
	}
	if (n<=4)
	{
		auto z=gen({});
		for (auto a: z) test(a);
		exit(0);
	}
	else
	{
		for (int i=0;i<=n;++i) if (i*(i+1)/2==res[1].x) an[0]=i;
		for (int i=2;i<n;++i) for (int j=2;j<=n;++j) if (j*(j-1)/2==res[i].x) an[per[i]]=j;
		if (!an[2])
		{
			if (an[3])
			{
				an[2]=res[3].y/(an[0]+an[3]+2)-1;
			}
			else
			{
				if (res[3].y<=an[0]+3) an[2]=0;
				else an[2]=1;
			}
		}
		if (!an[3])
		{
			an[3]=res[3].y/(an[2]+1)-an[0]-2;
		}
		if (!an[1])
		{
			if (an[4])
			{
				an[1]=(res[2].y-an[3]*an[4])/(an[0]+2+an[3]);
			}
			else
			{
				if (res[2].y>=an[0]+an[3]+2) an[1]=1;
				else an[1]=0;
			}
		}
		for (int i=4;i<n-1;++i) if (!an[i]) an[i]=!!(res[i].y/(an[i-2]+1)-(an[i-3]+1));
		for (int i=n-1;i<n;++i) if (!an[i]) an[i]=res[i].y/(an[i-2]+1)-(an[i-3]+1);
		cout<<"! ";
		for (int i=0;i<n;++i) cout<<an[i]<<' ';
		cout<<endl;
	}
}