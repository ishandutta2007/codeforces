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
int n,m,t,maX[N],maY[N],miX[N],miY[N];
string h[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void maxi(int&a,int b)
{
	a=max(a,b);
}

void mini(int&a,int b)
{
	a=min(a,b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>t;
	while (t--)
	{
		memset(maX,-1,sizeof(maX));
		memset(maY,-1,sizeof(maY));
		memset(miX,1,sizeof(miX));
		memset(miY,1,sizeof(miY));
		cin>>n>>m;
		int mal=-1;
		for (int i=0;i<n;++i) cin>>h[i];
		for (int i=0;i<n;++i) for (int j=0;j<m;++j)
		{
			char c=h[i][j];
			if (c>='a')
			{
				mal=max(mal,c-'a');
			}
			int z=c-'a';
			maxi(maX[z],i);
			maxi(maY[z],j);
			mini(miX[z],i);
			mini(miY[z],j);
		}
		vector<pair<pii,pii>> v;
		int pX=-1,pY=-1;
		bool pos=1;
		for (int i=mal;i>=0;--i)
		{
			if (maX[i]==-1)
			{
				v.pb({{pX,pY},{pX,pY}});
				continue;
			}
			if (maX[i]==miX[i] && maY[i]==miY[i])
			{
				v.pb({{maX[i],maY[i]},{maX[i],maY[i]}});
				h[maX[i]][maY[i]]='X';
				pX=maX[i];
				pY=maY[i];
				continue;
			}
			if (maX[i]==miX[i])
			{
				for (int j=miY[i];j<=maY[i];++j) if (h[maX[i]][j]!='X' && h[maX[i]][j]!=i+'a') pos=0;
				for (int j=miY[i];j<=maY[i];++j) h[maX[i]][j]='X';
				pX=maX[i];
				pY=maY[i];
				v.pb({{miX[i],miY[i]},{maX[i],maY[i]}});
				continue;
			}
			if (maY[i]==miY[i])
			{
				for (int j=miX[i];j<=maX[i];++j) if (h[j][maY[i]]!='X' && h[j][maY[i]]!=i+'a') pos=0;
				for (int j=miX[i];j<=maX[i];++j) h[j][maY[i]]='X';
				pX=maX[i];
				pY=maY[i];
				v.pb({{miX[i],miY[i]},{maX[i],maY[i]}});
				continue;
			}
			pos=0;
		}
		if (!pos) 
		{
			cout<<"NO"<<en;
			continue;
		}
		cout<<"YES"<<en;
		reverse(v.begin(),v.end());
		cout<<v.size()<<en;
		for (auto a: v) cout<<a.x.x+1<<' '<<a.x.y+1<<' '<<a.y.x+1<<' '<<a.y.y+1<<en;
	}
}