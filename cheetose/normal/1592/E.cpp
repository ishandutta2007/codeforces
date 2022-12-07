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

int a[1000001],b[1000001],s[1000001];
int mn[1<<20],ans;
void solve(int L,int R){
	if(L>R)return;
	mn[s[L-1]]=L-1;
	fup(i,L,R,1){
		if(mn[s[i]]!=-1){
			ans=max(ans,i-mn[s[i]]);
		}else mn[s[i]]=i;
	}
	fup(i,L-1,R,1){
		mn[s[i]]=-1;
	}
}
int main(){
	MEM_1(mn);
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fdn(K,19,0,1){
		fup(i,1,n,1){
			b[i]|=a[i]&(1<<K);
			s[i]=s[i-1]^b[i];
		}
		for(int l=1,r=1;r<=n+1;r++){
			if(r==n+1 || !(b[r]&(1<<K))){
				solve(l,r-1);
				l=r+1;
			}
		}
	}
	printf("%d\n",ans);
}