#include<cstdio>
int n,m;
struct Pair{
	int x,y;
}A[15],B[15];
int ca[15],cb[15];
int num=-1;
int getsame(int x,int y)
{
	if (A[x].x==B[y].x&&A[x].y!=B[y].y) return A[x].x;
	if (A[x].x==B[y].y&&A[x].y!=B[y].x) return A[x].x;
	if (A[x].y==B[y].x&&A[x].x!=B[y].y) return A[x].y;
	if (A[x].y==B[y].y&&A[x].x!=B[y].x) return A[x].y;
	return -1;
}
int main()
{
	int tmp;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&A[i].x,&A[i].y);
	for (int i=1;i<=m;i++) scanf("%d%d",&B[i].x,&B[i].y);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			tmp=getsame(i,j);
			if (tmp==-1) continue;
			if (!ca[i]) ca[i]=tmp;
			else if (ca[i]!=tmp){return puts("-1"),0;}
			if (!cb[j]) cb[j]=tmp;
			else if (cb[j]!=tmp){return puts("-1"),0;}
			if (num==-1) num=tmp;
			else if (num!=tmp) num=0;
		}
	printf("%d\n",num);
	return 0;
}