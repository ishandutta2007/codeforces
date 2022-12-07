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

Pi p[500005];
int ans[500005];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",&p[i].X),p[i].Y=i;
	sort(p+1,p+n+1,[&](Pi p1,Pi p2){
		if(p1.X==0 && p2.X==0)return p1.Y<p2.Y;
		if(p1.X==0)return false;
		if(p2.X==0)return true;
		return 1ll*p1.Y*p2.X<1ll*p2.Y*p1.X;
	});
	set<int> S;
	fup(i,1,n,1)S.insert(i);
	fup(i,1,n,1){
		if(p[i].X==0){
			ans[p[i].Y]=*S.begin();
			S.erase(S.begin());
		}else{
			auto it=S.lower_bound(p[i].Y/(p[i].X+1)+1);
			ans[p[i].Y]=*it;
			S.erase(it);
		}
	}
	fup(i,1,n,1)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}