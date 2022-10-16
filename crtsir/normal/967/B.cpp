#include<bits/stdc++.h>
using namespace std;
int num[100001];
long long all;
int main()
{
	int n,a,b;
	cin>>n>>a>>b>>num[0];
	all=num[0];
	for(int i=1;i<n;i++)
		cin>>num[i],
		all+=num[i];
	sort(num+1,num+n);
	int js=n-1;
	if(a/all*num[0]>=b)
	{
		cout<<0;
		return 0;
	}
	while(a*num[0]<b*(all-num[js]))all-=num[js],js--;
	cout<<n-js;
}