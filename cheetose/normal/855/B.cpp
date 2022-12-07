#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 4987654321987654321LL
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int n;
ll a[100000];
ll d[3][100000];
ll p[3];
ll go(int k, int N)
{
	if (k ==3)return 0;
	if(N == n)return -INF;
	ll& ret = d[k][N];
	if (ret != -INF)return ret;
	ret = go(k, N + 1);
	ret = max(ret, max(a[N] * p[k] + go(k + 1, N + 1), a[N] * p[k] + go(k + 1, N)));
	return ret;
}
int main() {
	for (int i = 0; i < 3; i++)
		fill(d[i], d[i] + 100000, -INF);
	scanf("%d%I64d%I64d%I64d", &n, &p[0], &p[1], &p[2]);
	for (int i = 0; i < n; i++)
		scanf("%I64d", a + i);
	printf("%I64d", go(0, 0));
}