#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1010;
int N,pr[MX],nx[MX],P[MX];
void Link(int x,int y){nx[x]=y,pr[y]=x;}

int Next(int x)
{
	printf("? ");
	Fr(i,1,N)printf("%d ",1+(i==x));
	putchar('\n');
	fflush(stdout);
	int a;
	scanf("%d",&a);
	return a;
}

int Prev(int x)
{
	printf("? ");
	Fr(i,1,N)printf("%d ",2-(i==x));
	putchar('\n');
	fflush(stdout);
	int a;
	scanf("%d",&a);
	return a;
}

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		int p=Prev(i),n=Next(i);
		if(p&&p!=i)Link(p,i);
		if(n&&n!=i)Link(i,n);
	}
	Fr(i,1,N)if(!pr[i])
	{
		for(int j=i,k=1;j;j=nx[j],++k)
			P[j]=k;
	}
	printf("! ");
	Fr(i,1,N)printf("%d ",P[i]);
	putchar('\n');
	return 0;
}