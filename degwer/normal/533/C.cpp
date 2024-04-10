#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int ax, ay, bx, by;
	scanf("%d%d%d%d", &ax, &ay, &bx, &by);
	if (ax <= bx&&ay <= by)
	{
		printf("Polycarp\n");
		return 0;
	}
	if (ax + ay <= bx + by - min(bx, by))
	{
		printf("Polycarp\n");
	}
	else printf("Vasiliy\n");
}