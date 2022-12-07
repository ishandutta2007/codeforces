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
int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		temp += a;
	}
	puts(temp + n - 1 == x ? "YES" : "NO");
}