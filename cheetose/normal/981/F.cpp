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

ll a[600000],b[600000];
int n,l;
bool ok(int k){
	int L=-INF,R=INF;
	int t1=0,t2=0;
	fup(i,n,2*n-1,1){
		while(b[t1]<a[i]-k)t1++;
		while(b[t2]<=a[i]+k)t2++;
		L=max(L,t1-i), R=min(R,t2-i-1);
	}
	return L<=R;
}
int main(){
	scanf("%d%d",&n,&l);
	fup(i,0,n-1,1)scanf("%lld",a+i);
	fup(i,0,n-1,1)scanf("%lld",b+i);
	sort(a,a+n);sort(b,b+n);
	fup(i,n,3*n-1,1){
		a[i]=a[i-n]+l,b[i]=b[i-n]+l;
	}
	int L=0,R=l;
	while(L<=R){
		int k=L+R>>1;
		if(ok(k))R=k-1;
		else L=k+1;
	}
	printf("%d\n",L);
}