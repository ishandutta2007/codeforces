#include <iostream>
#include <cstdio>
#include <set>
using namespace std; 
int main()
{
	// freopen("712C.in", "r", stdin); 
	int x, y, cnt = 0; 
	scanf("%d%d", &x, &y); 
	multiset<int> se; 
	se.insert(y); 
	se.insert(y); 
	se.insert(y); 
	while (true)
	{
		int tmp = *se.begin(); 
		if (tmp == x)
		{
			printf("%d\n", cnt);
			return 0; 
		}
		se.erase(se.begin()); 
		se.insert(min(x, *se.begin() + *(--se.end()) - 1)); 
		cnt++; 
	}
	return 0; 
}