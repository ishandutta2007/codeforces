#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int a[101];
	while(cin>>n)
	{
		int ans=0,ans1=0,ans2=0;
		memset(a,0,sizeof(a)); 
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]; 
		}
		int mark1,mark2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			mark1=i;
			if(a[i]==n)
			mark2=i;
		}
	/*	if(mark>=(n/2))
		{
			ans=mark-1;
		}
		else ans=n-mark;
		*/
		ans1=max(mark1-1,n-mark1);
		ans2=max(mark2-1,n-mark2);
		ans=max(ans1,ans2);
		printf("%d\n",ans);
	}
	return 0;
}