#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,a[27],m,i,j,f1[100005],f2[100005],Max;/////////////////////////////////
string st;
bool ch(int x,int y)
{
	int l=y-x+1,i;
	for (i=x;i<=y;i++)
	if (a[st[i]-96]<l) return 0;
	return 1;
} 
int main()
{
	cin>>n>>st;
	st=" "+st;
	for (i=1;i<=26;i++) cin>>a[i];
	f1[0]=1;
	for (i=1;i<=n;i++)
	{
		f2[i]=2147480000;
		for (j=1;j<=i;j++)
		{
		    if (ch(i-j+1,i))
		    {
	 	         f1[i]=(f1[i]+f1[i-j])%1000000007;
	 	         f2[i]=min(f2[i],f2[i-j]+1);
	 	         Max=max(Max,j);
        	}
    	}
    }
    cout<<f1[n]<<endl<<Max<<endl<<f2[n];
    return 0;
}