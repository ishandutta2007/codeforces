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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

struct UF{
	int p[100005];
	int find(int x){
		return x==p[x]?x:p[x]=find(p[x]);
	}
	void merge(int x,int y){
		p[find(x)]=find(y);
	}
}A,B;
int main() {
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	iota(A.p,A.p+n+1,0);
	iota(B.p,B.p+n+1,0);
	fup(i,1,m1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		A.merge(x,y);
	}
	fup(i,1,m2,1){
		int x,y;
		scanf("%d%d",&x,&y);
		B.merge(x,y);
	}
	VPi ans;
	fup(i,1,n,1){
		fup(j,i+1,n,1){
			if(A.find(i)==A.find(j) || B.find(i)==B.find(j))continue;
			ans.pb(mp(i,j));
			A.merge(i,j);B.merge(i,j);
		}
	}
	printf("%d\n",ans.size());
	for(auto [x,y]:ans)printf("%d %d\n",x,y);
}