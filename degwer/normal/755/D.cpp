#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define SIZE 1048576
class BIT
{
public:
	ll bit[SIZE + 1];
	void add(int a, ll b)
	{
		a+=5;
		for (;;)
		{
			bit[a] += b;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	ll get(int a)
	{
		a+=5;
		ll ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
BIT bi;
int main()
{
	int num, dif;
	scanf("%d%d", &num, &dif);
	if(dif*2>num)dif=num-dif;
	ll ans = 1;
	ll now = 0;
	for (int i = 0; i < num; i++)
	{
		int x = (now + 1) % num, y = (now + dif - 1) % num;
		//printf("%d %d\n", x, y);
		if (x <= y)ans += 1 + bi.get(y) - bi.get(x - 1);
		else ans += 1 + bi.get(y) + bi.get(num) - bi.get(x - 1);
		printf("%lld ", ans);
		bi.add(now, 1);
		bi.add((now + dif) % num, 1);
		now = (now + dif) % num;
	}
	printf("\n");
}