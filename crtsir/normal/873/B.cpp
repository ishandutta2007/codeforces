#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[200004];
int x=100001,n;
char c;
int main(){
	cin>>n;
	a[x].first=1;
	a[x].second=1;
	for(int i=2;i<=1+n;i++)
	{
		cin>>c;
		if(c=='1')x++;else x--;
		if(!a[x].first)a[x].first=i;
		a[x].second=i;
	}
	int ans=0;
	for(int i=0;i<200003;i++)
		ans=max(ans,a[i].second-a[i].first);
	cout<<ans;
}