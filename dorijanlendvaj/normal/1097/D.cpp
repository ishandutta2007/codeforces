/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define rand rund
#define pb push_back
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=1000000007;
const int MOD2=998244353;
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

ll raand()
{
	ll a=rand();
	a*=RAND_MAX;
	a+=rand();
    return a;
}

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

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=10;
		k+=a[i]-'0';
	}
	return k;
}

string its(ll k)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%10)+'0');
		k/=10;
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

ll mult(ll a,ll b)
{
	return (a*b)%MOD;
}

ll pot(ll n,ll k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

ll divide(ll a,ll b)
{
	return mult(a,pot(b,MOD-2));
}

ll sub(ll a,ll b)
{
	return (a-b+MOD)%MOD;
}

inline int add(int a,int b)
{
	return (a+b)%MOD;
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

ll has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (char a: x)
	{
		h1*=bases[0];
		h1+=a-'a';
		h1%=bases[3];
		h2*=bases[1];
		h2+=a-'a';
		h2%=bases[4];
	}
	return h1*(MOD+13893829)+h2;
}

const int N=10010;
ll n,k,nn;
//vector<int> l[N];
set<ll> di;
vector<pair<ll,int> > dd;
map<ll,int> m,m1;
int re[N],ans;
//int nu[N];
int r[51][51][N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void rek(int d)
{
	if (d==dd.size())
	{
		int abr=1,nu=1;
		for (int i=0;i<dd.size();++i)
		{
			abr=mult(abr,pot(dd[i].x,re[i]));
			nu=mult(nu,pot(dd[i].x,re[i]));
			abr=mult(abr,r[dd[i].y-re[i]][dd[i].y][k]);
		}
		ans=add(ans,abr);
	}
	else
	{
		for (int i=0;i<=dd[d].y;++i)
		{
			re[d]=i;
			rek(d+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(raand()%MOD+13893829);
	cin>>n>>k;
	int niz[100];
	for (int i=1;i<=51;++i) niz[i]=divide(1,i);
	for (int m=1;m<=50;++m)
	{
		r[0][m][0]=1;
		for (int j=1;j<=k;++j)
		{
			for (int i=0;i<=m;++i) r[i][m][j]=mult(r[i][m][j-1],niz[m-i+1]);
			for (int i=1;i<=m;++i) r[i][m][j]=add(r[i-1][m][j],r[i][m][j]);
		}
	}
	//cout<<clock()-cl1<<endl;
	/*for (int i=0;i<=1;++i)
	{
		for (int j=0;j<=1;++j)
		{
			cout<<r[j][1][i]<<' ';
		}
		cout<<en;
	}*/
	nn=n;
	for (int i=2;i<=round(sqrt(nn))+2;++i)
	{
		if (n%i==0)
		{
			while (n%i==0) ++m1[i],n/=i;
		}
		if (nn%i==0)
		{
			di.insert(i);
			di.insert(nn/i);
		}
	}
	if (n!=1) ++m1[n];
	int o=0;
	for (auto e: di)
	{
		m[e]=o;
		++o;
	}
	for (auto e: m1) dd.push_back({e.x,e.y});
	rek(0);
	cout<<ans;
}