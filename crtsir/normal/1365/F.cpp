#include<bits/stdc++.h>
using namespace std;
int n,a[200003],b[200003],T;
int main(){
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<pair<int,int> >v[2];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		for(int i=0;i<n/2;i++)
		{
			v[0].push_back(make_pair(max(a[i],a[n-1-i]),min(a[i],a[n-1-i])));
			v[1].push_back(make_pair(max(b[i],b[n-1-i]),min(b[i],b[n-1-i])));
		}
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end());
		if(v[0]!=v[1])
			cout<<"No";
		else
			if(n%2==1&&a[n/2]!=b[n/2])
				cout<<"No";
			else
				cout<<"Yes";
		cout<<endl;
	}
}