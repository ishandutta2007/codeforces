#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int a[100];
int n, x;
bool F(int k)
{
	for (int i = 0; i < n; i++)
		if (a[i] == k)return 1;
	return 0;
}
int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	int c = 0;
	for (int i = 0; i < x; i++)
		if (!F(i))c++;
	if (F(x))c++;
	printf("%d", c);
}