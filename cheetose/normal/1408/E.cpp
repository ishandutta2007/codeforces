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

int sz[100001];
ll a[100001],b[100002];
int parent[200005];
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
int main() {
	MEM_1(parent);
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%lld",a+i);
	fup(i,1,m,1)scanf("%lld",b+i);
	ll ans=0;
	VLLL v;
	fup(i,0,n-1,1){
		int k;
		scanf("%d",&k);
		while(k--){
			int x;
			scanf("%d",&x);
			ans+=a[i]+b[x];
			v.pb(LLL(a[i]+b[x],i,x+100000));
		}
	}
	sort(ALL(v),[&](LLL a1, LLL a2){
		return get<0>(a1)>get<0>(a2);
	});
	for(auto &I:v){
		auto [z,x,y]=I;
		x=find(x),y=find(y);
		if(x==y)continue;
		ans-=z;
		merge(x,y);
	}
	printf("%lld\n",ans);
}