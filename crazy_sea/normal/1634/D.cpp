#include<cstdio>
#include<algorithm>
using namespace std;
int T,x,y,z,a,b,c,d,k,n;
int out(int a,int b,int c)
{
	int x;
	printf("? %d %d %d\n",a,b,c);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
void work(int A,int B,int C,int D)
{
	a=out(A,B,C);
	b=out(A,B,D);
	c=out(A,C,D);
	d=out(B,C,D);
	k=max(max(a,b),max(c,d));
	if(a==k)
	{
		if(a==b) x=A,y=B,z=C;
		else if(a==c) x=A,y=C,z=B;
		else if(a==d) x=B,y=C,z=A;
	}
	else if(b==k)
	{
		if(b==c) x=A,y=D,z=C;
		else if(b==d) x=B,y=D,z=C;
	}
	else if(c==d&&c==k) x=C,y=D,z=A;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		work(1,2,3,4);
		for(int i=5;i+1<=n;i+=2) work(x,y,i,i+1);
		if(n&1) work(x,y,z,n);
		printf("! %d %d\n",x,y);
//		bool p;
//		if(a==0||b==0||c==0||d==0) p=1;
//		else p=0;
//		for(int i=5;i<=n;i++)
//		{
//			a=out(x,y,i);
//			if(a<=k) continue;
//			if(p) work(x,y,z,i),p=0;
//			else
//			{
//				k=a;
//				if(out(x,z,i)==a) y=i;
//				else x=i;
//			}
//		}
//		printf("! %d %d\n",x,y);
		fflush(stdout);
	}
}