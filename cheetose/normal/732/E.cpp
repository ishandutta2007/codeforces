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
const ll MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

map<int,Vi> M;
int a1[200005],a2[200005];
int a[200005],b[200005];
int c,u;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		M[a[i]].pb(i);
	}
	fup(i,1,m,1)scanf("%d",b+i);
	priority_queue<iii> q;
	fup(i,1,m,1)
	{
		q.push(iii(b[i],0,i));
	}
	while(!q.empty())
	{
		iii p=q.top();
		q.pop();
		int xx,yy,zz;
		tie(xx,yy,zz)=p;
		yy*=-1;
		if(M.find(xx)!=M.end())
		{
			if(!M[xx].empty())
			{
				c++,u+=yy;
				a1[zz]=yy;
				a2[M[xx].back()]=zz;
				M[xx].pop_back();
				continue;
			}
		}
		if(xx==1)continue;
		xx=(xx+1)/2,yy++;
		q.push(iii(xx,-yy,zz));
	}
	printf("%d %d\n",c,u);
	fup(i,1,m,1)printf("%d ",a1[i]);
	puts("");
	fup(i,1,n,1)printf("%d ",a2[i]);
	puts("");
}