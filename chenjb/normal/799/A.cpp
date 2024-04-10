#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
int main()
{
	int n,t,k,d;
	cin>>n>>t>>k>>d;
	int ans1,ans2;
	ans1=n/k;
	if (n%k!=0)ans1++;
	ans1*=t;

	int count=0;
	int flag=0;
	for(int i=0;i<ans1;i++)
	{
		if (i>0&&(i%t==0))count+=k;
		if (i>d&&((i-d)%t==0))count+=k;
		if (count>=n)
			{
				flag=1;
				break;
			}
	}
	if (flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}