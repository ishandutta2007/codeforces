#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

struct info{
	int u, v;
	info(int a, int b){
		u = a, v = b;
	}
};
 
stack<info> st;
map<Pi,int> M;
int Change;
ll res;

struct DisjointSet{
	int par[600005],num[600005];
	int xsz[600005],ysz[600005];
	ll cnt(int u){
		return 1ll*xsz[u]*ysz[u];
	}
	DisjointSet(){
		fup(i,0,600004,1){
			if(i<=300000)xsz[i]=1,ysz[i]=0;
			else xsz[i]=0,ysz[i]=1;
			par[i]=i,num[i]=1;
		}
	}
	int find(int u){
		if(u==par[u]) return u;
		return find(par[u]);
	}
	void merge(int u, int v){
		u=find(u),v=find(v);
		if(u==v)return;
		Change++;
		if (num[u] < num[v])
			swap(u, v);
		st.push(info(u, v));
		res-=cnt(u)+cnt(v);
		par[v] = u;
		num[u] += num[v];
		xsz[u] += xsz[v];
		ysz[u] += ysz[v];
		res+=cnt(u);
	}
	void rollback(){
		Change--;
		info I=st.top();
		st.pop();
		res-=cnt(I.u);
		par[I.u] = I.u;
		par[I.v] = I.v;
		num[I.u] -= num[I.v];
		xsz[I.u]-=xsz[I.v];
		ysz[I.u]-=ysz[I.v];
		res+=cnt(I.u)+cnt(I.v);
	}
} disj;

VPi v[1048576];
void upd(int node,int S,int E,int i,int j,Pi k)
{
	if (i > E || j < S)return;
	if (i <= S && j >= E)
	{
		v[node].pb(k);
		return;
	}
	upd(node<<1,S,(S+E)/2,i,j,k);
	upd(node<<1|1,(S+E)/2+1,E,i,j,k);
}
void solve(int node,int S,int E)
{
	if(S>E)return;
	int T=Change;
	for (auto [x,y]:v[node])
	{
        disj.merge(x,y);
    }
    if (S==E)printf("%lld ",res);
    else{
        solve(node*2,S,(S+E)/2);
        solve(node*2+1,(S+E)/2+1,E);
    }
    while (Change>T)disj.rollback();
}
int main(){
	int q;
	scanf("%d",&q);
	set<iii> S;
	fup(i,1,q,1){
		int x,y;
		scanf("%d%d",&x,&y);
		y+=300000;
		auto it=M.find(mp(x,y));
		if(it!=M.end()){
			upd(1,1,q,it->Y,i-1,mp(x,y));
			M.erase(it);
		}else{
			M[mp(x,y)]=i;
		}
	}
	for(auto it=M.begin();it!=M.end();it++){
		upd(1,1,q,it->Y,q,it->X);
	}
	solve(1,1,q);
}