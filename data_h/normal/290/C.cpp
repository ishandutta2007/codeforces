#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int TUX;

int main()
{
	scanf("%d", &TUX);
	int FOO = 0;
	int BAR = 0;
	int BAZ = 0;
	int QUZ = 1;
	for(int i = 1; i <= TUX; i++)
	{
		int PUR;
		scanf("%d", &PUR);
		FOO = FOO + PUR;
		BAR = BAR + 1;
		if (FOO * QUZ > BAR * BAZ && FOO * QUZ)
		{
			BAZ = FOO;
			QUZ = BAR;
		}
	}
	printf("%.6lf", (double)BAZ / QUZ);
	return 0;
}