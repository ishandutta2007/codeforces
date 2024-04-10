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
#include<cmath>
#include<algorithm>
#include<list>
#include<functional>
#define X first
#define Y second
#define INF 1000000000
#define PI 3.14159265358979323
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
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef pair<int, char> P;
int a[200001];
bool chk[200001];
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 1, n, 1)
		scanf("%d", a + i);
	int ans = 0;
	fdn(i, n, 1, 1)
	{
		if (chk[i])continue;
		ans++;
		int j = i;
		while (!chk[j])
		{
			chk[j] = 1;
			j = a[j];
		}
	}
	printf("%d", ans);
}