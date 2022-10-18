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

struct PP
{
	int start,id,end;
	PP(int a,int b,int c)
	{
		start=a, end=b, id=c;
	}

	PP(){}
};

PP V[200];

int main()
{
	int L,b,f,id,num,i,j;
	int sz,n;

	scanf("%d%d%d",&L,&b,&f);
	V[0]=PP(-b,-b,0) ;
	V[1]=PP(L+f,L+f,0) ;

	scanf("%d",&n);
	sz = 2;
	int ID=0;
	while(n--)
	{
		ID++;
		scanf("%d%d",&id,&num);

		if(id==1)
		{
			for(i=1;i<sz;i++)
			{
				if(V[i-1].end+b+f+num <= V[i].start)
				{
					for(j=sz-1;j>=i;j--)
						V[j+1]=V[j];
					V[i] = PP(V[i-1].end+b,V[i-1].end+b+num,ID);
					printf("%d\n",V[i-1].end+b);
					sz++;
					goto end;
				}
			}

			printf("-1\n");
end:
			sz=sz;
		}
		else
		{
			for(i=0;i<sz;i++)
				if(V[i].id==num)
					break;

			for(i=i+1;i<sz;i++)
				V[i-1]=V[i];
			sz--;
		}

	}

	return 0;
}