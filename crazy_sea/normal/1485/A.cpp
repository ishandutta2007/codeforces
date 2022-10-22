#include<cstdio>
#define N 1000010
using namespace std;
struct queue{
	int qx[N],qy[N],qz[N],head,tail;
	void push(int a,int b,int c)
	{
		qx[tail]=a;
		qy[tail]=b;
		qz[tail]=c;
		tail++;
	}
	void gettop(int&a,int&b,int&c)
	{
		a=qx[head];
		b=qy[head];
		c=qz[head];
	}
	void pop(){head++;}
	void clear(){head=tail=0;}
}q;
int T,a,b,c;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		q.clear();
		q.push(a,b,0);
		while(1)
		{
			q.gettop(a,b,c);
			q.pop();
			if(a==0||a/b==0)
			{
				printf("%d\n",c+(a>0));
				break;
			}
			q.push(a/b,b,c+1);
			q.push(a,b+1,c+1);
		}
	}
	return 0;
}