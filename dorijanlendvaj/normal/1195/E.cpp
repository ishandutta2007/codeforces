#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
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

const int N=3010;
ll n,m,a,b,g,x,y,z;
int h[2][N][N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n>>m>>a>>b>>g>>x>>y>>z;
	int e=1,f=1,p=0,q=0;
	while (e*2<a) e*=2,++p;
	while (f*2<b) f*=2,++q;
	vector<int> seq;
	seq.pb(g);
	for (int i=0;i<n*m;++i) seq.pb((seq.back()*x+y)%z);
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) h[0][i][j]=seq[i*m+j];
	bool O=0;
	if (O) for (int i=0;i<n;++i,cout<<en) for (int j=0;j<m;++j) cout<<h[0][i][j]<<' ';
	if (O) cout<<en;
	if (O) cout<<p<<' '<<q<<en;
	for (int w=1;w<=p;++w)
    {
        int ee=w&1;
        int ff=!ee;
        for (int i=0;i<(1<<(w-1));++i) for (int j=0;j<m;++j) h[ee][i][j]=0;
        for (int i=1<<(w-1);i<n;++i) for (int j=0;j<m;++j) h[ee][i][j]=min(h[ff][i][j],h[ff][i-(1<<(w-1))][j]);
    }
    if (O) for (int i=0;i<n;++i,cout<<en) for (int j=0;j<m;++j) cout<<h[p&1][i][j]<<' ';
    if (O) cout<<en;
    for (int w=1;w<=q;++w)
    {
        int ee=(w+p)&1;
        int ff=!ee;
        if (O) cout<<ee<<' '<<ff<<endl;
        for (int i=0;i<n;++i) for (int j=0;j<(1<<(w-1));++j) h[ee][i][j]=0;
        for (int i=0;i<n;++i) for (int j=1<<(w-1);j<m;++j) h[ee][i][j]=min(h[ff][i][j],h[ff][i][j-(1<<(w-1))]);
    }
    int a1=a-e,b1=b-f,c=(p+q)&1;
    ll su=0;
    if (O) for (int i=0;i<n;++i,cout<<en) for (int j=0;j<m;++j) cout<<h[c][i][j]<<' ';
    if (O) cout<<en;
    for (int i=a-1;i<n;++i) for (int j=b-1;j<m;++j)
    {
        su+=min(min(h[c][i][j],h[c][i-a1][j]),min(h[c][i][j-b1],h[c][i-a1][j-b1]));
    }
    cout<<su;
}