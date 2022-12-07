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
int res(int n)
{
	int c = n;
	while (n)
	{
		c += n % 10;
		n /= 10;
	}
	return c;
}
int main() {
	int n;
	scanf("%d", &n);
	VI ans;
	for (int i = max(n - 200, 0); i <= n; i++)
	{
		if (res(i) == n) ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}