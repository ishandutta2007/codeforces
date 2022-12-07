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
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
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
int s[500005], e[500005];
int n,q;

struct DisjointSet{
    int par[100005],num[100005];
    DisjointSet(){
		fup(i,0,100004,1)
            par[i]=i,num[i]=1;
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
        par[v] = u;
        num[u] += num[v];
    }
    void rollback(){
        Change--;
        info I=st.top();
        st.pop();
        par[I.u] = I.u;
        par[I.v] = I.v;
        num[I.u] -= num[I.v];
    }
} disj;

int o[500000],x[500000],y[500000];
Vi v[1048576];
void upd(int node,int S,int E,int i,int j,int k)
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
	for (int i:v[node])
	{
        disj.merge(x[i],y[i]);
    }
    if (S==E){
    	if(o[S]==2){
    		printf("%d\n",disj.num[disj.find(x[S])]);
    	}
    }
    else{
        solve(node*2,S,(S+E)/2);
        solve(node*2+1,(S+E)/2+1,E);
    }
    while (Change>T)disj.rollback();
}
Vi vv[500001];
int main(){
	int n,q,k,t=0;
	scanf("%d%d%d",&n,&q,&k);
	fup(i,0,q-1,1){
		scanf("%d",o+i);
		if(o[i]==1){
			scanf("%d%d",x+i,y+i);
			vv[t].pb(i);
			s[i]=i;
			e[i]=-1;
		}else if(o[i]==2){
			scanf("%d",x+i);
		}else{
			t++;
			if(t>=k){
				for(int z:vv[t-k])e[z]=i-1;
			}
		}
	}
	fup(i,0,q-1,1){
		if(o[i]==1){
			if(e[i]==-1)e[i]=q-1;
			upd(1,0,q-1,s[i],e[i],i);
		}
	}
	solve(1,0,q-1);
}