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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[500005],b[500005];
int tree[1050000];

void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node] = INF;
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void upd(int node, int S, int E, int k, int dif)
{
	if (S == E){
		tree[node]=dif;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return INF;
	if (i <= S && j >= E)return tree[node];
	return min(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	Vi vv={0};
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		vv.pb(a[i]);
	}
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	int N=vv.size();
	fup(i,0,n-1,1)a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
	init(1,0,N-1);
	upd(1,0,N-1,0,n);
	fdn(i,n-1,0,1){
		b[i]=find(1,0,N-1,0,a[i]-1)-i;
		upd(1,0,N-1,a[i],i);
	}
	int f=-1;
	fup(i,0,n-1,1){
		if(b[i]>k){
			f=i;
			break;
		}
	}
	if(f==-1)return !printf("YES\n");
	if(f+b[f]==n || b[f]>2*k)return !printf("NO\n");
	int tt=f+b[f];
	fup(i,f+b[f],min(f+b[f]+k,n-1),1){
		if(a[i]<a[f] && a[i]>a[tt])tt=i;
	}
	swap(a[tt],a[f+k]);
	init(1,0,N-1);
	upd(1,0,N-1,0,n);
	fdn(i,n-1,0,1){
		b[i]=find(1,0,N-1,0,a[i]-1)-i;
		upd(1,0,N-1,a[i],i);
	}
	f=-1;
	fup(i,0,n-1,1){
		if(b[i]>k){
			f=i;
			break;
		}
	}
	puts(f==-1?"YES":"NO");
}