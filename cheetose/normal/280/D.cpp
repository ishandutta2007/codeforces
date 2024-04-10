#include <bits/stdc++.h>
#include <ext/rope>
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
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
using namespace __gnu_cxx;
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
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int n,k=20;
struct A{
	int d[4][21]={0};
	A(){
		fup(i,0,3,1)fup(j,0,k,1)d[i][j]=j?-INF:0;
	}
}tree[262144];
int a[100001];

A merge(const A &L,const A &R){
	A res;
	fup(k1,1,k,1){
		res.d[0][k1]=max({res.d[0][k1], L.d[0][k1], L.d[1][k1], R.d[0][k1], R.d[2][k1]});
		res.d[1][k1]=max({res.d[1][k1], R.d[1][k1], R.d[3][k1]});
		res.d[2][k1]=max({res.d[2][k1], L.d[2][k1], L.d[3][k1]});
	}
	fup(k1,1,k,1){
		fup(k2,1,k,1){
			if(k1+k2<=k){
				int K=k1+k2;
				res.d[0][K]=max({res.d[0][K], L.d[0][k1]+R.d[0][k2], L.d[0][k1]+R.d[2][k2], L.d[1][k1]+R.d[0][k2]});
				res.d[1][K]=max({res.d[1][K], L.d[0][k1]+R.d[1][k2], L.d[0][k1]+R.d[3][k2], L.d[1][k1]+R.d[1][k2]});
				res.d[2][K]=max({res.d[2][K], L.d[2][k1]+R.d[0][k2], L.d[2][k1]+R.d[2][k2], L.d[3][k1]+R.d[0][k2]});
				res.d[3][K]=max({res.d[3][K], L.d[2][k1]+R.d[1][k2], L.d[2][k1]+R.d[3][k2], L.d[3][k1]+R.d[1][k2]});
			}
			if(k1+k2-1<=k){
				int K=k1+k2-1;
				res.d[0][K]=max(res.d[0][K], L.d[1][k1]+R.d[2][k2]);
				res.d[1][K]=max(res.d[1][K], L.d[1][k1]+R.d[3][k2]);
				res.d[2][K]=max(res.d[2][K], L.d[3][k1]+R.d[2][k2]);
				res.d[3][K]=max(res.d[3][K], L.d[3][k1]+R.d[3][k2]);
			}
		}
	}
	return res;
}
void init(int node,int S,int E){
	if(S==E){
		tree[node].d[3][1]=a[S];
		return;
	}
	int M=S+E>>1;
	init(node<<1,S,M);init(node<<1|1,M+1,E);
	tree[node]=merge(tree[node<<1],tree[node<<1|1]);
}
void upd(int node,int S,int E,int k,int dif){
	if(S==E){
		tree[node].d[3][1]=dif;
		return;
	}
	int M=S+E>>1;
	if(k<=M)upd(node<<1,S,M,k,dif);
	else upd(node<<1|1,M+1,E,k,dif);
	tree[node]=merge(tree[node<<1],tree[node<<1|1]);
}
A find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S){
		A t;
		t.d[0][0]=-INF-5;
		return t;
	}
	if (i <= S && j >= E)return tree[node];
	A L=find(node * 2, S, (S + E) / 2, i, j),R=find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	if(L.d[0][0]==-INF-5)return R;
	if(R.d[0][0]==-INF-5)return L;
	return merge(L,R);
}
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	init(1,1,n);
	int q;
	scanf("%d",&q);
	while(q--){
		int o,x,y,z;
		scanf("%d%d%d",&o,&x,&y);
		if(o==0){
			upd(1,1,n,x,y);
		}else{
			scanf("%d",&z);
			A t=find(1,1,n,x,y);
			int ans=0;
			fup(i,0,3,1)fup(j,0,z,1)ans=max(ans,t.d[i][j]);
			printf("%d\n",ans);
		}
	}
}