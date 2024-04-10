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

int dr[]={0,0,1,-1,-1,-1,1,1};
int dc[]={1,-1,0,0,1,-1,1,-1};

char line[5200];
string S;
int sz;
vector<string> V;
vector<int> ans;

int rec(int at)
{
	//V[at]==table

	int cnt=0;
	while(1)
	{
		at++;

		if(V[at]=="table")
		{
			at = rec(at);
		}
		else if(V[at]=="/table")
			break;
		else if(V[at]=="tr")
			continue;
		else if(V[at]=="/tr")
			continue;
		else if(V[at]=="td")
			cnt++;
		else if(V[at]=="/td")
			continue;
	}

	ans.push_back(cnt);
	return at;
}

int main()
{
	while(scanf("%s",line)!=EOF)
	{
		S += line;
	}

	int i;
	string A;

	for(i=0;i<S.size();i++)
		if(S[i]=='<' || S[i]=='>')
			S[i]=' ';

	istringstream iS(S);
	while(iS>>A)
	{
		V.push_back(A);
	}

	sz = V.size();
	rec(0);

	sort(ans.begin(),ans.end());
	sz = ans.size();
	for(i=0;i<sz;i++)
	{
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}