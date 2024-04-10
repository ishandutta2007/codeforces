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

const int N=410;
int n,m; //v=2i, c=2i+1
bool con[N],bio[N];
vi ch[N];
vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;
vi u;

void dfs(int i)
{
	if (bio[i]) return;
	bio[i]=1;
	u[i]=1;
	for (auto a: ch[i]) dfs(a);
}

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT(int n) {
	order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

bool pos(vi mad)
{
	g.clear();
	gt.clear();
	g.resize(2*n);
	gt.resize(2*n);
	u.assign(2*n,0);
	memset(bio,0,sizeof(bio));
	for (auto a: mad) dfs(a);
	//for (int i=0;i<n*2;++i) cout<<u[i]<<' ';
	//cout<<endl;
	for (int i=0;i<n;++i) if (u[i*2] && u[i*2+1]) return 0;
	//cout<<"tus"<<endl;
	vi pos;
	for (int i=0;i<n;++i) if (!u[i*2] && !u[i*2+1]) pos.pb(i*2),pos.pb(i*2+1);
	for (int i=0;i<pos.size();++i)
	{
		for (auto j: ch[pos[i]]) if (!u[j] && !u[j^1])
		{
			int z=lower_bound(pos.begin(),pos.end(),j)-pos.begin();
			g[i].pb(z);
			gt[z].pb(i);
		}
	}
	return solve_2SAT(pos.size());
}

bool _po(string a)
{
	vi re;
	for (int i=0;i<a.size();++i) if (con[a[i]-'a']) re.pb(i*2+1);
	else re.pb(i*2);
	return pos(re);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	string r;
	cin>>r;
	for (int i=0;i<r.size();++i) con[i]=r[i]=='C';
	cin>>n>>m;
	for (int i=0;i<m;++i)
	{
		int a,b;
		char c,d;
		cin>>a>>c>>b>>d;
		if (c=='V') a=(a-1)*2;
		else a=a*2-1;
		if (d=='V') b=(b-1)*2;
		else b=b*2-1;
		ch[a].pb(b);
		ch[b^1].pb(a^1);
	}
	for (int i=0;i<n*2;++i)
	{
		sort(ch[i].begin(),ch[i].end());
		ch[i].erase(unique(ch[i].begin(),ch[i].end()),ch[i].end());
		//for (auto a: ch[i]) cout<<a<<' ';
		//cout<<endl;
	}
	string h;
	cin>>h;
	int smC=-1,smV=-1;
	for (int i=0;i<r.size();++i) if (con[i])
	{
		smC=i;
		break;
	}
	for (int i=0;i<r.size();++i) if (!con[i])
	{
		smV=i;
		break;
	}
	if (smC==-1)
	{
		for (int i=0;i<2*n;i+=2) for (auto a: ch[i]) if (a&1)
		{
			cout<<-1;
			exit(0);
		}
		cout<<h;
		exit(0);
	}
	if (smV==-1)
	{
		for (int i=1;i<2*n;i+=2) for (auto a: ch[i]) if (a%2==0)
		{
			cout<<-1;
			exit(0);
		}
		cout<<h;
		exit(0);
	}
	if (_po(h))
	{
		cout<<h;
		exit(0);
	}
	vi pos;
	for (int i=0;i<n;++i) if (h[i]!=r.size()-1+'a') pos.pb(i);
	reverse(pos.begin(),pos.end());
	for (auto po: pos)
	{
		string u=h.substr(0,po);
		u.pb(h[po]+1);
		if (_po(u))
		{
			for (int i=po+1;i<n;++i)
			{
				u.pb('a');
				if (!_po(u)) u[i]='a'+max(smC,smV);
			}
			cout<<u;
			exit(0);
		}
		int z=con[u.back()-'a'];
		while (u.back()<'a'+r.size()-1 && con[u.back()-'a']==z) ++u[u.size()-1];
		if (_po(u))
		{
			for (int i=po+1;i<n;++i)
			{
				u.pb('a');
				if (!_po(u)) u[i]='a'+max(smC,smV);
			}
			cout<<u;
			exit(0);
		}
	}
	cout<<-1;
}