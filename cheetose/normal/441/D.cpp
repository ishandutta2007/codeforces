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
#define INF 1987654321
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n,m;
int a[3001];
int parent[3001],pos[3001];
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
int main() {
	MEM_1(parent);
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	scanf("%d",&m);
	fup(i,1,n,1)
	{
		merge(i,a[i]);
	}
	int c=0;
	fup(i,1,n,1)
	{
		if(i==find(i))
		{
			c+=-parent[i]-1;
		}
	}
	if(m==c)return !printf("0");
	if(c<m)
	{
		printf("%d\n",m-c);
		fup(i,2,n,1)
		{
			if(c<m && find(1)!=find(i))
			{
				printf("1 %d ",i);
				merge(1,i);
				c++;
			}
		}
		return 0;
	}
	else
	{
		printf("%d\n",c-m);
		fup(i,1,n,1)
		{
			MEM_1(pos);
			int cc=0;
			for(int j=a[i];j!=i;j=a[j])pos[j]=cc++;
			pos[i]=cc;
			
			cc = 0;
			fup(j,i+1,n,1)
			{
				if(pos[j]>=cc)
				{
					printf("%d %d ",i,j);
					c--;
					if(c==m)return 0;
					cc=pos[j]+1;
					swap(a[i],a[j]);
				}
			}
		}
	}
}