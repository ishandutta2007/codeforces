#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int pr(int i)
{
	for(int j=2;j<i;j++)
		if(i%j==0)
			return 0;
	return 1;
}char s[10];
int main()
{
	int a=0;
	for(int i=2;i<=10;i++)
		if(pr(i))
		{
			cout<<i<<endl;
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='y')
				a=i;
		}
	if(a==0)
	{
		cout<<"prime\n";
		fflush(stdout);
		return 0;
	}
	for(int i=2;i*a<=100;i++)
		if(pr(i))
		{
			cout<<i*a<<endl;
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='y')
			{
				cout<<"composite\n";
				fflush(stdout);
				return 0;
			}
		}
	{
		cout<<"prime\n";
		fflush(stdout);
		return 0;
	}		
	
}