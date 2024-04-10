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
typedef __int64 LL;

char line[1000002];
int cnt,len,i,ans;

int main()
{
	scanf("%s",line);
	len=strlen(line);
	cnt=0;
	for(i=0;i<len;i++)
	{
		if(line[i]=='(') cnt++;
		else
		{
			if(cnt)
			{
				cnt--;
				ans+=2;
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}