#include<bits/stdc++.h>
using namespace std;
int arr[200];
int main()
{
	int n;
	scanf("%d",&n);
	memset(arr,0,sizeof(arr));
	for(int i=0,temp;i<n;i++)
	{
		scanf("%d",&temp);
		arr[temp]++;
		arr[temp]%=2;
	}
	int ans=0;
	int pre=0;
	bool ok=0;
	for(int i=1;i<=100;i++)
	{
		if(arr[i]&&ok)
		{
			ans+=i-pre;
			ok=0;
		}
		else if(arr[i]) {ok=1;pre=i;}
	}
	printf("%d\n",ans);
}