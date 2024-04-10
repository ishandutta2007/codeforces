#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
vector<pii>ko[100000];
ll dat[100000];
int ans = 0;
void dfs(int node, ll d)
{
	if (d > dat[node])
	{
		return;
	}
	ans++;
	for (int i = 0; i < ko[node].size(); i++)
	{
		dfs(ko[node][i].first, max(d + ko[node][i].second, 0LL));
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &dat[i]);
	for (int i = 1; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		ko[za].push_back(make_pair(i, zb));
	}
	dfs(0, 0);
	printf("%d\n", num - ans);
}