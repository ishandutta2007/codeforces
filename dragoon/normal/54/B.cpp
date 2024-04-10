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

struct piece
{
	int r, c;
	string s;
};

bool operator<(piece A, piece B)
{
	if(A.r < B.r) return 1;
	if(A.r > B.r) return 0;

	if(A.c < B.c) return 1;
	if(A.c > B.c) return 0;

	if(A.s < B.s) return 1;
	return 0;
}

map<piece,int> M;

int A, B;
char line[30][30];

piece rotate(piece s)
{
	piece t;
	int i,j;

	t.r = s.c;
	t.c = s.r;
	for(j=0;j<s.c;j++)
		for(i=s.r-1;i>=0;i--)
			t.s += s.s[i*s.c+j];

	return t;
}

piece what(int sx,int sy, int x, int y)
{
	piece ret;
	piece s, r;

	ret.r = x;
	ret.c = y;
	ret.s="";
	int i,j;

	for(i=sx;i<sx+x;i++)
		for(j=sy;j<sy+y;j++)
		{
			ret.s += line[i][j];
		}

	s=ret;
	r = rotate(ret);
	if(r < s) s = r;
	r = rotate(r);
	if(r < s) s = r;
	r = rotate(r);
	if(r < s) s = r;

	return s;
}

int check(int x, int y)
{
	int i, j;
	piece t;

	for(i=0;i+x<=A;i+=x)
		for(j=0;j+y<=B;j+=y)
		{
			t = what(i,j,x,y);
			if(M.find(t)==M.end()) M[t]=1;
			else return 0;
		}

	return 1;
}

int main()
{
	int x, y,i;
	int ansa = 1000000, ansx, ansy;

	int cnt = 0;
	scanf("%d%d",&A,&B);
	for(i=0;i<A;i++) scanf("%s",line[i]);

	for(x=1;x<=A;x++)
		for(y=1;y<=B;y++)
		{
			
			if(A%x!=0 || B%y!=0) continue;

			M.clear();
			if(check(x,y))
			{
//				printf("%d %d\n",x,y);
				cnt++;
				if(x*y<ansa || (x*y==ansa && x<ansx))
					ansa = x*y, ansx=x, ansy=y;
			}
		}

	printf("%d\n",cnt);
	printf("%d %d\n",ansx,ansy);

	return 0;
}