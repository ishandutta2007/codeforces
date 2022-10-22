#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=120;
int N,B[MX][MX];
vector<pair<int,int> > P[2];

void Color(int c,int x,int y)
{
	B[x][y]=c;
	printf("%d %d %d\n",c,x,y);
	fflush(stdout);
}

int Read()
{
	int x;
	scanf("%d",&x);
	return x;
}

int main()
{
	scanf("%d",&N);
	Fr(x,1,N)Fr(y,1,N)
		P[(x^y)&1].push_back(make_pair(x,y));
	int i=0,j=0,g=0;
	while(1)
	{
		if(i==(int)P[0].size()){g=1;break;}
		if(j==(int)P[1].size()){g=2;break;}
		int a=Read(),c=1+(a==1);
		pair<int,int> p=(c==1?P[0][i++]:P[1][j++]);
		Color(c,p.first,p.second);
	}
	Fr(x,1,N)Fr(y,1,N)if(!B[x][y])
	{
		int a=Read(),c=1;
		for(;c==a||c==g;++c);
		Color(c,x,y);
	}
//	Fr(x,1,N)Fr(y,1,N)printf("%d%c",B[x][y]," \n"[y==N]);
	return 0;
}