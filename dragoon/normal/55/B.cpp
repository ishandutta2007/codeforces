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

LL num[10];
char sign[10][10];
LL ans;

void DO(int at, vector<LL> V)
{
	vector<LL> S;
	if(V.size()==1)
	{
		if(ans<0 || ans>V[0]) ans = V[0];
	}
	int i,j,k;

	for(i=0;i<V.size();i++)
		for(j=i+1;j<V.size();j++)
		{
			S.clear();
			if(sign[at][0]=='+') S.push_back( V[i]+V[j] );
			else if(sign[at][0]=='*') S.push_back( V[i]*V[j] );
			for(k=0;k<V.size();k++) if(k!=i && k!=j) S.push_back( V[k] );
			DO(at+1,S);
		}
}

int main()
{
	int i;
	vector<LL> V;
	for(i=0;i<4;i++) scanf("%I64d",&num[i]);
	for(i=0;i<3;i++) scanf("%s",sign[i]);

	for(i=0;i<4;i++) V.push_back(num[i]);
	ans = -1;
	DO(0,V);
	printf("%I64d\n",ans);

	return 0;
}