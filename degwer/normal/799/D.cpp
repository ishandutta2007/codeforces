#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
set<pii>se;
int main()
{
	ll mx, my, nx, ny;
	int num;
	scanf("%I64d%I64d%I64d%I64d%d", &mx, &my, &nx, &ny, &num);
	vector<ll>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	queue<pi3>que;
	que.push(make_pair(make_pair(nx, ny),0));
	que.push(make_pair(make_pair(ny, nx),0));
	for (;;)
	{
		if (que.empty())
		{
			printf("-1\n");
			return 0;
		}
		pi3 z = que.front();
		que.pop();
		if (se.find(z.first) != se.end())continue;
		se.insert(z.first);
		ll x = z.first.first, y = z.first.second;
		if (x >= mx&&y >= my)
		{
			printf("%I64d\n", z.second);
			return 0;
		}
		if (z.second >= vec.size())continue;
		if (x < mx)que.push(make_pair(make_pair(x*vec[z.second], y), z.second + 1));
		if (y < my)que.push(make_pair(make_pair(x, vec[z.second]*y), z.second + 1));
	}
}