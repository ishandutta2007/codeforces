#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<ll, pii>pi3;
vector<int>pat[202020];
bool flag[202020];
ll ans = 0;
pi3 dfs(int node)
{
	flag[node] = true;
	ll od = 0, ev = 1, sum = 0;
	ll ret = 0;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (flag[pat[node][i]])continue;
		pi3 z = dfs(pat[node][i]);
		ret += z.first*(od + ev) + (z.second.first + z.second.second)*sum - z.second.first*od;
		sum += z.first, od += z.second.first, ev += z.second.second;
	}
	ans += ret;
	return make_pair(sum + ev, make_pair(ev, od));
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb), pat[zb].push_back(za);
	}
	dfs(0);
	printf("%I64d\n", ans);
}