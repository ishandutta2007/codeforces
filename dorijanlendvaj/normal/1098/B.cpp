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

int sub(int a,int b)
{
	return (a-b+MOD)%MOD;
}

int add(int a,int b)
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

const int N=300010;
int n,mx;
string h[N];
string m1[N],te[N];
int re;
map<char,int> cnt[N];
string m="GTAC";
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(raand()%MOD+13893829);
	cin>>n>>mx;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<mx;++j) m1[i].push_back(' ');
		te[i]=m1[i];
	}
	for (int j=0;j<mx;++j)
	{
		for (int i=0;i<n;++i) ++cnt[j][h[i][j]];
	}
	for (int a=0;a<4;++a)
	{
		for (int b=0;b<4;++b)
		{
			if (a==b) continue;
			for (int c=0;c<4;++c)
			{
				if (a==c || b==c) continue;
				int d;
				for (int i=0;i<4;++i) if (i!=a && i!=b && i!=c) d=i;
				int tm=0;
				for (int i=0;i<n;++i)
				{
					int z1=0,z2=0;
					for (int j=0;j<mx;++j)
					{
						char r;
						if (i%2)
						{
							if (j%2) r=m[a];
							else r=m[b];
						}
						else
						{
							if (j%2) r=m[c];
							else r=m[d];
						}
						if (h[i][j]==r) ++z1;
					}
					for (int j=0;j<mx;++j)
					{
						char r;
						if (i%2)
						{
							if (j%2) r=m[b];
							else r=m[a];
						}
						else
						{
							if (j%2) r=m[d];
							else r=m[c];
						}
						if (h[i][j]==r) ++z2;
					}
					if (z2>z1)
					{
						for (int j=0;j<mx;++j)
						{
							char r;
							if (i%2)
							{
								if (j%2) r=m[b];
								else r=m[a];
							}
							else
							{
								if (j%2) r=m[d];
								else r=m[c];
							}
							te[i][j]=r;
						}
					}
					else
					{
						for (int j=0;j<mx;++j)
						{
							char r;
							if (i%2)
							{
								if (j%2) r=m[a];
								else r=m[b];
							}
							else
							{
								if (j%2) r=m[c];
								else r=m[d];
							}
							te[i][j]=r;
						}
					}
					tm+=max(z1,z2);
				}
				if (tm>re)
				{
					for (int i=0;i<n;++i) m1[i]=te[i];
					re=tm;
				}
			}
		}
	}
	for (int a=1;a<4;++a)
	{
		int b,c;
		if (a==1) b=2,c=3;
		else if (a==2) b=1,c=3;
		else b=1,c=2;
		for (int k=0;k<2;++k) for (int l=0;l<2;++l) for (int q=0;q<2;++q)
		{
			int tmp=0;
			for (int i=0;i<mx;++i)
			{
				if (i%2==k)
				{
					int za=0,z0=0;
					int u[2];
					u[0]=a;
					u[1]=0;
					for (int j=0;j<n;++j)
					{
						if (h[j][i]==m[u[(j+l)%2]]) ++za;
						else if (h[j][i]==m[u[(j+1+l)%2]]) ++z0;
					}
					if (za>z0)
					{
						for (int j=0;j<n;++j) te[j][i]=m[u[(j+l)%2]];
						tmp+=za;
					}
					else
					{
						for (int j=0;j<n;++j) te[j][i]=m[u[(j+l+1)%2]];
						tmp+=z0;
					}
				}
				else
				{
					int za=0,z0=0;
					int u[2];
					u[0]=b;
					u[1]=c;
					for (int j=0;j<n;++j)
					{
						if (h[j][i]==m[u[(j+q)%2]]) ++za;
						else if (h[j][i]==m[u[(j+1+q)%2]]) ++z0;
					}
					if (za>z0)
					{
						for (int j=0;j<n;++j) te[j][i]=m[u[(j+q)%2]];
						tmp+=za;
					}
					else
					{
						for (int j=0;j<n;++j) te[j][i]=m[u[(j+q+1)%2]];
						tmp+=z0;
					}
				}
			}
			if (tmp>re)
			{
				re=tmp;
				for (int i=0;i<n;++i) m1[i]=te[i];
			}
		}
	}
	for (int i=0;i<n;++i) cout<<m1[i]<<en;
}