#include<cstdio>
#include<iostream>
using namespace std;
int n,a,b;
int c[105][105];
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin>>n>>a>>b;
	if(n>a*b){cout<<-1<<endl;return 0;}
	for(int i=1,k=0;i<=a;i++)
		for(int jj=1;jj<=b;jj++)
		{
			int j;
			if(i&1)j=jj;
			else j=b-jj+1;
			if(k<n)c[i][j]=++k;
			else break;
		}
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			printf("%d%c",c[i][j]," \n"[j==b]);
	return 0;
}