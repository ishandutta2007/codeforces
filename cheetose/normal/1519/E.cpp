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

struct fraction {
	__int128 a, b;
	__int128 _gcd(__int128 x, __int128 y){
		return y?_gcd(y,x%y):x;
	}
	fraction(ll A, ll B) { __int128 t = _gcd(A, B); a = A / t, b = B / t; }
	fraction() { fraction(0, 1); }
	bool operator < (const fraction& O)const
	{
		__int128 A = O.a, B = O.b;
		return a*B < b*A;
	}
};
map<fraction,int> M;
bool chk[600000];
Vi v[600000],tmp;
int p[200000][2];
VPi ans;
int n;
bool ok(int x,int y){
	fup(i,0,1,1)fup(j,0,1,1)if(p[x][i]==p[y][j])return 1;
	return 0;
}
void dfs(int N){
	chk[N]=1;
	for(int next:v[N]){
		if(!chk[next])dfs(next);
	}
	if(N<n){
		if(tmp.empty())tmp.pb(N);
		else{
			int t=tmp.back();
			if(ok(t,N)){
				tmp.pop_back();
				ans.pb({t+1,N+1});
			}else tmp.pb(N);
		}
	}
}
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1){
		ll a,b,c,d;
		scanf("%lld%lld%lld%lld",&b,&a,&d,&c);
		fraction A(a*d,(a+b)*c),B(a*(c+d),b*c);
		if(M.find(A)==M.end())M[A]=M.size();
		if(M.find(B)==M.end())M[B]=M.size();
		int x=M[A],y=M[B];
		p[i][0]=x,p[i][1]=y;
		v[x+n].pb(i),v[y+n].pb(i);
		v[i].pb(x+n),v[i].pb(y+n);
	}
	int N=M.size();
	fup(i,n,n+N-1,1){
		if(!chk[i]){
			tmp.clear();
			dfs(i);
		}
	}
	printf("%d\n",ans.size());
	for(auto [x,y]:ans)printf("%d %d\n",x,y);
}