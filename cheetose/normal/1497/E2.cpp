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

int t[10000001];
bitset<10000001> chk;
int a[200002];
int d[200002][21],L[200002][21];
int cnt[10000001];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		a[i]=t[a[i]];
	}
	fup(K,0,k,1){
		int c=0;
		int l,r;
		for(l=0,r=0;r<n;r++){
			cnt[a[r]]++;
			if(cnt[a[r]]>1)c++;
			while(c>K){
				cnt[a[l]]--;
				if(cnt[a[l++]]>=1)c--;
			}
			L[r][K]=l;
		}
		for(;l<n;l++)cnt[a[l]]--;
	}
	fup(K,0,k,1){
		fup(i,0,n-1,1){
			d[i][K]=INF;
			fup(kk,0,K,1){
				if(L[i][kk]==0)d[i][K]=1;
				else d[i][K]=min(d[i][K],d[L[i][kk]-1][K-kk]+1);
			}
		}
	}
	int ans=INF;
	fup(K,0,k,1)ans=min(ans,d[n-1][K]);
	printf("%d\n",ans);
}
int main(){
	iota(t,t+10000001,0);
	fup(i,2,4000,1){
		if(chk[i])continue;
		int tt=i*i;
		fup(j,i+i,10000000,i){
			chk[j]=true;
			while(t[j]%tt==0)t[j]/=tt;
		}
	}
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}