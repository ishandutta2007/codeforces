#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
long long n,m,i,j,b[15],k,mi=2147480000,s,x,g=1;
string st,st1;
char c[10005];
bool zero(string st)
{
	if (st=="0") return 1;
	if (st[0]=='0') return 0;
	return 1;
}
int main()
{
	cin>>n>>k;
	for (i=1;i<=k;i++) g*=10;
	sprintf(c," %d",n);
	st=c;
	m=st.length()-1;
	//b[1]=b[2]=b[3]=1;
	while (b[0]==0)
	{
		st1="";
		for (j=m;j>=1&&b[j];j--);
		b[j]=1;
		for (i=j+1;i<=m;i++) b[i]=0;
		for (i=1;i<=m;i++)
		if (b[i]) st1+=st[i];
		sscanf(st1.c_str(),"%d",&x);
		if (x%g==0&&zero(st1)) 
		{
			s=m;
			for (i=1;i<=m;i++) s-=b[i];
			if (s<mi) mi=s;
		}
	}
	cout<<mi;
	return 0;
}