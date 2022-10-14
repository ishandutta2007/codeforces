#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,x=0,y=0,z=0;
		bool f=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) 
		{
			scanf("%d",&k);
			if(k==0) ++x,f=1; else if(k<0) y-=(k+1),z+=k; else z+=k,f=1; 
		}
		z+=x;
		if(z!=0) printf("%d\n",x);
		else if(f) printf("%d\n",x+1);
	}
	return 0;
}