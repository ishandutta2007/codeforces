#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 262144
class segtree
{
public:
	int seg[SIZE * 2];
	void update(int a, int b)
	{
		a += SIZE;
		seg[a] = max(seg[a], b);
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = max(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	int get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return 0;
		if (beg <= lb&&ub <= end)return seg[node];
		return max(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree tree;
typedef pair<int, int>pii;
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>vec;
	vector<int>zv;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		vec.push_back(make_pair(za, zb));
		zv.push_back((za + zb));
	}
	sort(vec.begin(), vec.end());
	sort(zv.begin(), zv.end());
	for (int i = 0; i < num; i++)
	{
		int upp = upper_bound(zv.begin(), zv.end(), vec[i].first - vec[i].second) - zv.begin() - 1;
		int g = 0;
		if (upp >= 0)g = tree.get(0, upp, 1, 0, SIZE - 1);
		int low = lower_bound(zv.begin(), zv.end(), vec[i].first + vec[i].second) - zv.begin();
		tree.update(low, g + 1);
	}
	printf("%d\n", tree.get(0, SIZE - 1, 1, 0, SIZE - 1));
}