#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


int main()
{
	short n; std::cin>>n;
	std::vector<std::pair<short,bool>> buf; buf.resize(n);

	int x=0, y=0, y_min=0, y_max=0;
	bool mode=1; //1:+; 0:-
		for (int i=0; i<n; i++)
	{
		int d; std::cin>>d;
		x+=d;
		if (mode==1)
			y+=d;
		else
			y-=d;
		buf[i]=std::make_pair(d,mode);
		mode=1-mode;
		y_min=std::min(y, y_min);
		y_max=std::max(y, y_max);
	}
	///////////
	std::vector<std::string> out; out.resize(y_max-y_min);
	for (auto it=out.begin(); it!=out.end(); it++)
	{
		it->insert(it->begin(), x, ' ');
	}
	//std::cerr<<y_max<<" "<<y_min<<" "<<x<<" --\n";

	{
		int x=0; int y=-y_min;
		for (int i=0; i<n; i++)
		{
		//	std::cerr<<"$"<<i<<"\n";
			char c=(buf[i].second==1)?'/':'\\';
			for (int j=0; j<buf[i].first; j++)
			{
				//std::cerr<<":"<<x<<" "<<y<<" "<<buf[i].first<<"\n";
				out[y][x]=c;
				x++;
				if (j!=buf[i].first-1) y+=(2*buf[i].second-1);
		//		std::cerr<<"="<<x<<" "<<y<<"\n";

			}
		}
	}
	for (auto it=out.rbegin(); it!=out.rend(); it++)
		std::cout<<*it<<std::endl;
	return 0;
}