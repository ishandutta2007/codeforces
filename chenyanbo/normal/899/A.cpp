#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n, a,op[5];
int main()
{
	//memset  xiaoda daxia      deng //  //uoj
//	int n, a,op[5]; //0 ? //  a  ={0}   1 10 daxiao     wainei struct void  //0  0 0   4   //,} // ={}
	n=read();
	for(int i=1; i<=n ; ++i)
	{
		++op[read()];
	}
	if(op[2]>op[1])op[2]=op[1];
	printf("%d\n",op[2]+(op[1]-op[2])/3);//3. 3.0    //(oduble)
}