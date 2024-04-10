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

char s[200005][62];
inline ll myrand(){
	return ((1LL*rand())<<16)|(rand());
}
int cnt[1<<15],d[1<<15];
int main(){
	srand(time(0));
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	int T=50;
	ll ans=0;
	while(T--){
		MEM0(cnt);
		MEM0(d);
		int t=myrand()%n;
		Vi vv;
		fup(i,0,m-1,1){
			if(s[t][i]=='1')vv.pb(i);
		}
		int N=vv.size();
		fup(i,0,n-1,1){
			int c=0;
			fup(j,0,N-1,1){
				if(s[i][vv[j]]=='1')c|=(1<<j);
			}
			cnt[c]++;
		}
		fup(i,1,(1<<N)-1,1){
			for(int j=i;j;j=(j-1)&i)d[j]+=cnt[i];
		}
		fup(i,1,(1<<N)-1,1){
			if(d[i]>=(n+1)/2 && __builtin_popcountll(ans)<__builtin_popcount(i)){
				ans=0;
				fup(j,0,N-1,1){
					if(i&(1<<j))ans|=(1LL<<vv[j]);
				}
			}
		}
	}
	fup(i,0,m-1,1){
		if(ans&(1LL<<i))putchar('1');
		else putchar('0');
	}
}