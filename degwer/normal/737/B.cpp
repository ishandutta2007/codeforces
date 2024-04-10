#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, kai, len, sh;
	scanf("%d%d%d%d", &num, &kai, &len, &sh);
	vector<int>v;
	v.push_back(1);
	for (int i = 0; i < num; i++)
	{
		char z;
		scanf(" %c", &z);
		v.push_back(z - '0');
	}
	v.push_back(1);
	vector<int>ans;
	int now = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 1)now = 0;
		else now++;
		if (now != 0 && now%len == 0)ans.push_back(i);
	}
	printf("%d\n", max(int(ans.size()) - kai + 1, 0));
	for (int i = 0; i < max(int(ans.size()) - kai + 1, 0); i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
}