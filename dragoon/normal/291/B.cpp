#include<stdio.h>
#include<string>
using namespace std;

char line[100005];

int main()
{
	string S;
	int len, i, j;

	gets(line);

	len = strlen(line);
	for(i = 0; i < len; i++)
	{
		if(line[i]==' ') continue;
		if(line[i]=='\"')
		{
			S="";
			for(j = i+1;;j++)
				if(line[j]=='\"')
					break;
				else
					S += line[j];
			i = j;
		}
		else
		{
			S="";
			for(j = i;;j++)
				if(line[j]==' ')
					break;
				else
					S += line[j];
			i = j;
		}

		printf("<%s>\n", S.c_str());
	}

	return 0;
}