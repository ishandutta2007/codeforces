#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>v1, v2;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		if (za < zb)v1.push_back(make_pair(-zb, i));
		else v2.push_back(make_pair(za, i));
	}
	sort(v1.begin(), v1.end()), sort(v2.begin(), v2.end());
	if (v1.size() < v2.size())swap(v1, v2);
	printf("%d\n", v1.size());
	for (int i = 0; i < v1.size(); i++)printf("%d\n", v1[i].second + 1);
}