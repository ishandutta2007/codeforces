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

char s[200005];
int a[17][200005];
int d[1<<17];
int main(){
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	fup(i,0,k-1,1){
		fup(j,1,n,1){
			if(s[j]=='?' || s[j]==i+'a')a[i][j]=a[i][j-1]+1;
		}
	}
	int l=1,r=n/k;
	while(l<=r){
		int m=l+r>>1;
		vector<Vi> v(k);
		fup(i,0,k-1,1){
			fup(j,1,n,1)if(a[i][j]>=m)v[i].pb(j);
		}
		fill(d,d+(1<<k),INF);
		queue<int> q;
		q.push(0);
		d[0]=0;
		while(!q.empty()){
			int K=q.front();
			q.pop();
			fup(i,0,k-1,1){
				if(K&(1<<i))continue;
				int t=lower_bound(ALL(v[i]),d[K]+m)-v[i].begin();
				if(t!=v[i].size()){
					if(d[K|(1<<i)]==INF)q.push(K|(1<<i));
					d[K|(1<<i)]=min(d[K|(1<<i)],v[i][t]);
				}
			}
		}
		if(d[(1<<k)-1]!=INF)l=m+1;
		else r=m-1;
	}
	printf("%d\n",r);
}