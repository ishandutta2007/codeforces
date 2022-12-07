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
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int a[500005];
ll tree[4][1050000];
void merge(int node,int S,int E){
	int M=S+E>>1;
	int L=node<<1,R=L+1;
	tree[0][node]=(tree[1][L]*tree[0][R])%MOD;
	tree[1][node]=(tree[1][L]*tree[1][R])%MOD;
	tree[2][node]=(tree[2][L]*tree[1][R])%MOD;
	tree[3][node]=(tree[2][L]*tree[0][R])%MOD;
	if(a[M]==1){
		int lz=M-S+1,rz=E-M;
		if(rz>=2)tree[0][node]=(tree[0][node]+tree[0][L]*tree[3][R]*(9-a[M+1]))%MOD;
		tree[1][node]=(tree[1][node]+tree[0][L]*tree[2][R]*(9-a[M+1]))%MOD;
		if(lz>=2)tree[2][node]=(tree[2][node]+tree[3][L]*tree[2][R]*(9-a[M+1]))%MOD;
		if(lz>=2 && rz>=2)tree[3][node]=(tree[3][node]+tree[3][L]*tree[3][R]*(9-a[M+1]))%MOD;
	}
}
void init(int node,int S,int E){
	if(S==E){
		fup(i,0,3,1)tree[i][node]=1;
		tree[1][node]=a[S]+1;
		return;
	}
	int M=S+E>>1;
	int L=node<<1,R=L+1;
	init(L,S,M);
	init(R,M+1,E);
	merge(node,S,E);
}
void upd(int node,int S,int E,int k){
	if(S==E){
		tree[1][node]=a[S]+1;
		return;
	}
	int M=S+E>>1;
	if(k<=M)upd(node<<1,S,M,k);
	else upd(node<<1|1,M+1,E,k);
	merge(node,S,E);
}
char s[500005];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	fup(i,1,n,1)a[i]=s[i]-'0';
	init(1,1,n);
	while(q--){
		int i,x;
		scanf("%d%d",&i,&x);
		a[i]=x;
		upd(1,1,n,i);
		printf("%lld\n",tree[1][1]);
	}
}