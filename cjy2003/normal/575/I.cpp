#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,q;
struct BIT1
{
	int sum[5050];
	inline void add(int p,int w){while(p<=n)sum[p]+=w,p+=p&-p;}
	inline int query(int p){int s=0;while(p)s+=sum[p],p-=p&-p;return s;}
};
template<int T>struct BIT
{
	BIT1 a[T+10];
	int lim;
	inline void add(int x,int y,int w){while(x<=lim)a[x].add(y,w),x+=x&-x;}
	inline int query(int x,int y){int s=0;while(x)s+=a[x].query(y),x-=x&-x;return s;}
};
BIT<5000>A;
BIT<10000>B,C;
int main()
{
	scanf("%d %d",&n,&q);
	A.lim=n,B.lim=C.lim=2*n;
	int op,dir,x,y,len;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d %d %d %d",&dir,&x,&y,&len);
			if(dir==1)
			{
				A.add(x,y,1),A.add(x+len+1,y,-1);
				B.add(x+y+len+1,x,-1),B.add(x+y+len+1,x+len+1,1);
			}
			else if(dir==2)
			{
				A.add(x,y+1,-1),A.add(x+len+1,y+1,1);
				C.add(y-len-x+n,x,1),C.add(y-len-x+n,x+len+1,-1);
			}
			else if(dir==3)
			{
				A.add(x-len,y,1),A.add(x+1,y,-1);
				C.add(y+1-x+len+n,x-len,-1),C.add(y+1-x+len+n,x+1,1);
			}
			else
			{
				A.add(x-len,y+1,-1),A.add(x+1,y+1,1);
				B.add(x-len+y,x-len,1),B.add(x-len+y,x+1,-1);
			}
		}
		else scanf("%d %d",&x,&y),printf("%d\n",A.query(x,y)+B.query(x+y,x)+C.query(y-x+n,x));
	}
	return 0;
}