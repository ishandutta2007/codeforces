#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int gcd(int a, int b)
{
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	multiset<int>se;
	for (int i = 0; i < num*num; i++)
	{
		int z;
		scanf("%d", &z);
		se.insert(z);
	}
	vector<int>ans;
	for (int i = 0; i < num; i++)
	{
		multiset<int>::iterator it = se.end();
		it--;
		int z = (*it);
		se.erase(it);
		for (int i = 0; i < ans.size(); i++)
		{
			it = se.find(gcd(z, ans[i]));
			se.erase(it);
			it = se.find(gcd(z, ans[i]));
			se.erase(it);
		}
		ans.push_back(z);
	}
	for (int i = 0; i < num; i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}