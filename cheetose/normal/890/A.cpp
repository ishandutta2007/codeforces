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
int a[6];
int main() {
	fup(i, 0, 5, 1)
		scanf("%d", a + i);
	int c[6] = { 0,0,0,1,1,1 };
	do {
		int A = 0, B = 0;
		fup(i, 0, 5, 1)
		{
			if (c[i])B += a[i];
			else A += a[i];
		}
		if (A == B)
		{
			puts("YES");
			return 0;
		}
	} while (next_permutation(c, c + 6));
	puts("NO");
}