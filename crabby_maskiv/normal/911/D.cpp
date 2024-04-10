#include<iostream>
using namespace std;
int a[1505];
int n,cnt;
int main()
{
	cin>>n;
	int i,j;
	for(i=0;i<n;i++) cin>>a[i];
	int m;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		    if(a[i]>a[j]) cnt++;
	}
	bool ans=cnt%2;
	cin>>m;
	for(i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		int x=r-l+1;
		if(((x-1)*x/2)%2==0) ans=ans;
		else ans=1-ans;
		if(ans==0) cout<<"even"<<endl;
		else cout<<"odd"<<endl;
	}
	return 0;
}