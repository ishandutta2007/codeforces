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
#define ABS(X) ((X) < 0 ? (-(X)) : (X))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;
//typedef __int64 LL;

int u[4000],prime[4000];
int i,j,cnt,n;

int main()
{
	u[1]=0;
	for(i=2;i<=3000;i++)
	{
		cnt=0;
		for(j=2;j<i;j++)
			if(i%j==0 && prime[j]==1)
				cnt++;

		if(cnt==0) prime[i]=1;

		if(cnt==2)
			u[i]=1;

//		printf("%d %d\n",i,u[i]);

		u[i]+=u[i-1];
	}

	scanf("%d",&n);
	printf("%d\n",u[n]);

	return 0;
}