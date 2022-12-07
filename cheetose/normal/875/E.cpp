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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi vv;
int a[100003],n;
inline int ch(int x){
	return lower_bound(ALL(vv),x)-vv.begin();
}
int tree[262144];

void init(int node, int S, int E){
	tree[node]=n;
	if (S == E)return;
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
}

void upd(int node, int S, int E, int k, int dif){
	if (S == E){
		tree[node]=min(tree[node],dif);
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}

int find(int node, int S, int E, int i, int j){
	if (i > E || j < S)return n;
	if (i <= S && j >= E)return tree[node];
	return min(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int go[100005];
struct FenwickTree{
	int n;
	Vi tree;
	
	FenwickTree(){}
	FenwickTree(int N){
		n=N;
		tree.resize(N+1);
	}
	
	void upd(int i, int k){
		i++;
		while (i <= n){
			tree[i] += k;
			i += (i&-i);
		}
	}
	int sum(int i){
		i++;
		int c = 0;
		while (i > 0){
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
}A,B;
bool ok(int k){
	fill(ALL(A.tree),0);
	fill(ALL(B.tree),0);
	init(1,0,n-1);
	fdn(i,n-1,0,1){
		int t1=upper_bound(ALL(vv),vv[a[i]]+k)-vv.begin(),t2=lower_bound(ALL(vv),vv[a[i]]-k)-vv.begin()-1;
		int t=min(find(1,0,n-1,t1,n-1),find(1,0,n-1,0,t2));
		go[i]=t-1;
		upd(1,0,n-1,a[i],i);
	}
	A.upd(0,1);A.upd(1,-1);
	B.upd(1,1);B.upd(2,-1);
	fup(i,0,n-1,1){
		if(A.sum(i)){
			B.upd(i+1,1);
			B.upd(go[i]+1,-1);
		}
		if(B.sum(i)){
			A.upd(i+1,1);
			A.upd(go[i]+1,-1);
		}
	}
	if(A.sum(n-1) || B.sum(n-1))return 1;
	return 0;
}
int main() {
	scanf("%d",&n);
	n+=2;
	A=FenwickTree(n),B=FenwickTree(n);
	fup(i,0,n-1,1)scanf("%d",a+i),vv.pb(a[i]);
	int l=abs(a[0]-a[1]),r=(int)1e9;
	sort(ALL(vv));
	fup(i,0,n-1,1)a[i]=ch(a[i]);
	while(l<=r){
		int k=l+r>>1;
		if(ok(k))r=k-1;
		else l=k+1;
	}
	printf("%d\n",l);
}