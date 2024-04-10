#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,num[5],t=1e18;
char ch;
bool add[5],used[5];
long long dfs(long long dep)
{
	long long i,j,x,y;
	/*for (i=1;i<=4;i++) 
	{
		if (!used[i]) cerr<<num[i]<<' ';
	}
	cerr<<endl;*/
	if (dep==1) return num[1];
	for (i=1;i<=4;i++)
	{
		 for (j=i+1;j<=4;j++)
		 {
		 	if (i!=j&&!used[i]&&!used[j])
		 	{
		 		x=num[i];
		 		y=num[j];
		 		if (add[dep]) num[i]+=num[j];
		 		else num[i]*=num[j];
		 		used[j]=1;
		 		t=min(t,dfs(dep-1));
		 		num[i]=x;
		 		num[j]=y;
				used[j]=0; 
		 	}
		 }
	}
	return t;
} 
int main()
{
	for (i=1;i<=4;i++) cin>>num[i];
	for (i=4;i>1;i--)
	{
		cin>>ch;
		if (ch=='+') add[i]=1;
	}
	cout<<dfs(4);
	return 0;
}