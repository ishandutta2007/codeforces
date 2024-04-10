#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef __int64 LL;
typedef pair<int,int> PII;

int i,j,rr,cc,r,c,n,k,s,flag,now;
char word[5][5];
char line[400][400];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%s",word[i]);

	now=1;
	for(i=1;i<=k;i++)
		now*=n;

	for(i=0;i<now;i++)
	{
		for(j=0;j<now;j++)
		{
			r=i, c = j;
			flag=0;
			for(s=1;s<=k;s++)
			{
				rr = r%n;
				cc = c%n;
				r/=n;
				c/=n;

				if(word[rr][cc]=='*') flag=1;
			}

			if(flag) line[i][j]='*';
			else line[i][j]='.';
		}

		line[i][j]=0;
		printf("%s\n",line[i]);
	}

	return 0;
}