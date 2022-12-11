#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
	int x,y,z,id;
	friend bool operator < (point a,point b)
	{
		if(a.x!=b.x)return a.x<b.x;
		if(a.y!=b.y)return a.y<b.y;
		return a.z<b.z;
	}
}p[50050];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z),p[i].id=i;
	sort(p+1,p+1+n);
	int last1=0,last2=0;
	for(int i=1;i<=n;++i)
	{
		int r1=i;
		while(r1<n&&p[r1+1].x==p[i].x)++r1;
	//	printf("%d %d\n",i,r1);
		for(int j=i;j<=r1;++j)
		{
			int r2=j;
			while(r2<r1&&p[r2+1].y==p[j].y)++r2;
		//	printf("%d %d %d\n",j,r2,last2);
			for(int k=j;k+1<=r2;k+=2)printf("%d %d\n",p[k].id,p[k+1].id);
			if((r2-j+1)&1)
			{
				if(last2)printf("%d %d\n",p[r2].id,last2),last2=0;
				else last2=p[r2].id;
			}
			j=r2;
		}
		if(last2)
		{
			if(last1)
			{
				printf("%d %d\n",last1,last2);
				last1=0;last2=0;
			}
			else last1=last2,last2=0;
		}
		i=r1;
	}
	return 0;
}