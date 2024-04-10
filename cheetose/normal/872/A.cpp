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
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
int a[9], b[9];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < m; i++)
		scanf("%d", b + i);
	int ans = INF;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])ans = min(ans, a[i]);
			else
			{
				int t1 = 10 * a[i] + b[j];
				int t2 = 10 * b[j] + a[i];
				ans = min(ans, t1);
				ans = min(ans, t2);
			}
		}
	printf("%d", ans);
}