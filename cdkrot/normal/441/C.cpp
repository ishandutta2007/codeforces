#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

bool swap_bit;
int n, m, k;
std::vector<std::pair<int, int>> coords;
int main()
{
	scanf("%d", &n); scanf("%d", &m); scanf("%d", &k);
	////////==============GEN====================//
	/////// k<=n, (!)

	auto util = [](unsigned short i){for (unsigned short j=1; j<=m; j++) coords.emplace_back(i,j); };
	auto util_ = [](unsigned short i){for (unsigned short j=m; j!=0; j--) coords.emplace_back(i,j); };


	bool mode=true;
	for (unsigned short i=1; i<=n; i++)
	{
		if (mode)
			util(i);
		else
			util_(i);
		mode=!mode;
	}
	for (int i=0; i<k-1; i++)
	{
		printf("2 %d %d %d %d\n", coords[2*i].first, coords[2*i].second, coords[2*i+1].first, coords[2*i+1].second);
	}
	printf("%d", int(coords.size()-2*(k-1)));
	for (auto it=coords.begin()+2*(k-1); it!=coords.end(); it++)
		printf(" %d %d", it->first, it->second);
	return 0;
}