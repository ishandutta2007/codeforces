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

int m[300][300];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int i,j,k;
/*
	while(1)
	{
		scanf("%d",&k);
		if(k==0) break;
		for(i=0;i<=50;i++)
			for(j=0;j<=50;j++)
			{
				if(!i && !j) m[i][j]=0;
				else if( (i && m[i-1][j]==0) || (j && m[i][j-1]==0) || (i>=k && j>=k && m[i-k][j-k]==0)) m[i][j]=1;
				else m[i][j]=0;
			}

			printf("\n\n\n%d\n",k);
		for(i=0;i<=50;i++)
		{
			for(j=0;j<=50;j++)
				printf("%d",m[i][j]);
			printf("\n");
		}
	}
*/

	int t,ks,m,n;

	scanf("%d%d",&t,&k);
	for(ks=1;ks<=t;ks++)
	{
		scanf("%d%d",&n,&m);
		n--, m--;

		if(n<m) swap(n,m);


		if(1==k)
		{
			if((n&1) || (m&1) ) printf("+\n");
			else printf("-\n");
			continue;
		}

		if(m>=k && (m-k)%(k+1)==0)
		{
			printf("+\n");
			continue;
		}

		if(m<k)
		{
			n-=m;
			if(n&1) printf("+\n");
			else printf("-\n");
			continue;
		}

		i = (m-k)/(k+1);

		if(!(i&1))
		{
			n-=m;
			if(n&1) printf("-\n");
			else printf("+\n");
			continue;

		}
		else
		{
			n-=m;
			if(n&1) printf("+\n");
			else printf("-\n");
			continue;
		}

	}

	return 0;
}