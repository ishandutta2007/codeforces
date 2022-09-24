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

const int N=200010;
int n,ss[N],dep[N],par[20][N],root=1,dex,qc,cl;
vector<int> mm;
bool kill;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool dead[N];
bool bio[N];
vector<int> ch[N];

void dfs(int i)
{
	par[0][root]=root;
	bio[i]=1;
	ss[i]=1;
	for (auto d: ch[i]) if (!bio[d] && !dead[d])
	{
		if (root==1) dep[d]=dep[i]+1;
		dfs(d);
		par[0][d]=i;
		ss[i]+=ss[d];
	}
}

void deadDFS(int i,int j)
{
	bio[i]=1;
	if (i==j) kill=1;
	dead[i]=!kill;
	for (auto d: ch[i]) if (!bio[d] && !dead[d]) deadDFS(d,j);
	if (i==j) kill=0;
}

void deadDFS2(int i,int j)
{
	bio[i]=1;
	if (i==j) kill=1;
	dead[i]=kill;
	for (auto d: ch[i]) if (!bio[d] && !dead[d]) deadDFS2(d,j);
	if (i==j) kill=0;
}

void setDead(int i,bool a)
{
	memset(bio,0,sizeof(bio));
	if (a==0) kill=0,deadDFS(root,i);
	else kill=0,deadDFS2(root,i);
}

int dist(int a)
{
	cout<<"d "<<a<<endl;
	int x;
	cin>>x;
	return x;
}

void eliminate()
{
	memset(bio,0,sizeof(bio));
	memset(ss,0,sizeof(ss));
	dfs(root);
	for (int i=0;i<17;++i) for (int j=1;j<=n;++j) if (!dead[j]) par[i+1][j]=par[i][par[i][j]];
	vector<int> m;
	for (int i=1;i<=n;++i) if (!dead[i]) m.pb(i);
	if (m.size()==1)
	{
		cout<<"! "<<m[0]<<endl;
		exit(0);
	}
	//cout<<m.size()<<endl;
	for (int i=1;i<=n;++i) if (!dead[i] && ss[i]*2>=m.size())
	{
		bool moz=1;
		for (auto d: ch[i]) if (ss[d]<ss[i] && ss[d]*2>m.size()) moz=0;
		//cout<<i<<' '<<moz<<' '<<ss[3]<<endl;
		if (!moz) continue;
		int di=dist(i);
		++qc;
		if (di==0)
		{
			cout<<"! "<<i<<endl;
			exit(0);
		}
		int dLCA=(dep[i]+dex-di)/2;
		int dD=dep[i]-dLCA;
		int ii=i;
		for (int j=0;j<18;++j) if (dD&(1<<j)) ii=par[j][ii];
		if (ii==i)
		{
			cout<<"s "<<i<<endl;
			++qc;
			int ans;
			cin>>ans;
			if (ans==-1) exit(0);
			setDead(ans,0);
			root=ans;
		}
		else if (ii==root && dep[root]==dex)
		{
			cout<<"! "<<root<<endl;
			exit(0);
		}
		else
		{
			//cout<<"s "<<root<<endl;
			//++qc;
			//int ans;
			//cin>>ans;
			//if (ans==-1) exit(0);
			setDead(i,1);
			//root=ans;
		}
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cl=clock();
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		ch[a].pb(b);
		ch[b].pb(a);
	}
	dex=dist(1);
	while (1) eliminate();
}