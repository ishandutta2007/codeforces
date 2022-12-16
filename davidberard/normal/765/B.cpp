#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	int pos = 0;
	int problem = 0;
	while(scanf("%c", &c))
	{
		if(c == '\n')
			break;
		int v = (c - 'a' + 1);
		if(v - pos > 1)
		{
			problem = 1;
			printf("NO\n");
			break;
		}
		if(v > pos)
			pos = v;
	}
	if(!problem)
		printf("YES\n");
	

	return 0;
}