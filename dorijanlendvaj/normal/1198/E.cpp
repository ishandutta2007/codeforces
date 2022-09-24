#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
 
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
 
const int N=300010;
int n,m,a[N],b[N],c[N],d[N];
vector<int> x,y;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
 
template <int MAXV, class T = ll> struct Dinic {
    const static bool SCALING = false; // non-scaling = V^2E, Scaling=VElog(U) with higher constant
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    struct edge {
        int to, rev;
        T cap, flow;
    };
    int s = 0, t = MAXV - 1;
 
    int level[MAXV], ptr[MAXV];
    vector<edge> adj[MAXV],ad1[MAXV];
    void addEdge(int a, int b, T cap, bool isDirected = true) {
        adj[a].push_back({b, adj[b].size(), cap, 0});
        adj[b].push_back({a, adj[a].size() - 1, isDirected ? 0 : cap, 0});
        ad1[a].push_back({b, adj[b].size(), cap, 0});
        ad1[b].push_back({a, adj[a].size() - 1, isDirected ? 0 : cap, 0});
    }
    bool bfs() {
        queue<int> q({s});
        memset(level,-1,sizeof(level));
        level[s] = 0;
        while (!q.empty() && level[t] == -1) {
            int v = q.front();
            q.pop();
            for (auto e : adj[v]) {
                if (level[e.to] == -1 && e.flow < e.cap && (!SCALING || e.cap - e.flow >= lim)) {
                    q.push(e.to);
                    level[e.to] = level[v] + 1;
                }
            }
        }
        return level[t] != -1;
    }
    T dfs(int v, T flow) {
        if (v == t || !flow)
            return flow;
        for (; ptr[v] < adj[v].size(); ptr[v]++) {
            edge &e = adj[v][ptr[v]];
            if (level[e.to] != level[v] + 1)
                continue;
            if (T pushed = dfs(e.to, min(flow, e.cap - e.flow))) {
                e.flow += pushed;
                adj[e.to][e.rev].flow -= pushed;
                ad1[e.to][e.rev].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    void calc(int lef) {
        long long flow = 0;
        for (lim = SCALING ? (1 << 30) : 1; lim > 0; lim >>= 1) {
            while (bfs()) {
            	for (int i=0;i<MAXV;++i) for (auto&e:ad1[i]) e.flow=0;
                memset(ptr,0,sizeof(ptr));
                while (T pushed = dfs(s, INF))
                    flow += pushed;
            }
        }
        cout<<flow<<endl;
    }
};
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>m>>n;
	if (n==0)
	{
		cout<<0;
		exit(0);
	}
	for (int i=0;i<n;++i)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		--a[i];
		--b[i];
		x.pb(a[i]);
		x.pb(c[i]);
		y.pb(b[i]);
		y.pb(d[i]);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	Dinic<1002,int> solver;
	for (int i=1;i<x.size();++i) solver.addEdge(0,i,x[i]-x[i-1]);
	int cnt=x.size()+y.size();
	for (int i=x.size();i<x.size()+y.size()-1;++i) solver.addEdge(i,cnt-1,y[i-x.size()+1]-y[i-x.size()]);
	solver.s=0;
	solver.t=cnt-1;
	for (int i=0;i<n;++i)
	{
		int aa=lower_bound(x.begin(),x.end(),a[i])-x.begin();
		int bb=lower_bound(x.begin(),x.end(),c[i])-x.begin();
		int cc=lower_bound(y.begin(),y.end(),b[i])-y.begin();
		int dd=lower_bound(y.begin(),y.end(),d[i])-y.begin();
		for (int j=aa;j<bb;++j) for (int k=cc;k<dd;++k) solver.addEdge(j+1,k+x.size(),min(x[j+1]-x[j],y[k+1]-y[k]));
	}
	solver.calc(x.size()-1);
}