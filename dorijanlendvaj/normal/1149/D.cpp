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

const int N=75,MO=100;
int n,m,a,b,xxx,midi[N],z;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int par[N],sz[N],ge[N];
gp_hash_table<int,int> dist[N];
vector<int> ch[2][N];
bool bio[N],bio1[N];
vector<pair<int,signed>> ht[N][MO+10];

void update(unsigned i,int k,signed x)
{
	int j=i%MO;
	for (auto &a: ht[k][j])
	{
		if (a.x==i)
		{
			a.y=max(a.y,x);
			return;
		}
	}
	ht[k][j].pb({i,x});
}

signed que(unsigned i,int k)
{
	int j=i%MO;
	for (auto a: ht[k][j])
	{
		if (a.x==i) return a.y;
	}
	return -MOD;
}


int find(int a)
{
	if (a==par[a]) return a;
	return par[a]=find(par[a]);
}

void merge(int a,int b)
{
	a=find(a);
	b=find(b);
	if (a==b) return;
	par[a]=b;
	sz[b]+=sz[a];
	sz[a]=0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back((rand()%MOD+13893829)%MOD);
	cin>>n>>m>>a>>b;
	for (int i=1;i<=n;++i) par[i]=i,sz[i]=1;
	for (int i=0;i<m;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if (z==a) ch[0][x].pb(y),ch[0][y].pb(x);
		else ch[1][x].pb(y),ch[1][y].pb(x);
		if (z==a) merge(x,y);
	}
	//for (int i=1;i<=n;++i) cout<<sz[i]<<' '<<find(i)<<en;
	memset(ge,-1,sizeof(ge));
	for (int i=1;i<=n;++i)
	{
		//cout<<i<<' '<<ge[i]<<' '<<bio1[i]<<' '<<sz[find(i)]<<en;
		if (bio1[i]) continue;
		if (sz[i]>=4)
		{
			for (int j=1;j<=n;++j)
			{
				//cout<<find(i)<<' '<<find(j)<<' ';
				if (find(j)==find(i))
				{
					bio1[j]=1;
					ge[j]=xxx;
					//cout<<i<<' '<<j;
				}
				//cout<<en;
			}
			++xxx;
		}
		else
		{
			bio1[i]=1;
			ge[i]=-1;
		}
	}
	cout<<en;
	priority_queue<pair<pii,int>> pq;
	pq.push({{0,1},0});
	memset(midi,0x3f3f3f3f,sizeof(midi));
	const double HC=2;
	int z=0;
	while (pq.size())
	{
		int di=pq.top().x.x,j=pq.top().x.y,mask=pq.top().y;
		if (ge[j]!=-1) mask|=1<<ge[j];
		pq.pop();
		if (-di/1.L/midi[j]>=HC) continue;
		if (que(mask,j)!=-MOD) continue;
		update(mask,j,-di);
		midi[j]=min(midi[j],-di);
		if (!bio[j])
		{
			bio[j]=1;
			++z;
		}
		if (z==n) break;
		//cout<<ge[j]<<' '<<j<<' '<<mask<<' '<<di<<en;
		for (auto d: ch[0][j]) pq.push({{di-a,d},mask});
		for (auto d: ch[1][j]) if ((ge[d]==-1 && find(d)!=find(j)) || (ge[d]!=-1 && (mask&(1<<ge[d]))==0))
		{
			//cout<<"sending "<<j<<' '<<d<<' '<<mask<<' '<<find(d)<<' '<<find(j)<<en;
			pq.push({{di-b,d},mask});
		}
	}
	for (int i=1;i<=n;++i)
	{
		cout<<midi[i]<<' ';
	}
}