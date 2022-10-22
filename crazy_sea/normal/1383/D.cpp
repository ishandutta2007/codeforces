#include<cstdio>
#include<algorithm>
using namespace std;
const int N=310,M=N*N;
int n,m,a[N][N],t[M],r[N],c[N],x,X,Y;
int qx[M],qy[M],head,tail;
void push(int x,int y)
{
	qx[++tail]=x,qy[tail]=y;
}
void get_top()
{
	X=qx[++head],Y=qy[head];
}
void push1(int x,int y1,int y2,bool tp)
{
	if(!tp) for(int i=y1;i<=y2;i++) push(x,i);
	else for(int i=y2;i>=y1;i--) push(x,i);
}
void push2(int y,int x1,int x2,bool tp)
{
	if(!tp) for(int i=x1;i<=x2;i++) push(i,y);
	else for(int i=x2;i>=x1;i--) push(i,y);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&x),r[i]=max(r[i],x),c[j]=max(c[j],x);
	for(int i=1;i<=n;i++) t[r[i]]|=1;
	for(int j=1;j<=m;j++) t[c[j]]|=2;
	int R=0,C=0,w1,w2;
	for(int x=n*m;x;x--)
	{
		if(t[x]==3) a[w1=++R][w2=++C]=x,push1(R,1,C-1,1),push2(C,1,R-1,1);
		if(t[x]==0) get_top(),a[X][Y]=x;
		if(t[x]==1) a[++R][w2]=x,push1(R,1,w2-1,1),push1(R,w2+1,C,0);
		if(t[x]==2) a[w1][++C]=x,push2(C,1,w1-1,1),push2(C,w1+1,R,0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}