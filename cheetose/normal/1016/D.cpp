#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int ans[100][100];
int a[100],b[100];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,0,m-1,1)scanf("%d",b+i);
	fdn(k,29,0,1)
	{
		Vi A,B;
		fup(i,0,n-1,1)if(a[i]&(1<<k))A.pb(i);
		fup(i,0,m-1,1)if(b[i]&(1<<k))B.pb(i);
		int N=A.size(),M=B.size();
		if((N^M)&1)return !printf("NO");
		fup(i,0,min(N,M)-1,1)ans[A[i]][B[i]]+=1<<k;
		if(N>M)fup(i,M,N-1,1)ans[A[i]][0]+=1<<k;
		else if(N<M)fup(i,N,M-1,1)ans[0][B[i]]+=1<<k;
	}
	puts("YES");
	fup(i,0,n-1,1)
	{
		fup(j,0,m-1,1)
			printf("%d ",ans[i][j]);
		puts("");
	}
}