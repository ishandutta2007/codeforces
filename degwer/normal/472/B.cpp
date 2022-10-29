#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < num; i += gen)ans += (v[i] - 1) * 2;
	printf("%d\n", ans);
}