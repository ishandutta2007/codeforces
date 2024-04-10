#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int a[100003];
int main()
{
	long long cnt=0,n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i],
		cnt+=a[i];
	if(cnt%k){
		cout<<"No";
		return 0;
	}
	cnt/=k;
	for(int i=0;i<n;i++)
	{
		long long cnt2=0,ans=0;
		for(;i<n;i++,ans++)
		{
			cnt2+=a[i];
			if(cnt2>cnt){
				cout<<"No";
				return 0;
			}
			if(cnt2==cnt){
				v.push_back(ans);
				break;
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<k;i++)cout<<v[i]+1<<' ';
}