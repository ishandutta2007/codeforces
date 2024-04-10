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

int main()
{
	vector<int> V,H;
	map<vector<int>,int> M;
	int n,i,a,ans=0,j;
	char word[2][10],line[10];

	scanf("%d",&n);
	for(int I = 0;I<n;I++)
	{
		scanf("%s%s",word[0],word[1]);
		if(I!=n-1) scanf("%s",line);

		V.clear();
		V.push_back(word[0][0]-'0');
		V.push_back(word[0][1]-'0');
		V.push_back(word[1][1]-'0');
		V.push_back(word[1][0]-'0');

		H = V;
		for(i=0;i<4;i++)
		{
			a = V.front();
			for(j=0;j<3;j++)
				V[j] = V[j+1];
			V[3] = a;

			if(H > V) H = V;
		}

//		for(i=0;i<4;i++) printf("%d ",H[i]); printf("\n");
		if(M.find(H)==M.end()) 
		{
			M[H]=1;
			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}