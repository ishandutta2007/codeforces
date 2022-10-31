#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long arr[maxn];
string s;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	long long tot=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[i]*=2;
		tot+=arr[i];
	}
	cin>>s;
	long long W=0,G=0,flag=5;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='G') G+=arr[i];
		else if(s[i]=='W') W+=arr[i],flag=3;
		long long cur=arr[i],sta;
		sta=min(cur/2,W),tot+=sta*2,cur-=sta*2,W-=sta;
		sta=min(cur/2,G),tot+=sta*4,cur-=sta*2,G-=sta;
		tot+=flag*cur;
	}
	cout<<tot/2<<endl;


}