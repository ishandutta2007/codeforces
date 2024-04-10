#include<bits/stdc++.h>
using namespace std;
int t[100005];
int pre[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+t[i];
	}
	int l=0,r=n+1;
	while(l<r-1)
	{
		if(pre[l]<=pre[n]-pre[r-1]) l++;
		else r--; 
	}
	printf("%d %d\n",l,n-l);
	return 0;
}