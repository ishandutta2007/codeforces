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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,m,k;
int l[500000],r[500000],x[500000];
int s[500005];
int rr[500005];
ll d[500005],sum[500005];
ll go(int p){
	MEM0(s);MEM_1(rr);
	fup(i,0,m-1,1){
		if(x[i]&(1<<p)){
			s[l[i]]++,s[r[i]+1]--;
		}else{
			rr[r[i]]=max(rr[r[i]],l[i]);
		}
	}
	fup(i,2,n,1)s[i]+=s[i-1];
	int j=-1;
	d[0]=1;
	sum[0]=1;
	fup(i,1,n,1){
		if(s[i])d[i]=0;
		else d[i]=(sum[i-1]+MOD-(j==-1?0:sum[j-1]))%MOD;
		sum[i]=(sum[i-1]+d[i])%MOD;
		j=max(j,rr[i]);
	}
	if(j!=-1)sum[n]=(sum[n]+MOD-sum[j-1])%MOD;
	return sum[n];
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	fup(i,0,m-1,1){
		scanf("%d%d%d",l+i,r+i,x+i);
	}
	ll res=1;
	fup(i,0,k-1,1)res=res*go(i)%MOD;
	printf("%lld\n",res);
}