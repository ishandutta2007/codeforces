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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[200000];
struct SEG{
	ll a[100000], tree[262144], lazy[262144];
	void init(int node, int S, int E)
	{
		tree[node]=lazy[node]=0;
		if (S == E)return;
		init(2 * node, S, (S + E) / 2);
		init(2 * node + 1, (S + E) / 2 + 1, E);
	}
	void propagation(int node, int S, int E)
	{
		if (lazy[node] != 0)
		{
			tree[node] += lazy[node];
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
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
	ll find(int node, int S, int E, int i, int j)
	{
		propagation(node, S, E);
		if (i > E || j < S) return INF;
		if (j >= E && i <= S) return tree[node];
		return min(find(node * 2, S, (S + E) / 2, i, j), find(2 * node + 1, (S + E) / 2 + 1, E, i, j));
	}
}odd,even;
ll so[100001],se[100001];
void solve(){
	int n;
	scanf("%d",&n);
	ll ss=0;
	fup(i,0,n-1,1)scanf("%lld",a+i),ss+=a[i];
	if(ss&1){
		puts("NO");
		return;
	}
	int N=(n+1)/2,M=n/2;
	odd.init(1,0,M-1);even.init(1,0,N-1);
	fup(i,0,n-1,1){
		int j=i/2;
		if(i&1){
			so[j]=a[i];
			if(j>0)so[j]+=so[j-1];
			ll t=so[j]-se[j];
			odd.upd(1,0,M-1,j,j,t);
		}else{
			se[j]=a[i];
			if(j>0)se[j]+=se[j-1];
			ll t=se[j];
			if(j>0)t-=so[j-1];
			even.upd(1,0,N-1,j,j,t);
		}
	}
	if(even.find(1,0,N-1,0,N-1)>=0 && odd.find(1,0,M-1,0,M-1)>=0 && se[N-1]==so[M-1]){
		puts("YES");
		return;
	}
	fup(i,0,n-2,1){
		ll dif=a[i+1]-a[i];
		int j=i/2,k=(i+1)/2;
		if(i&1){
			odd.upd(1,0,M-1,j,M-1,dif);
			even.upd(1,0,N-1,k,N-1,-dif);
			even.upd(1,0,N-1,j+1,N-1,-dif);
			odd.upd(1,0,M-1,k,M-1,dif);
		}else{
			even.upd(1,0,N-1,j,N-1,dif);
			odd.upd(1,0,M-1,k,M-1,-dif);
			odd.upd(1,0,M-1,j,M-1,-dif);
			even.upd(1,0,N-1,k+1,N-1,dif);
		}
		bool ok=0;
		if(n&1){
			ok=(even.find(1,0,N-1,N-1,N-1)==0);
		}else{
			ok=(odd.find(1,0,M-1,M-1,M-1)==0);
		}
		if(ok && even.find(1,0,N-1,0,N-1)>=0 && odd.find(1,0,M-1,0,M-1)>=0){
			puts("YES");
			return;
		}
		if(i&1){
			odd.upd(1,0,M-1,j,M-1,-dif);
			even.upd(1,0,N-1,k,N-1,dif);
			even.upd(1,0,N-1,j+1,N-1,dif);
			odd.upd(1,0,M-1,k,M-1,-dif);
		}else{
			even.upd(1,0,N-1,j,N-1,-dif);
			odd.upd(1,0,M-1,k,M-1,dif);
			odd.upd(1,0,M-1,j,M-1,dif);
			even.upd(1,0,N-1,k+1,N-1,-dif);
		}
	}
	puts("NO");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}