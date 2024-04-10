#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
ll dat[400000];
int ans[400000];
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	for (int i = 0; i < num; i++)scanf("%I64d", &dat[i]);
	priority_queue<pii>que;
	ll s = 0;
	for (int i = 0; i < num + kai; i++)
	{
		if (i < num)que.push(make_pair(dat[i], i));
		if (kai <= i)
		{
			pii z = que.top();
			que.pop();
			ans[z.second] = i;
			s += (i - z.second)*z.first;
		}
	}
	printf("%I64d\n", s);
	for (int i = 0; i < num; i++)printf("%d ", ans[i] + 1);
	printf("\n");
}