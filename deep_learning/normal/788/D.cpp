#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#define pb push_back
std::vector<int> ver, hor; 
inline int query(int x, int y)
{
	printf("0 %d %d\n", x, y);
	fflush(stdout); 
	int res; 
	scanf("%d", &res); 
	return res; 
}
int main()
{
	srand(time(NULL)); 
	int cur = -1e8, lst = (rand() % (int)1e8 + 1) * (rand() & 1 ? 1 : -1); 
	while (cur <= 1e8)
	{
		int res = query(cur, cur); 
		if (!res)
		{
			if (!query(cur, lst))
				ver.pb(cur); 
			if (!query(lst, cur))
				hor.pb(cur); 
			if (cur + 1000 <= 1e8 && query(cur + 1000, cur + 1000) == 1000)
				cur += 999; 
			cur++; 
		}
		else
			cur += res; 
	}
	printf("1 %d %d\n", (int)ver.size(), (int)hor.size());
	for (int x : ver)
		printf("%d ", x);
	puts(""); 
	for (int y : hor)
		printf("%d ", y);
	puts(""); 
	return 0; 
}