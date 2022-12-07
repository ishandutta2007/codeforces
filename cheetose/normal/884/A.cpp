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
#define X first
#define Y second
#define INF 987654321987654321
#define PI 3.14159265358979323
#define MOD 10007
using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
int n, t;
int a[100];
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int tt = 0;
	for (int i = 0; i < n; i++)
	{
		tt += 86400 - a[i];
		if (tt >= t)
		{
			printf("%d", i + 1);
			return 0;
		}
	}
}