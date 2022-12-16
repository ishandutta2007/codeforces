#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

void toNewline()
{
	char c;
	while(scanf("%c", &c))
	{
		if(c == '\n')
			break;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	if(n%2 == 1)
		printf("contest\n");
	else
		printf("home\n");

	return 0;
}