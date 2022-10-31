#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int bin[maxn];
int ans[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	memset(ans,0,sizeof(ans));
	memset(arr,0,sizeof(arr));
	memset(bin,0,sizeof(bin));
	int cur=1;
	for(int i=1,temp;i<=m;i++)
	{
		cin>>temp;
		arr[temp]++;
		bin[arr[temp]]++;
		if(bin[cur]==n)
		{
			ans[i]=1;
			cur++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
	}
	cout<<endl;
}