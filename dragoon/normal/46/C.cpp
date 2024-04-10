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

int pos[2200];
char word[2000];

int main()
{
	int n,h,t,cnt,ans,i,j;

	scanf("%d",&n);
	scanf("%s",word);
	h=t=0;
	for(i=0;i<n;i++)
	{
		if(word[i]=='H') {pos[i]=pos[i+n]=1; h++;}
		else {pos[i]=pos[i+n]=0; t++;}
	}

	cnt=0;
	for(i=0;i<h;i++)
		cnt+=pos[i];

	ans = h-cnt;

	for(i=0,j=h;j<2*n;i++,j++)
	{
		cnt-=pos[i];
		cnt+=pos[j];
		if(h-cnt<ans)
			ans=h-cnt;
	}

	printf("%d\n",ans);

	return 0;
}