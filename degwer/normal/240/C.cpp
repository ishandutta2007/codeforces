#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	FILE *fr=fopen("input.txt","r");
	FILE *fw=fopen("output.txt","w");
	int num;
	fscanf(fr,"%d",&num);
	int ret=0;
	int now=1;
	for(;;)
	{
		if(now>=num)
		{
			break;
		}
		ret++;
		now*=2;
	}
	fprintf(fw,"%d\n",ret);
	for(int i=0;i<ret;i++)
	{
		vector<int>vec;
		for(int j=1;j<=num;j++)
		{
			if((j>>i)&1)
			{
				vec.push_back(j);
			}
		}
		fprintf(fw,"%d",int(vec.size()));
		for(int j=0;j<vec.size();j++)
		{
			fprintf(fw," %d",vec[j]);
		}
		fprintf(fw,"\n");
	}
}