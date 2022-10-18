#include<stdio.h>
#include<map>
using namespace std;

map<int, int> M;
map<int, int>::iterator iM;

int main()
{
	int n, i, ans, a;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a);
		M[a] = M[a] + 1;
	}

	ans = 0;
	for(iM = M.begin(); iM!=M.end(); iM++)
		if(iM->first!=0)
		{
			if(iM->second > 2) ans = -1000000;
			if(iM->second == 2) ans++;
		}

	if(ans < 0) ans = -1;

	printf("%d\n", ans);

	return 0;
}