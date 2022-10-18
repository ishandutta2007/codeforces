#pragma warning(disable:4786)
#include<stdio.h>
#include<string> 
#include<map>
using namespace std;

char name[1004][40];
int point[1004];

int mx, i, n;
map<string,int> Score, S;

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d",name[i],&point[i]);
		Score[ name[i] ] += point[i];
	}

	mx = 0;
	for(i=0;i<n;i++)
		if(mx < Score[ name[i] ])
			mx = Score[ name[i] ];

	for(i=0;i<n;i++)
	{
		S[ name[i] ] += point[i];

		if( Score[ name[i] ] == mx && S[ name[i] ]>=mx )
			break;
	}

	printf("%s\n",name[i]);



	return 0;
}