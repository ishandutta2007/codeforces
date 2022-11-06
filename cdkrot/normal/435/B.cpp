#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


int main()
{
	std::string num; std::cin>>num;
	int k; std::cin>>k;

	for (int head=0; head<int(num.size()) and k!=0; head++)
	{
		auto max_elem=std::max_element(num.begin()+head, num.begin()+std::min(head+k+1, int(num.size())));
		if (max_elem != num.begin()+head) // do the swap;
		{
			int delta = (max_elem - num.begin()) - head;
			char cont = *max_elem;
			num.erase(max_elem);
			num.insert(num.begin()+head, cont);
			k-=delta;
		}
	}
	std::cout<<num<<std::endl;
	return 0;
}