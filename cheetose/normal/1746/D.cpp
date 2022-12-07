#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[200005];
ll s[200005];
unordered_map<int,ll> M[200005];
ll go(int N,int K){
	if(K==0)return 0;
	if(v[N].empty())return s[N]*K;
	if(M[N].count(K))return M[N][K];
	int c=v[N].size();
	int k1=K/c,k2=k1+1;
	int c2=K%c,c1=c-c2;
	ll res=s[N]*K;
	Vll rr;
	for(int next:v[N]){
		ll t1=go(next,k1),t2;
		res+=t1;
		if(c2){
			t2=go(next,k2);
			rr.pb(t2-t1);
		}
	}
	sort(rr.rbegin(),rr.rend());
	fup(i,0,c2-1,1)res+=rr[i];
	return M[N][K]=res;
}
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,1,n,1){
		v[i].clear();
		M[i].clear();
	}
	fup(i,2,n,1){
		int p;
		scanf("%d",&p);
		v[p].pb(i);
	}
	fup(i,1,n,1)scanf("%lld",s+i);
	printf("%lld\n",go(1,k));
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}