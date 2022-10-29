#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num,gen;
	scanf("%d%d",&num,&gen);
	if(num<gen)
	{
		printf("-1\n");
		return 0;
	}
	if(gen==1)
	{
		if(num==1)
		{
			printf("a\n");
		}
		else
		{
			printf("-1\n");
		}
		return 0;
	}
	vector<char>vec;
	for(int i=0;i<num;i++)
	{
		if(i%2==0)
		{
			vec.push_back('a');
		}
		else
		{
			vec.push_back('b');
		}
	}
	for(int i=0;i<gen-2;i++)
	{
		vec[num-i-1]='a'+(gen-i-1);
	}
	for(int i=0;i<num;i++)
	{
		printf("%c",vec[i]);
	}
	printf("\n");
}