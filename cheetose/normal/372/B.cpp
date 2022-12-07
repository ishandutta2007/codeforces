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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m,q;
int A[41][41],L[41][41];
int dd[41][41][41][41];
void precal(int b,int c,int d)
{
	fup(i,1,c,1)
	{
		L[i][b-1]=0;
		fup(j,b,d,1)
		{
			if(A[i][j]==1)L[i][j]=0;
			else L[i][j]=L[i][j-1]+1;
		}
	}
	
	int ans=0;
	int tot[41]={0};
	stack<Pi> st[41];
	
	fdn(i,c,1,1)
	{
		fup(j,b,d,1)
		{
			int cnt=0;
			while(!st[j].empty() && st[j].top().X>=L[i][j])
			{
				cnt+=st[j].top().Y;
				tot[j]-=st[j].top().X*st[j].top().Y;
				st[j].pop();
			}
			st[j].push(mp(L[i][j],cnt+1));
			tot[j]+=st[j].top().X*st[j].top().Y;
			ans+=tot[j];
		}
		dd[i][b][c][d]=ans;
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&q);
	fup(i,1,n,1)fup(j,1,m,1)scanf("%1d",&A[i][j]);
	fup(i,1,40,1)fup(j,1,40,1)fup(k,i,40,1)precal(i,j,k);
	while(q--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",dd[a][b][c][d]);
	}
}