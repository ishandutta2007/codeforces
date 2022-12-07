#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
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

int a[6],b[100000],cnt[100000],cc;
int main(){
	fup(i,0,5,1)scanf("%d",a+i);
	int n;
	scanf("%d",&n);
	VPi v;
	fup(i,0,n-1,1){
		scanf("%d",b+i);
		fup(j,0,5,1)v.pb(mp(b[i]-a[j],i));
	}
	sort(ALL(v));
	int N=v.size();
	int i=0,j=0,ans=INF;
	while(j<N){
		while(j<N && cc!=n){
			cnt[v[j].Y]++;
			if(cnt[v[j].Y]==1)cc++;
			j++;
		}
		if(j==N && cc!=n)break;
		while(i<j && cc==n){
			cnt[v[i].Y]--;
			if(cnt[v[i].Y]==0){
				cc--;
				ans=min(ans,v[j-1].X-v[i].X);
			}
			i++;
		}
	}
	printf("%d\n",ans);
}