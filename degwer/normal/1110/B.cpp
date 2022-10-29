#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[101010];
int main()
{
	int num, len, gen;
	scanf("%d%d%d", &num, &len, &gen);
	for (int i = 0; i < num; i++)scanf("%d", &d[i]);
	vector<int>v;
	for (int i = 0; i < num - 1; i++)v.push_back(d[i + 1] - d[i] - 1);
	sort(v.begin(), v.end());
	int r = 0;
	for (int i = 0; i < num - gen; i++)r += v[i];
	printf("%d\n", r + num);
}