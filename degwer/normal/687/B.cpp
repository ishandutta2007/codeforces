#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
vector<int>getfact(int n)
{
	vector<int>ret;
	for (int i = 2;; i++)
	{
		if (i*i > n)break;
		if (n%i == 0)
		{
			ret.push_back(1);
			for (;;)
			{
				if (n%i == 0)
				{
					n /= i;
					ret[ret.size() - 1] *= i;
				}
				else break;
			}
		}
	}
	if (n != 1)ret.push_back(n);
	return ret;
}
int main()
{
	int num, k;
	scanf("%d%d", &num, &k);
	vector<int>r = getfact(k);
	bool dat[100];
	fill(dat, dat + 100, false);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		for (int j = 0; j < r.size(); j++)if (z%r[j] == 0)dat[j] = true;
	}
	bool a = true;
	for (int i = 0; i < r.size(); i++)a &= dat[i];
	if (a)printf("Yes\n");
	else printf("No\n");
}