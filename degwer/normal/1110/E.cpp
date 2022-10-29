#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d1[101010], d2[101010];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &d1[i]);
	for (int i = 0; i < num; i++)scanf("%d", &d2[i]);
	vector<int>v1, v2;
	for (int i = 1; i < num; i++)v1.push_back(d1[i] - d1[i - 1]);
	sort(v1.begin(), v1.end());
	v1.push_back(d1[0]), v1.push_back(d1[num - 1]);
	for (int i = 1; i < num; i++)v2.push_back(d2[i] - d2[i - 1]);
	sort(v2.begin(), v2.end());
	v2.push_back(d2[0]), v2.push_back(d2[num - 1]);
	printf(v1 == v2 ? "Yes\n" : "No\n");
}