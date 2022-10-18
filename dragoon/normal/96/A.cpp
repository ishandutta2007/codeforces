#include<stdio.h>
#include<string.h>

int main()
{
	char line[1000];
	scanf("%s",line);
	int L,i,j,now;

	L = strlen(line);

	for(i=0;i<L;i++)
	{
		for(j=i;j<L;j++)
			if(line[i]!=line[j])
				break;

		now = j-i;

		if(now>6)
			goto e;
	}
e:
	if(now>6) printf("YES\n");
	else printf("NO\n");

	return 0;
}