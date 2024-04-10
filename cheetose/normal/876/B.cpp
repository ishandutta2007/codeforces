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
#define X first
#define Y second
#define INF 987654231
#define PI 3.14159265358979323
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
int a[100000],b[100000],cnt[100000];
int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		b[i] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		b[i] %= m;
		cnt[b[i]]++;
	}
	bool ok = 0;
	int what;
	for (int i = 0; i < m; i++)
		if (cnt[i] >= k)
		{
			what = i;
			ok = 1;
		}
	if (!ok)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	VI ans;
	for (int i = 0; i < n; i++)
	{
		if (b[i] == what)ans.push_back(a[i]);
	}
	for (int i = 0; i < k; i++)
		printf("%d ", ans[i]);
}