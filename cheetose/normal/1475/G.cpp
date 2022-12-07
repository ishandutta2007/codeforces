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

int cnt[200001];
int d[200001];
Vi v[200001];
int go(int N){
	if(N==1)return cnt[1];
	int &ret=d[N];
	if(~ret)return ret;
	ret=0;
	for(int y:v[N]){
		ret=max(ret,cnt[N]+go(N/y));
	}
	return ret;
}
void solve(){
	MEM0(cnt);
	MEM_1(d);
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	int ans=0;
	fup(i,1,200000,1)ans=max(ans,go(i));
	printf("%d\n",n-ans);
}
int main(){
	fup(i,2,200000,1){
		if(v[i].size())continue;
		fup(j,i,200000,i)v[j].pb(i);
	}
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}