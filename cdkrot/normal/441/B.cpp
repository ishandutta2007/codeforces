#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
	short n, v; scanf("%hd", &n); scanf("%hd", &v);
	std::vector<std::pair<short, short>> trees; trees.resize(n);
	for (auto it=trees.begin(); it!=trees.end(); it++)
	{
		scanf("%hd", &(it->first)); scanf("%hd", &(it->second));
	}
	std::sort(trees.begin(), trees.end(), [](std::pair<short,short> a, std::pair<short,short> b){return a.first<b.first;});
	
	short cur_day=1;
	short day_left=v;
	int total=0;
	for (auto it=trees.begin(); it!=trees.end(); it++)
	{
		start:
		if (it->first>cur_day)//  
		{
			cur_day=it->first;
			day_left=v;
		}
		else if (it->first+1<cur_day) // .
			continue; 
		
		if (it->second<=day_left) //  
		{
			total+=it->second;
			day_left-=it->second;
			if (day_left==0)
			{
				cur_day++;
				day_left=v;
			}
		}
		else //if (it->second>day_left) // 
		{
			total+=day_left;
			it->second-=day_left;

			cur_day++;
			day_left=v;
			goto start;
		}
	}
	printf("%d\n", total );
	return 0;
}