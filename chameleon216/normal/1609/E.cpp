#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=100100;
int N,M;
char S[MX];

struct Matrix
{
	int x[3][3];
//	Matrix(){memset(x,0,sizeof(x));}
};
Matrix operator*(const Matrix& a,const Matrix& b)
{
	Matrix c;
	memset(c.x,0x3f,sizeof(c.x));
	Fr(i,0,2)Fr(k,0,2)Fr(j,0,2)
		c.x[i][j]=min(c.x[i][j],a.x[i][k]+b.x[k][j]);
	return c;
}

Matrix MakeMatrix(char c)
{
	Matrix a;
	memset(a.x,0x3f,sizeof(a.x));
	a.x[0][0]=c=='a';
	a.x[0][1]=c!='a';
	a.x[1][1]=c=='b';
	a.x[1][2]=c!='b';
	a.x[2][2]=c=='c';
	return a;
}

Matrix val[MX*4];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
void Build(int i,int l,int r)
{
	if(l==r){val[i]=MakeMatrix(S[l]);return;}
	Build(li,l,mid);
	Build(ri,mid+1,r);
	val[i]=val[li]*val[ri];
}
void Modify(int i,int l,int r,int a,char c)
{
	if(l==r){val[i]=MakeMatrix(c);return;}
	if(a<=mid)Modify(li,l,mid,a,c);
	else Modify(ri,mid+1,r,a,c);
	val[i]=val[li]*val[ri];
}

int main()
{
	scanf("%d%d%s",&N,&M,S+1);
	Build(1,1,N);
	Fr(i,1,M)
	{
		int x;
		char c;
		scanf("%d %c",&x,&c);
		Modify(1,1,N,x,c);
		Matrix a=val[1];
//		printf("%d %d %d\n",a.x[0][0],a.x[0][1],a.x[0][2]);
		printf("%d\n",min(min(a.x[0][0],a.x[0][1]),a.x[0][2]));
	}
	return 0;
}