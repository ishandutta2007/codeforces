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

int a[2000001], tree[2097152<<1], lazy[2097152<<1];
void propagation(int node,int S,int E){
	if(lazy[node]!=0){
		tree[node]+=lazy[node];
		if(S!=E){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}
void upd(int node,int S,int E,int i,int j,int val){
	propagation(node,S,E);
	if(i>E || j<S) return;
	if(j>=E && i<=S){
		lazy[node]+=val;
		propagation(node,S,E);
		return;
	}
	upd(2*node,S,(S+E)/2,i,j,val);
	upd(2*node+1,(S+E)/2+1,E,i,j,val);
	tree[node]=min(tree[2*node],tree[2*node+1]);
}
int find(int node,int S,int E,int i,int j){
	propagation(node,S,E);
	if(i>E || j<S)return INF;
	if(j>=E && i<=S)return tree[node];
	return min(find(node*2,S,(S+E)/2,i,j),find(2*node+1,(S+E)/2+1,E,i,j));
}
iii e[300000];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	m<<=1;
	fup(i,0,n-1,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x<<=1,y<<=1;
		e[i]=iii(z,x,y);
	}
	sort(e,e+n);
	int ans=INF;
	for(int i=0,j=0;i<n && j<n;j++){
		auto [z,x,y]=e[j];
		upd(1,2,m,x,y,1);
		while(i<j){
			tie(z,x,y)=e[i];
			if(find(1,2,m,x,y)>1){
				upd(1,2,m,x,y,-1);
				i++;
			}else break;
		}
		if(find(1,2,m,2,m)>=1){
			ans=min(ans,get<0>(e[j])-get<0>(e[i]));
		}
	}
	printf("%d\n",ans);
}