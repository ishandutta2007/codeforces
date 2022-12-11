#include<cstdio>
#include<cstdlib>
int x,y;
void ans(int x)
{
	putchar(x?(x==1?'>':'<'):'='),putchar('\n');
	exit(0);
}
int t[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,-1,0},{0,0,1,0,1},{0,0,0,-1,0}};
int main()
{
	scanf("%d%d",&x,&y);
	if (x==y) ans(0);
	if (x==1) ans(-1);
	if (y==1) ans(1);
	if (x<=4&&y<=4) ans(t[x][y]);
	ans(x>y?-1:1);
}