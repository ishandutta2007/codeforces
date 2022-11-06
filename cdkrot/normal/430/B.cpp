#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;




struct item
{
	short begin;
	short end;
	short color;
};

vector< item > data;


int collapse(short ind)
{
	int result = data[ind].end-data[ind].begin+1;
	if (result<2) return 0;

	int off=0;
	st:
	if (0 < ind-off and ind+off < data.size()-1)
	{
		off++;
		if (data[ind-off].color == data[ind+off].color)
		{
			int delta_res = (data[ind-off].end-data[ind-off].begin + data[ind+off].end-data[ind+off].begin)+2;
			if (delta_res>=3)
			{
				result+=delta_res;
				goto st;
			}
		}
	}
	return result;
}

int main()
{
	short n; scanf("%hd", &n);
	short k; scanf("%hd", &k);
	short S; scanf("%hd", &S);
	vector<short> indexes;
	for (short i=0; i<n; i++)
	{
		short a;
		scanf("%hd", &a);
		//printf("d%d", i);

		if (data.size()!=0 and data[data.size()-1].end==i-1 and data[data.size()-1].color==a)
			data[data.size()-1].end++;
		else
		{
			//printf("n%d", i);
			if (a==S)
				indexes.emplace_back(short(data.size()));
			item itm={i,i,a};
			data.push_back(itm);
		}
	}
	//for (auto it=data.begin(); it!= data.end(); it++)
	//	printf("%d %d %d\n", it->begin, it->end, it->color);
	int best=0;
	for (auto it=indexes.begin(); it!=indexes.end(); it++)
		best=max(best, collapse(*it));
	printf("%d\n", best);
	return 0;
}