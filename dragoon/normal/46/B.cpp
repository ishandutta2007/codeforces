#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<math.h>
#include<stack>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define D(x1,y1,x2,y2) (sqrt( S((x1)-(x2)) + S((y1)-(y2)) ))
#define D2(x1,y1,x2,y2) ( S((x1)-(x2)) + S((y1)-(y2)) )
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))

typedef pair<int,int> PII;
//typedef long long LL;
//typedef __int64 LL;

//int dr[]={0,-1,-1,-1,0,1,1,1};
//int dc[]={-1,-1,0,1,1,1,0,-1};

char ans[10][10]=
{
	"S","M","L","XL","XXL"
};

char word[10];

int main()
{
	int i,n[10],k,j,type;

	for(i=0;i<5;i++)
		scanf("%d",&n[i]);
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%s",word);

		if(strcmp(word,"S")==0) type=0;
		if(strcmp(word,"M")==0) type=1;
		if(strcmp(word,"L")==0) type=2;
		if(strcmp(word,"XL")==0) type=3;
		if(strcmp(word,"XXL")==0) type=4;

		for(j=0;j<5;j++)
		{
			if(type+j>=0 && type+j<5 && n[type+j]>0)
			{
				n[type+j]--;
				printf("%s\n",ans[type+j]);
				goto end;
			}
			if(type-j>=0 && type-j<5 && n[type-j]>0)
			{
				n[type-j]--;
				printf("%s\n",ans[type-j]);
				goto end;
			}
		}

end:
		i=i;
	}

	return 0;
}