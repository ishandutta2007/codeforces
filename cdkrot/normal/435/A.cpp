#include <stdio.h>



int main()
{
	int n; scanf("%d", &n);
	int m; scanf("%d", &m);
	int space_left=m;
	int bus_count=1;
	for (int i=0; i<n; i++)
	{
		int group_size; scanf("%d", &group_size);
		if (group_size <= space_left)
			space_left-=group_size;
		else
		{
			bus_count++;
			space_left=m-group_size;
		}
	}
	printf("%d\n", bus_count);
	
	return 0;
}