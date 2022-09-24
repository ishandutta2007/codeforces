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
#define popcnt __builtin_popcountll
#define all(a) begin(a),end(a)
//for kactl
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
const int MOD=31607;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(0);
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

inline int mult(int a,int b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	int a=pot(n,k/2);
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

void ad(int&a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}

void su(int&a,int b)
{
	a-=b;
	if (a<0) a+=MOD;
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
const int N=310;
int t,n,pr[N][N],npr[N][N],inv[N*N],spp[N];

int pro(int mask)
{
	//one column is black
	int sn=1;
	for (int i=0;i<n;++i)
	{
		int sp=1;
		for (int j=0;j<n;++j) if (!(mask&(1<<j))) sp=mult(sp,pr[i][j]);
		spp[i]=sp;
		sn=mult(sn,sub(1,sp));
	}
	int PnC=sub(1,sn);
	//one diagonal is black
	int PnD1=1;
	for (int i=0;i<n;++i) if (!(mask&(1<<i))) PnD1=mult(PnD1,pr[i][i]);
	//other diagonal is black
	int PnD2=1;
	for (int i=0;i<n;++i) if (!(mask&(1<<(n-i-1)))) PnD2=mult(PnD2,pr[i][n-i-1]);
	//one column and one diagonal is black
	sn=1;
	for (int i=0;i<n;++i)
	{
		int sp=spp[i];
		for (int j=i;j<=i;++j) if (!(mask&(1<<j)) && i==j) sp=mult(sp,inv[pr[i][j]]);
		sn=mult(sn,sub(1,sp));
	}
	int cond=sub(1,sn);
	int PnCnD1=mult(cond,PnD1);
	//one column and other diagonal is black
	sn=1;
	for (int i=0;i<n;++i)
	{
		int sp=spp[i];
		for (int j=n-i-1;j<=n-i-1;++j) if (!(mask&(1<<j)) && i==n-1-j) sp=mult(sp,inv[pr[i][j]]);
		sn=mult(sn,sub(1,sp));
	}
	cond=sub(1,sn);
	int PnCnD2=mult(cond,PnD2);
	//both diagonals are black
	int PnD1nD2=1;
	for (int i=0;i<n;++i) if (!(mask&(1<<i))) PnD1nD2=mult(PnD1nD2,pr[i][i]);
	for (int i=0;i<n;++i) if (i!=n-i-1) if (!(mask&(1<<(n-i-1)))) PnD1nD2=mult(PnD1nD2,pr[i][n-i-1]);
	//one column and both diagonals are black
	sn=1;
	for (int i=0;i<n;++i)
	{
		int sp=spp[i];
		for (int j=0;j<n;++j) if (!(mask&(1<<j)) && (i==j || i==n-1-j)) sp=mult(sp,inv[pr[i][j]]);
		sn=mult(sn,sub(1,sp));
	}
	cond=sub(1,sn);
	int PnCnD1nD2=mult(cond,PnD1nD2);
	//no bingo
	int P=add(PnC,add(PnD1,PnD2));
	P=sub(P,add(PnD1nD2,add(PnCnD1,PnCnD2)));
	P=add(P,PnCnD1nD2);
	/*vi v={PnC,PnD1,PnD2,PnD1nD2,PnCnD1,PnCnD2,PnCnD1nD2};
	for (auto a: v) cout<<mult(a,1<<(n*n))<<' ';
	cout<<en;*/
	return sub(1,P);
}

int pro2(int mask)
{
	int p1=0,p2=0;
	for (int b=0;b<(1<<(n*n));++b)
	{
		vector<vi> v(n,vi(n));
		int pro=1;
		for (int i=0;i<n;++i) for (int j=0;j<n;++j) if (b&(1<<(i*n+j)))
		{
			v[i][j]=1;
			pro=mult(pro,pr[i][j]);
		}
		else pro=mult(pro,npr[i][j]);
		bool ok=1;
		for (int i=0;i<n;++i) for (int j=0;j<n;++j) if (mask&(1<<j))
		{
			if (!v[i][j]) ok=0;
		}
		if (ok)
		{
			ad(p2,pro);
			bool bing=0;
			for (int i=0;i<n;++i)
			{
				bool ok=1;
				for (int j=0;j<n;++j) if (!v[i][j]) ok=0;
				if (ok) bing=1;
			}
			bool ok=1;
			for (int i=0;i<n;++i) if (!v[i][i]) ok=0;
			if (ok) bing=1;
			ok=1;
			for (int i=0;i<n;++i) if (!v[i][n-i-1]) ok=0;
			if (ok) bing=1;
			if (!bing) ad(p1,pro);
		}
	}
	return divide(p1,p2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	//n=19;
	for (int i=0;i<MOD;++i) inv[i]=divide(1,i);
	for (int i=0;i<n;++i) for (int j=0;j<n;++j)
	{
		int x;
		cin>>x;
		pr[i][j]=divide(x,10000);
		npr[i][j]=sub(1,pr[i][j]);
	}
	int pNiDa=0;
	for (int b=0;b<(1<<n);++b)
	{
		int pFu=1;
		for (int i=0;i<n;++i) for (int j=0;j<n;++j) if (b&(1<<j)) pFu=mult(pFu,pr[i][j]);
		int z=pro(b);
		//int z1=pro2(b);
		//cout<<b<<' '<<z<<' '<<mult(z,1<<(n*n))<<'/'<<(1<<(n*n))<<' '<<z1<<' '<<mult(z1,1<<(n*n))<<'/'<<(1<<(n*n))<<en;
		/*for (int i=1;i<=512;i*=2) if (mult(z,i)<=490)
		{
			cout<<mult(z,i)<<'/'<<i<<en;
			break;
		}*/
		int pRgO=mult(z,pFu);
		if (popcnt(b)%2) su(pNiDa,pRgO);
		else ad(pNiDa,pRgO);
	}
	cout<<sub(1,pNiDa)<<en;
}