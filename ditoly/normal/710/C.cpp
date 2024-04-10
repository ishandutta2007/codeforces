#include<cstdio>
int n,p0,p1=-1;
void put0(){printf("%d ",p0+=2);}
void put1(){printf("%d ",p1+=2);}
void work(int k)
{
	int i;
	for(i=0;i<k;i++)put0();
	for(;i<n-k;i++)put1();
	for(;i<n;i++)put0();
	puts("");
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=n>>1;i;i--)work(i);
	for(;i<=(n>>1);i++)work(i);
}