#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
bool vis[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(vis[i]) continue;
		ans++;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]%a[i]==0) vis[j]=1;
		}
	}
	cout<<ans<<endl;
}