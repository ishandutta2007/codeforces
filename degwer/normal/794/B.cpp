#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int num;
	double h;
	scanf("%d%lf", &num, &h);
	for (int i = 1; i < num; i++)
	{
		printf("%.10lf\n", sqrt(h*h / num*i));
	}
}