#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int arr[105];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int ans=0;
	int cnt=-1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]==arr[i-1]+1)
		{
			if(arr[i-1]==1) cnt++;
			cnt++;
			if(arr[i]==1000) cnt++;
		}
		else cnt=-1;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;


}