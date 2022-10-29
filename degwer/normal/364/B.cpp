#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
int dp[524288]; 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 524288
class segtree
{
public:
	int seg[SIZE * 2];
	void init()
	{
		fill(seg, seg + SIZE * 2, 1000000000);
	}
	void update(int a, int b)
	{
		a += SIZE;
		seg[a] = b;
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = min(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	int get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return 1000000000;
		if (beg <= lb&&ub <= end)return seg[node];
		return min(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree tree;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	bitset<524288>bi;
	bi[0] = 1;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		bi |= bi << z;
	}
	tree.init();
	tree.update(0, 0);
	int maxi = 0, mini = 0;
	for (int i = 1; i < 524288; i++)
	{
		if (bi[i])
		{
			int t = tree.get(max(0, i - gen), i - 1, 1, 0, SIZE - 1);
			if (t >= 1000000000)continue;
			tree.update(i, t + 1);
			maxi = i;
			mini = t + 1;
		}
	}
	printf("%d %d\n", maxi, mini);
}