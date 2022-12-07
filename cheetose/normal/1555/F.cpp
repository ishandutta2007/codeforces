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

int x[500005],y[500005],z[500005];
int p[300005];
Vi v[300005];
int n,q;
struct H{
	int tree[1050000],lazy[1050000],hld[300005],cnt[300005],num[300005],idx[300005],parent[300005],depth[300005],cc;
	H(){
		MEM0(tree);
		MEM0(lazy);
		MEM0(cnt);
		cc=0;
	}
	void propagation(int node,int S,int E){
		if(lazy[node]!=0){
			tree[node]+=lazy[node]*(E-S+1);
			if(S!=E){
				lazy[2*node]+=lazy[node];
				lazy[2*node+1]+=lazy[node];
			}
			lazy[node]=0;
		}
	}
	void upd(int node, int S, int E, int i, int j, int val){
		propagation(node,S,E);
		if(i>E || j<S) return;
		if(j>=E && i<=S){
			lazy[node]+=val;
			propagation(node,S,E);
			return;
		}
		upd(2*node,S,(S+E)/2,i,j,val);
		upd(2*node+1,(S+E)/2+1,E,i,j,val);
		tree[node]=tree[2*node]+tree[2*node+1];
	}

	int find(int node, int S, int E, int i, int j){
		propagation(node,S,E);
		if (i > E || j < S)return 0;
		if (i <= S && j >= E)return tree[node];
		return find(node * 2, S, (S + E) / 2, i, j)+ find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	}
	void dfs(int N,int p,int d){
		parent[N]=p;
		depth[N]=d;
		cnt[N]=1;
		for(int next:v[N]){
			if(next==p)continue;
			dfs(next,N,d+1);
			cnt[N]+=cnt[next];
		}
	}
	void HLD(int N,int p){
		int c=-1;
		num[N]=++cc;
		idx[num[N]]=N;
		for(int next:v[N]){
			if(next==p)continue;
			if(c==-1 || cnt[next]>cnt[c])c=next;
		}
		if(c!=-1){
			hld[c]=hld[N];
			HLD(c,N);
		}
		for(int next:v[N]){
			if(next==p || next==c)continue;
			hld[next]=next;
			HLD(next,N);
		}
	}
	void eupd(int x,int y,int z){
		while(hld[x]!=hld[y]){
			if(depth[hld[x]]>depth[hld[y]]){
				upd(1,1,n,num[hld[x]],num[x],z);
				x=parent[hld[x]];
			}
			else{
				upd(1,1,n,num[hld[y]],num[y],z);
				y=parent[hld[y]];
			}
		}
		if(depth[x]>depth[y])swap(x,y);
		upd(1,1,n,num[x]+1,num[y],z);
	}
	int equery(int x,int y){
		int res=0;
		while(hld[x]!=hld[y]){
			if(depth[hld[x]]>depth[hld[y]]){
				res+=find(1,1,n,num[hld[x]],num[x]);
				x=parent[hld[x]];
			}
			else{
				res+=find(1,1,n,num[hld[y]],num[y]);
				y=parent[hld[y]];
			}
		}
		if(depth[x]>depth[y])swap(x,y);
		res+=find(1,1,n,num[x]+1,num[y]);
		return res;
	}
}H1,H2;

int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
void merge(int x,int y){p[find(x)]=find(y);}
int main() {
	scanf("%d%d",&n,&q);
	iota(p,p+n+1,0);
	fup(i,0,q-1,1){
		scanf("%d%d%d",x+i,y+i,z+i);
		if(find(x[i])!=find(y[i])){
			v[x[i]].pb(y[i]);
			v[y[i]].pb(x[i]);
			merge(x[i],y[i]);
		}
	}
	fup(i,1,n,1){
		if(H1.cnt[i]==0){
			H1.dfs(i,-1,0);
			H2.dfs(i,-1,0);
			H1.hld[i]=i;
			H2.hld[i]=i;
			H1.HLD(i,-1);
			H2.HLD(i,-1);
		}
	}
	iota(p,p+n+1,0);
	fup(i,0,q-1,1){
		if(find(x[i])!=find(y[i])){
			puts("YES");
			merge(x[i],y[i]);
			H1.eupd(x[i],y[i],z[i]);
		}else{
			if(H2.equery(x[i],y[i])>=1){
				puts("NO");
			}else{
				int t=H1.equery(x[i],y[i]);
				if((t+z[i])%2==0){
					puts("NO");
				}else{
					puts("YES");
					H2.eupd(x[i],y[i],1);
				}
			}
		}
	}
}