#include <stdio.h>

int t[4][3] = {{0, 1, 2}, {3, 1, 2}, {3, 3, 2}, {3, 3, 3}};

int main()
{
	int N;
	int a[105];

	int state = 0;

	scanf("%d", &N);

	for(int i = 0; i < N; i++)	scanf("%d", &a[i]);

	for(int i = 1; i < N; i++)
	{
		if(a[i] > a[i - 1])	state = t[state][0];
		else if(a[i] == a[i - 1])	state = t[state][1];
		else	state = t[state][2];
	}

	if(state == 3)	printf("NO");
	else	printf("YES");
	return 0;
}