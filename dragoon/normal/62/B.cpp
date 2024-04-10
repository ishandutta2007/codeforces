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
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))
#define in(a,b,c) (a>=b && a<=c)
#define SORT(A) sort(A.begin(),A.end())
#define SZ(X) (int)(X.size())
#define D2(x1,y1,x2,y2) ( S((x1)-(x2)) + S((y1)-(y2)) )

typedef pair<int,int> PII;
typedef __int64 LL;

//int dr[]={0,0,1,-1,-1,-1,1,1};
//int dc[]={1,-1,0,0,1,-1,1,-1};

char text[100002];
char word[200002];
int next[100002][30];
int prev[100002][30];

int main()
{
	int n,k,i,j,pos,L;
	LL ans;

	scanf("%d%d",&n,&k);
	scanf("%s",text);
	for(i=0;i<k;i++)
		for(j='a';j<='z';j++)
			next[i][j-'a']=prev[i][j-'a']=-1;

	for(i=0;i<k;i++)
	{
		if(i)
		{
			for(j='a';j<='z';j++)
				prev[i][j-'a']=prev[i-1][j-'a'];
		}

		prev[i][ text[i]-'a' ] = i;
	}

	for(i=k-1;i>=0;i--)
	{
		if(i<k-1)
		{
			for(j='a';j<='z';j++)
				next[i][j-'a']=next[i+1][j-'a'];
		}

		next[i][ text[i]-'a' ] = i;
	}

	while(n--)
	{
		scanf("%s",word);
		L = strlen(word);
		ans = 0;
		for(i=0;word[i];i++)
		{
			if(prev[k-1][ word[i]-'a' ]==-1) {ans+=L; continue;}

			if(i>=k) pos = ABS(i-prev[k-1][word[i]-'a']);
			else
			{
				if(prev[i][word[i]-'a']==-1) pos = ABS(i-next[i][word[i]-'a']);
				else if(next[i][word[i]-'a']==-1) pos = ABS(i-prev[i][word[i]-'a']);
				else pos = MIN( ABS(i-next[i][word[i]-'a']),ABS(i-prev[i][word[i]-'a']) );
			}

			ans+=pos;
		}

		printf("%I64d\n",ans);
	}

	return 0;
}