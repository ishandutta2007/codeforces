#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<algorithm>
#include<list>
#include<functional>
#define _USE_MATH_DEFINES
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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
typedef complex<double> base;
int a[100];
int d[100][2];
int n;
int go(int N, int prev)
{
	if (N == n)return 0;
	int &ret = d[N][prev];
	if (ret != -1)return ret;
	ret = go(N+1, prev);
	if(!(prev==1&&a[N]==0))
		ret = max(ret,1+go(N + 1, a[N]));
	return ret;
}
int main() {
	MEM_1(d);
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)scanf("%d", a + i);
	printf("%d", go(0, 0));
}