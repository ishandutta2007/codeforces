#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1048576
class BIT
{
public:
	int bit[SIZE + 1];
	void add(int a, int b)
	{
		a++;
		for (;;)
		{
			bit[a] += b;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	int get(int a)
	{
		if (a < 0)return 0;
		a++;
		int ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
BIT bi;
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
int main()
{
	int num;
	scanf("%d", &num);
	vector<pi3>que;
	vector<pii>zat;
	for (int i = 0; i < num; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		que.push_back(make_pair(za, make_pair(zc, zb)));
		zat.push_back(make_pair(zc, zb));
	}
	sort(zat.begin(), zat.end());
	for (int i = 0; i < num; i++)
	{
		int low = lower_bound(zat.begin(), zat.end(), que[i].second) - zat.begin();
		int beg = lower_bound(zat.begin(), zat.end(), make_pair(que[i].second.first, -1)) - zat.begin();
		if (que[i].first == 1)bi.add(low, 1);
		else if (que[i].first == 2)bi.add(low, -1);
		else
		{
			printf("%d\n", bi.get(low) - bi.get(beg - 1));
		}
	}
}