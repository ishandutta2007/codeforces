#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

//typedef __int64 LL;
//#define I64d "%I64d"
//typedef long long LL;
//#define I64d "%lld"

int a[3000];

int main() 
{
	int n,d;
	int i,z,ans;

	scanf("%d%d",&n,&d);
	for(i=0;i<n;i++) scanf("%d",&a[i]);

	ans=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>a[i-1]) continue;

		z=a[i-1]+1-a[i];

		if(z%d==0) ans+=z/d, a[i]+=d*(z/d);
		else ans+=z/d+1, a[i]+=d*(z/d+1);
	}

	printf("%d\n",ans);

	return 0;
}