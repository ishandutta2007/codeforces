#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
int N;
int Ask(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
void Ans(int i)
{
	printf("! %d\n",i);
	fflush(stdout);
	exit(0);
}

void Bin(int l,int r,int two)
{
	//printf("[%d,%d] two=%d\n",l,r,two);
	if(l==r)Ans(l);
	if(!two)two=Ask(l,r);
	if(r-l==1)
	{
		if(l==two)Ans(r);
		else Ans(l);
	}
	int m=(l+r)>>1;
	if(l<=two&&two<=m)
	{
		int res=Ask(l,m);
		if(res==two)Bin(l,m,two);
		else Bin(m,r,0);
	}
	else
	{
		int res=Ask(m,r);
		if(res==two)Bin(m,r,two);
		else Bin(l,m,0);
	}
}


int main()
{
	scanf("%d",&N);
	Bin(1,N,0);
	return 0;
}