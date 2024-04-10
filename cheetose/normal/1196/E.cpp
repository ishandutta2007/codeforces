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
#define INF 987654321
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int main() {
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int b,w;
		scanf("%d%d",&b,&w);
		if(b==w)
		{
			puts("YES");
			fup(i,1,b+w,1)printf("1 %d\n",i);
		}
		else if(b<w)
		{
			if(w>3*b+1)
			{
				puts("NO");
				continue;
			}
			puts("YES");
			w-=b+1;
			fup(i,1,b,1)
			{
				printf("99 %d\n",2*i+100);
				printf("99 %d\n",2*i+101);
			}
			printf("99 101\n");
			fup(i,1,b,1)
			{
				if(w>0)printf("98 %d\n",2*i+100),w--;
				if(w>0)printf("100 %d\n",2*i+100),w--;
			}
		}
		else
		{
			if(b>3*w+1)
			{
				puts("NO");
				continue;
			}
			puts("YES");
			b-=w+1;
			fup(i,1,w,1)
			{
				printf("100 %d\n",2*i+100);
				printf("100 %d\n",2*i+101);
			}
			printf("100 101\n");
			fup(i,1,w,1)
			{
				if(b>0)printf("99 %d\n",2*i+100),b--;
				if(b>0)printf("101 %d\n",2*i+100),b--;
			}
		}
	}
}