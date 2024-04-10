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
int a[100001];
bool chk[100001];
int cnt;
void dfs(int N)
{
	cnt++;
	chk[N] = 1;
	if (!chk[a[N]])
		dfs(a[N]);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	Vi v;
	for (int i = 1; i <= n; i++)
	{
		if (!chk[i])
		{
			cnt = 0;
			dfs(i);
			v.push_back(cnt);
		}
	}
	sort(v.begin(), v.end());
	int N = v.size();
	if (N == 1)
	{
		printf("%I64d", 1LL * n*n);
		return 0;
	}
	v[N - 2] += v[N - 1];
	ll ans = 0;
	for (int i = N - 2; i >= 0; i--)
	{
		ans += 1LL * v[i] * v[i];
	}
	printf("%I64d", ans);
}