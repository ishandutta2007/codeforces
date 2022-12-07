#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi vv[2002];
int a[2002],sum[2002];
int inter(int l1,int r1,int l2,int r2){
	int res=min(r1,r2)-max(l1,l2)+1;
	if(res<0)res=0;
	return res;
}
struct TREE{
	int tree[4096]={0},lazy[4096]={0};
	void propagation(int node, int S, int E)
	{
		if (lazy[node] != 0)
		{
			tree[node] += lazy[node] * (E - S + 1);
			if (S != E)
			{
				lazy[2 * node] += lazy[node];
				lazy[2 * node + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	void upd(int node, int S, int E, int i, int j, ll val)
	{
		propagation(node, S, E);
		if (i > E || j < S) return;
		if (j >= E && i <= S)
		{
			lazy[node] += val;
			propagation(node, S, E);
			return;
		}
		upd(2 * node, S, (S + E) / 2, i, j, val);
		upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
	int find(int node, int S, int E, int i, int j)
	{
		propagation(node, S, E);
		if (i > E || j < S) return 0;
		if (j >= E && i <= S) return tree[node];
		return find(node * 2, S, (S + E) / 2, i, j) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j);
	}
}T[2002];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,1,m,1){
		int l1,r1;
		scanf("%d%d",&l1,&r1);
		fup(j,1,n-k+1,1){
			int l2=j,r2=j+k-1;
			a[j]=inter(l1,r1,l2,r2);
			sum[j]+=a[j];
			vv[a[j]].pb(j);
		}
		fup(j,0,n,1)reverse(ALL(vv[j]));
		fup(j,1,n-k+1,1){
			vv[a[j]].pop_back();
			if(a[j]==0)continue;
			T[j].upd(1,1,n,j,j,a[j]);
			if(vv[a[j]-1].empty())continue;
			int t=vv[a[j]-1].back();
			T[j].upd(1,1,n,t,min(n-k+1,t+a[j]-1),-1);
		}
	}
	int ans=0;
	fup(i,1,n-k+1,1){
		ans=max(ans,sum[i]);
		fup(j,i+1,n-k+1,1){
			ans=max(ans,sum[i]+sum[j]-T[i].find(1,1,n,1,j));
		}
	}
	printf("%d\n",ans);
}