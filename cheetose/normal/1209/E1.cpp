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
#define y0 y12
#define y1 y22
#define INF 1000000007
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
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
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n,m;
int d[1<<12],t[1<<12],cur[1<<12];
void solve()
{
	scanf("%d%d",&m,&n);
	vector<Vi> a(n,Vi(m));
	fup(j,0,m-1,1)fup(i,0,n-1,1)scanf("%d",&a[i][j]);
	if(n>m)
	{
		Vi t(n),b(n);
		vector<Vi> tmp;
		fup(i,0,n-1,1)
			fup(j,0,m-1,1)t[i]=max(t[i],a[i][j]);
		fup(i,0,n-1,1)b[i]=i;
		sort(ALL(b),[&](int x,int y){return t[x]>t[y];});
		fup(i,0,m-1,1)tmp.emplace_back(a[b[i]]);
		a=tmp;
	}
	while(a.size()<m)a.emplace_back(Vi(m,0));
	n=m;
	MEM0(d);
	fup(i,0,n-1,1)
	{
		memcpy(t,d,sizeof(d));
		fup(j,0,n-1,1)
		{
			Vi b(n);
			fup(k,0,n-1,1)b[k]=a[i][(k+j)%n];
			memcpy(cur,d,sizeof(d));
			fup(k,0,(1<<n)-1,1)
			{
				fup(kk,0,n-1,1)
				{
					if(k&(1<<kk))
						cur[k]=max(cur[k],cur[k-(1<<kk)]+b[kk]);
				}
			}
			fup(k,0,(1<<n)-1,1)t[k]=max(t[k],cur[k]);
		}
		memcpy(d,t,sizeof(d));
	}
	printf("%d\n",d[(1<<n)-1]);
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}