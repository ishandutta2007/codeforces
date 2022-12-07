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

int a[100005];
int d[301][301];
int s[301],n;
int res(int L,int R){
	if(L==0)return s[R];
	return s[R]^s[L-1];
}
int go(int L,int R){
	if(R==n)return INF;
	int &ret=d[L][R];
	if(~ret)return ret;
	ret=INF;
	int pr=res(L,R);
	int c=0;
	fup(i,R+1,n,1){
		if(res(R+1,i)<pr)ret=min(ret,c);
		else ret=min(ret,c+go(R+1,i));
		c++;
	}
	return ret;
}
int main() {
	MEM_1(d);
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n-1,1){
		int t=a[i]^a[i+1];
		if(t<a[i-1] || (i+2<=n && t>a[i+2]))return !printf("1\n");
	}
	fup(i,1,n,1)s[i]=s[i-1]^a[i];
	int ans=go(0,0);
	if(ans==INF)ans=-1;
	printf("%d\n",ans);
}