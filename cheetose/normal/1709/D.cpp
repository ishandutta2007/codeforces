#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
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

int a[200005];
int tree[524288];
void init(int node,int S,int E){
	if(S==E){
		tree[node]=a[S];
		return;
	}
	int L=node<<1,R=L|1,M=S+E>>1;
	init(L,S,M);
	init(R,M+1,E);
	tree[node]=min(tree[L],tree[R]);
}
int find(int node,int S,int E,int i,int j){
	if(i>E || j<S)return INF;
	if(i<=S && j>=E)return tree[node];
	int L=node<<1,R=L|1,M=S+E>>1;
	return min(find(L,S,M,i,j),find(R,M+1,E,i,j));
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,m,1)scanf("%d",a+i),a[i]=n-a[i]-1;
	init(1,1,m);
	int q;
	scanf("%d",&q);
	while(q--){
		int x1,y1,x2,y2,k;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
		x1=n-x1,x2=n-x2;
		if(abs(x1-x2)%k || abs(y1-y2)%k){
			puts("NO");
			continue;
		}
		int t=x1%k;
		if(find(1,1,m,min(y1,y2),max(y1,y2))<t)puts("NO");
		else puts("YES");
	}
}