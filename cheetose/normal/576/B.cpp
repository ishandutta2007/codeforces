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
#define INF 987654321987654231
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int a[100001];
Vi v[2];
bool chk[100001];
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		if(a[i]==i)
		{
			puts("YES");
			fup(j,1,n,1)
			{
				if(j!=i)printf("%d %d\n",i,j);
			}
			return 0;
		}
	}
	fup(i,1,n,1)
		if(a[a[i]]==i)
		{
			chk[a[i]]=chk[i]=1;
			fup(j,1,n,1)
			{
				if(!chk[j])
				{
					int now=j,t=0;
					while(!chk[now])
					{
						chk[now]=1;
						v[t].pb(now);
						now=a[now];
						t=1-t;
					}
					if(t)return !printf("NO");
				}
			}
			puts("YES");
			printf("%d %d\n",i,a[i]);
			fup(j,0,(int)v[0].size()-1,1)
				printf("%d %d\n",i,v[0][j]);
			fup(j,0,(int)v[1].size()-1,1)
				printf("%d %d\n",a[i],v[1][j]);
			return 0;
		}
	puts("NO");
}