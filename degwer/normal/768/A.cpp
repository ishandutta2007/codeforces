#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	sort(v.begin(), v.end());
	int c = 0;
	for (int i = 0; i < num; i++)if (v[i] != v[0] && v[i] != v[v.size() - 1])c++;
	printf("%d\n", c);
}