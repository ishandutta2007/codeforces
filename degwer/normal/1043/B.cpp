#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	int now = 0;
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z - now);
		now = z;
	}
	vector<int>t;
	for (int i = 1; i <= num; i++)
	{
		bool f = true;
		for (int j = 0; j < num; j++)if (v[j] != v[j%i])f = false;
		if (f)t.push_back(i);
	}
	printf("%d\n", t.size());
	for (int i = 0; i < t.size(); i++)printf("%d\n", t[i]);
}