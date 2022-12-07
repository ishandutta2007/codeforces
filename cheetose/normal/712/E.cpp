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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

struct D{
	db d1,d2;
}tree[262144];

db p[100005];
void init(int node,int S,int E){
	if(S==E){
		tree[node].d1=tree[node].d2=p[S];
		return;
	}
	int L=node<<1,R=L+1,M=S+E>>1;
	init(L,S,M);init(R,M+1,E);
	tree[node].d1=tree[R].d1+tree[L].d1*tree[R].d2*(1-tree[R].d1)/(1-tree[L].d1*(1-tree[R].d2));
	tree[node].d2=tree[L].d2*tree[R].d2/(1+tree[L].d1*(tree[R].d2-1));
}
void upd(int node,int S,int E,int k){
	if(S==E){
		tree[node].d1=tree[node].d2=p[S];
		return;
	}
	int L=node<<1,R=L+1,M=S+E>>1;
	if(k<=M)upd(L,S,M,k);
	else upd(R,M+1,E,k);
	tree[node].d1=tree[R].d1+tree[L].d1*tree[R].d2*(1-tree[R].d1)/(1-tree[L].d1*(1-tree[R].d2));
	tree[node].d2=tree[L].d2*tree[R].d2/(1+tree[L].d1*(tree[R].d2-1));
}
D find(int node,int S,int E,int i,int j){
	if (i > E || j < S)return {-1,-1};
	if (i <= S && j >= E)return tree[node];
	int L=node<<1,R=L+1,M=S+E>>1;
	D l=find(L,S,M,i,j),r=find(R,M+1,E,i,j);
	if(l.d1==-1)return r;
	if(r.d1==-1)return l;
	D res;
	res.d1=r.d1+l.d1*r.d2*(1-r.d1)/(1-l.d1*(1-r.d2));
	res.d2=l.d2*r.d2/(1+l.d1*(r.d2-1));
	return res;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,1,n,1){
		int a,b;
		scanf("%d%d",&a,&b);
		p[i]=1.0*a/b;
	}
	init(1,1,n);
	fup(i,0,q-1,1){
		int o,j,x,y;
		scanf("%d",&o);
		if(o==1){
			scanf("%d%d%d",&j,&x,&y);
			p[j]=1.0*x/y;
			upd(1,1,n,j);
		}else{
			scanf("%d%d",&x,&y);
			D T=find(1,1,n,x,y);
			printf("%.6f\n",T.d2);
		}
	}
}