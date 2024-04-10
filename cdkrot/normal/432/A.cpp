#include <stdio.h>

using namespace std;

int main()
{
	short n, k;
	scanf("%hd", &n); scanf("%hd", &k);
	int R=0;
	for (int i=0; i<n; i++)
	{
		short V;
		scanf("%hd", &V);
		if (k+V<=5)
			R++;
	}
	printf("%d\n", R/3);
	return 0;
}