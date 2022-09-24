#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

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

const int N=300010;
int n,a[N],b[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<pair<pii,pii>> sol;
bool bio[10][10];
pii pos[2][N];
pii port[10][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n;
	for (int i=0;i<n;++i) cin>>a[i];
	for (int i=0;i<n;++i) cin>>b[i];
	int cl=clock();
	if (n==1) cout<<0;
	else if (n==2)
	{
		if (a[0]==1 && b[0]==1) cout<<0;
		else if (a[0]==1 && b[0]==2) cout<<"1\n1 1 1 2";
		else if (a[0]==2 && b[0]==1) cout<<"1\n1 1 2 1";
		else cout<<"1\n1 1 2 2";
	}
	else if (n<=5)
	{
		while (clock()-cl<=1.7*CLOCKS_PER_SEC)
		{
			//cout<<1<<endl;
			memset(bio,0,sizeof(bio));
			sol.clear();
			int k=rand()%(n+2);
			for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) port[i][j]={0,0};
			for (int i=0;i<k;++i)
			{
				int a=rand()%n+1,b=rand()%n+1;
				while (bio[a][b]) a=rand()%n+1,b=rand()%n+1;
				bio[a][b]=1;
				int c=rand()%n+1,d=rand()%n+1;
				while (bio[c][d]) c=rand()%n+1,d=rand()%n+1;
				sol.pb({{a,b},{c,d}});
				port[a][b]={c,d};
				port[c][d]={a,b};
				bio[c][d]=1;
			}
			bool flag=1;
			for (int i=0;i<n;++i)
			{
				int x=i+1,y=1,it=0;
				while (y<=n && it<=100)
				{
					if (port[x][y]!=mp(0,0))
					{
						auto a=port[x][y];
						x=a.x;
						y=a.y;
					}
					++y;
					++it;
				}
				if (x!=a[i] || y!=n+1)
				{
					flag=0;
					break;
				}
			}
			if (flag)
			{
				for (int i=0;i<n;++i)
				{
					int x=1,y=i+1,it=0;
					while (x<=n && it<=100)
					{
						if (port[x][y]!=mp(0,0))
						{
							auto a=port[x][y];
							x=a.x;
							y=a.y;
						}
						++x;
						++it;
					}
					if (y!=b[i] || x!=n+1)
					{
						flag=0;
						break;
					}
				}
			}
			if (flag)
			{
				cout<<sol.size()<<endl;
				for (auto a: sol) cout<<a.x.x<<' '<<a.x.y<<' '<<a.y.x<<' '<<a.y.y<<en;
				exit(0);
			}
		}
	}
	else
	{
		int r1=-1,rn=-1,c1=-1,cn=-1;
		for (int i=0;i<n;++i)
		{
			if (a[i]==1) r1=i;
			if (a[i]==n) rn=i;
			if (b[i]==1) c1=i;
			if (b[i]==n) cn=i;
		}
		for (int i=2;i<n;++i)
		{
			pos[0][i]={i,n};
			pos[1][i]={n,i};
		}
		pos[0][1]={2,n-2};
		pos[1][1]={n-2,2};
		pos[0][n]={n-1,n-2};
		pos[1][n]={n-2,n-1};
		sol.pb({{1,1},{2,2}});
		sol.pb({{1,n},{2,n-1}});
		sol.pb({{n,1},{n-1,2}});
		sol.pb({{n,n},{n-1,n-1}});
		for (int i=2;i<n;++i)
		{
			sol.pb({{i,1},pos[0][a[i-1]]});
			sol.pb({{1,i},pos[1][b[i-1]]});
		}
		sol.pb({{3,2},pos[1][b[0]]});
		sol.pb({{2,3},pos[0][a[0]]});
		sol.pb({{3,n-1},pos[1][b[n-1]]});
		sol.pb({{n-1,3},pos[0][a[n-1]]});
		cout<<sol.size()<<endl;
		for (auto a: sol) cout<<a.x.x<<' '<<a.x.y<<' '<<a.y.x<<' '<<a.y.y<<en;
	}
}