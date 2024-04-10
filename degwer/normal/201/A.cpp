#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	if(num==3)
	{
		num=6;
	}
	for(int i=1;;i+=2)
	{
		if((i*i+1)/2>=num)
		{
			printf("%d\n",i);
			return 0;
		}
	}
}