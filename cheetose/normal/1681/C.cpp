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

int a[101],b[101];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1)scanf("%d",b+i);
	VPi v;
	fup(i,1,n,1){
		int w=i;
		fup(j,i+1,n,1){
			if(a[w]>a[j]){
				w=j;
			}
		}
		if(w==i)continue;
		v.pb({i,w});
		swap(a[i],a[w]);
		swap(b[i],b[w]);
	}
	for(int i=1,j=1;i<=n;i=j){
		while(j<=n && a[i]==a[j])j++;
		fup(i1,i,j-1,1){
			int w=i1;
			fup(j1,i1+1,j-1,1){
				if(b[w]>b[j1]){
					w=j1;
				}
			}
			if(w==i1)continue;
			v.pb({i1,w});
			swap(b[i1],b[w]);
		}
	}
	fup(i,1,n-1,1){
		if(b[i]>b[i+1]){
			puts("-1");
			return;
		}
	}
	printf("%d\n",v.size());
	for(auto [x,y]:v)printf("%d %d\n",x,y);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}