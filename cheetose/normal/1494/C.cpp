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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int g(Vi &v1,Vi &v2){
	int n=v1.size(),m=v2.size();
	if(n==0 || m==0)return 0;
	Vi cnt(m+1);
	fdn(i,m-1,0,1){
		cnt[i]=cnt[i+1];
		int x=v2[i];
		if(binary_search(ALL(v1),x))cnt[i]++;
	}
	int ans=cnt[0];
	for(int i=0,j=0;i<m;i++){
		while(j<n && v1[j]<=v2[i])j++;
		if(j==0)continue;
		int t=lower_bound(ALL(v2),v2[i]-j+1)-v2.begin();
		ans=max(ans,i-t+1+cnt[i+1]);
	}
	return ans;
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	Vi L1,L2,R1,R2;
	fup(i,0,n-1,1){
		int x;
		scanf("%d",&x);
		if(x<0)L1.pb(-x);
		else R1.pb(x);
	}
	fup(i,0,m-1,1){
		int x;
		scanf("%d",&x);
		if(x<0)L2.pb(-x);
		else R2.pb(x);
	}
	reverse(ALL(L1));reverse(ALL(L2));
	printf("%d\n",g(L1,L2)+g(R1,R2));
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}