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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[5001],b[5001],s[5001];
Vll v[10001];
int n;
inline ll Q(int l,int r){
	int s=l+r;
	if(s<=n)return v[s][r]-v[s][l-1];
	return v[s][r-s+n+1]-v[s][l-s+n];
}
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)v[i].resize(i+1);
	fup(i,n+1,2*n,1)v[i].resize(2*n-i+2);
	fup(i,1,n,1)scanf("%lld",a+i);
	fup(i,1,n,1)scanf("%lld",b+i);
	fup(i,1,n,1){
		s[i]=a[i]*b[i];
		s[i]+=s[i-1];
	}
	fup(i,1,n,1){
		fup(j,1,n,1){
			int s=i+j;
			if(s<=n)v[s][i]+=a[i]*b[j];
			else v[s][i-s+n+1]+=a[i]*b[j];
		}
	}
	fup(i,1,2*n,1){
		int N=v[i].size();
		fup(j,1,N-1,1)v[i][j]+=v[i][j-1];
	}
	ll ans=s[n];
	fup(i,1,n,1){
		fup(j,i+1,n,1){
			ll tmp=s[n]-s[j]+s[i-1]+Q(i,j);
			ans=max(ans,tmp);
		}
	}
	printf("%lld\n",ans);
}