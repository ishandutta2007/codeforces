#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n;
string A,B,C,D;
int main()
{
	cin>>A>>B;
	n=read();
	cout<<A<<" "<<B<<endl;
	for(int i=1;i<=n;++i)
	{
		cin>>C>>D;
		if(C==A)
			A=D;
		else
			B=D;
		cout<<A<<" "<<B<<endl;
	}
	return 0;
}