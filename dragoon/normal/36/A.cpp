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

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n, prev,now,flag,t;
	int len,i;
	char word[1002];

	scanf("%d",&n);
	scanf("%s",word);
len=strlen(word);
	prev=-1;
	now=-1;
	flag=1;
	for(i=0;i<len;i++)
	{
		if(word[i]=='1')
		{
			if(prev==-1) prev = i;
			else
			{
				t = i-prev;
				if(now==-1) now = t;
				else if(now==t) ;
				else flag = 0;
				prev = i;
			}
		}
	}

	if(flag) printf("YES\n");
	else printf("NO\n");

	return 0;
}