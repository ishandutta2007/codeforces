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

ll a[200001],b[200001];
ll tree1[524288],tree2[524288];

void init(int node, int S, int E)
{
	if (S == E)
	{
		tree1[node] = (a[S]*b[S])%MOD;
		tree2[node]=b[S];
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree1[node] = (tree1[node * 2] + tree1[node * 2 + 1])%MOD;
	tree2[node] = tree2[node * 2] + tree2[node * 2 + 1];
}

void upd(int node, int S, int E, int k)
{
	if (S == E)
	{
		tree1[node] = (a[S]*b[S])%MOD;
		tree2[node]=b[S];
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k);
	tree1[node] = (tree1[node * 2] + tree1[node * 2 + 1])%MOD;
	tree2[node] = tree2[node * 2] + tree2[node * 2 + 1];
}
Pll operator + (const Pll &p1,const Pll &p2){
	return mp((p1.X+p2.X)%MOD,p1.Y+p2.Y);
}
Pll find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return {0,0};
	if (i <= S && j >= E)return {tree1[node],tree2[node]};
	return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

int findK(int node, int S, int E, ll k)
{
	if (S == E)return S;
	if (k <= tree2[node * 2])return findK(node * 2, S, (S + E) / 2, k);
	return findK(node * 2 + 1, (S + E) / 2 + 1, E, k - tree2[node * 2]);
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,1,n,1){
		scanf("%lld",a+i);
		a[i]-=i;
	}
	fup(i,1,n,1)scanf("%lld",b+i);
	init(1,1,n);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>0){
			ll k=(find(1,1,n,x,y).Y+1)/2;
			int i=findK(1,1,n,k+find(1,1,n,1,x-1).Y);
			Pll s1=find(1,1,n,x,i-1),s2=find(1,1,n,i+1,y);
			ll ans=((s1.Y*a[i]-s1.X)+(s2.X-s2.Y*a[i]))%MOD;
			if(ans<0)ans+=MOD;
			printf("%lld\n",ans);
		}else{
			x=-x;
			b[x]=y;
			upd(1,1,n,x);
		}
	}
}