#include<cstdio>
const int Dx[5]={0,1,1,-1,-1},Dy[5]={0,1,-1,1,-1};
int n,c;char a[501][502];
int main()
{
	scanf("%d",&n);if(n<3)return 0*puts("0");
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=2;i<n;i++)
	for(int j=2;j<n;j++)
	for(int k=0;k<5;k++)
	if(a[i+Dx[k]][j+Dy[k]]!='X')
	{c--;break;}
	printf("%d",c+(n-2)*(n-2));
	return 0;
}